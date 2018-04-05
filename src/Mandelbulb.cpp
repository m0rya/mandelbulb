//
//  Mandelbulb.cpp
//  mandelbulb3d
//
//  Created by m0Rya on 2018/04/01.
//

#include "Mandelbulb.hpp"


Mandelbulb::Mandelbulb(){
    gui.setup();
    
    gui_recalc.addListener(this, &Mandelbulb::calcMandelbulb);
    
    gui.add(gui_recalc.setup("Recalc"));
    gui.add(gui_resol.setup("resolution", 200, 10, 500));
    gui.add(gui_itr.setup("iteration", 5, 1, 20));
    gui.add(gui_nValue.setup("nValue", 8, 1, 20));
    gui.add(gui_size.setup("size", 3.0, 1.0, 10.0));
    gui.add(gui_label.setup("pressing SPACE key export .ply", ""));
}

Mandelbulb::~Mandelbulb(){
    gui_recalc.removeListener(this, &Mandelbulb::calcMandelbulb);
}





void Mandelbulb::calcMandelbulb(){
    
    //from gui
    resolution = gui_resol;
    iteration = gui_itr;
    nValue = gui_nValue;
    size = gui_size;

    
    point.clear();
    result.clear();
    cValue.clear();
    
    mandel.clear();
    colorForMandel.clear();
    
    point.resize(resolution*resolution*resolution);
    result.resize(resolution*resolution*resolution);
    cValue.resize(resolution*resolution*resolution);

    for(int i=0; i<resolution; i++){
        for(int j=0; j<resolution; j++){
            for(int k=0; k<resolution; k++){
                
                ofVec3f tmp = ofVec3f( float((i-resolution/2.0)/resolution) * size, float((j-resolution/2.0)/resolution) * size, float((k-resolution/2.0)/resolution)*size);
                
                point[i*resolution*resolution + j*resolution + k] = tmp;
                result[i*resolution*resolution + j*resolution + k] = true;
         
            }
        }
    }
    
    cValue = point;
    
    
    
    for(int i=0; i<iteration; i++){
        
        for(int a=0; a<resolution; a++){
            for(int b=0; b<resolution; b++){
                for(int c=0; c<resolution; c++){
                    
                    if(result[a*resolution*resolution + b*resolution +c]){
                        
                        ofVec3f v = point[a*resolution*resolution + b*resolution +c];
                        
                        float r = v.length();
                        float phi = atan2(v.y, v.x);
                        float theta = atan2(sqrt(v.x*v.x + v.y*v.y), v.z);
                        
                        float vr = pow(r,nValue);
                        float vx = sin(nValue*theta) * cos(nValue*phi);
                        float vy = sin(nValue*theta) * sin(nValue*phi);
                        float vz = cos(nValue*theta);
                        
                        ofVec3f tmpResult = ofVec3f(vx, vy, vz) * vr + cValue[a*resolution*resolution + b*resolution +c];
                        
                        
                        if(tmpResult.length() > emmisionValue || isnan(tmpResult.length()) ){
                            result[a*resolution*resolution + b*resolution +c] = false;
                        }else{
                            point[a*resolution*resolution + b*resolution +c] = tmpResult;
                        }
                        
                        
                        
                    }
                    
                }
            }
        }
    }
    
    

    
    //六方を囲まれた
    for(int i=1; i<resolution-1; i++){
        for(int j=1; j<resolution-1; j++){
            for(int k=1; k<resolution-1; k++){
                
                
                if(result[i*resolution*resolution + j*resolution + k] == false){
                    continue;
                }
                
                int count = 0;
                
                if(result[i*resolution*resolution + j*resolution + k - resolution*resolution] == true) count ++;
                if(result[i*resolution*resolution + j*resolution + k + resolution*resolution] == true) count ++;
                if(result[i*resolution*resolution + j*resolution + k - resolution] == true) count ++;
                if(result[i*resolution*resolution + j*resolution + k + resolution] == true) count ++;
                if(result[i*resolution*resolution + j*resolution + k - 1] == true) count ++;
                if(result[i*resolution*resolution + j*resolution + k + 1] == true) count ++;
                
                if(count == 6){
                    continue;
                }else{
                    mandel.push_back(ofVec3f(i-resolution/2,k-resolution/2,j-resolution/2));
                    
                    ofColor tmpColor = ofColor::fromHsb(ofMap(ofVec3f(i-resolution/2,j-resolution/2,k-resolution/2).length(), 0.0, resolution/2, 0, 255), 255, 255);
                    
                    colorForMandel.push_back(ofFloatColor(ofMap(tmpColor.r, 0, 255, 0, 1.0), ofMap(tmpColor.g, 0, 255, 0, 1.0), ofMap(tmpColor.b, 0, 255, 0, 1.0)));
                    
                    
                    
                }
                
                
            }
        }
    }

    vox.voxelize(mandel, colorForMandel);


    
}


void Mandelbulb::draw(){
    /*
    for(int i=0; i<mandel.size(); i++){
        ofDrawBox(mandel[i].x, mandel[i].y, mandel[i].z, 1, 1, 1);
    }
     */
    vox.draw();
    
    
}

void Mandelbulb::setResolution(int _resolution){
    resolution = _resolution;
}

void Mandelbulb::setIteration(int _iteration){
    iteration = _iteration;
}

void Mandelbulb::setNValue(int _nValue){
    nValue = _nValue;
}

void Mandelbulb::setSize(float _size){
    size = _size;
}

void Mandelbulb::setEmmisionValue(float _emmisionValue){
    emmisionValue = _emmisionValue;
}


vector<ofVec3f> Mandelbulb::getPointCloud(){
    return mandel;
}

vector<ofFloatColor> Mandelbulb::getColorCloud(){
    return colorForMandel;
}

void Mandelbulb::drawGui(){
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    gui.draw();
    
}

void Mandelbulb::exportAsPly(string fileName){
    ofFile plyFile;
    
    plyFile.open(fileName, ofFile::WriteOnly);
    cout << mandel.size() << endl;
    
    string headerText = "ply\nformat ascii 1.0\ncomment File exported by m0rya's software\nelement vertex ";
    headerText += ofToString(mandel.size() * 8);
    headerText += "\nproperty float x\nproperty float y\nproperty float z\nproperty uchar red\nproperty uchar green\nproperty uchar blue\nelement face ";
    headerText += ofToString(mandel.size() * 6);
    headerText += "\nproperty list uchar uint vertex_index\nend_header\n";
    
    plyFile << headerText;
    
    
    for(int i=0; i<mandel.size(); i++){
        ofColor tc = ofColor(int(ofMap(colorForMandel[i].r,0.0,1.0, 0, 255)), int(ofMap(colorForMandel[i].g,0.0,1.0, 0, 255)), int(ofMap(colorForMandel[i].b,0.0,1.0, 0, 255)));
        
       
        
        plyFile << ofToString(mandel[i].x+0.5) << " " << ofToString(mandel[i].y+0.5) << " " << ofToString(mandel[i].z+0.5) << " " << to_string(tc.r) << " " << to_string(tc.g) << " " << to_string(tc.b) << "\n";
        
        plyFile << ofToString(mandel[i].x+0.5) << " " << ofToString(mandel[i].y+0.5) << " " << ofToString(mandel[i].z-0.5) << " " << to_string(tc.r) << " " << to_string(tc.g) << " " << to_string(tc.b) << "\n";
        
        plyFile << ofToString(mandel[i].x-0.5) << " " << ofToString(mandel[i].y+0.5) << " " << ofToString(mandel[i].z-0.5) << " " << to_string(tc.r) << " " << to_string(tc.g) << " " << to_string(tc.b) << "\n";
        
        plyFile << ofToString(mandel[i].x-0.5) << " " << ofToString(mandel[i].y+0.5) << " " << ofToString(mandel[i].z+0.5) << " " << to_string(tc.r) << " " << to_string(tc.g) << " " << to_string(tc.b) << "\n";
        
        plyFile << ofToString(mandel[i].x+0.5) << " " << ofToString(mandel[i].y-0.5) << " " << ofToString(mandel[i].z+0.5) << " " << to_string(tc.r) << " " << to_string(tc.g) << " " << to_string(tc.b) << "\n";
        
        plyFile << ofToString(mandel[i].x+0.5) << " " << ofToString(mandel[i].y-0.5) << " " << ofToString(mandel[i].z-0.5) << " " << to_string(tc.r) << " " << to_string(tc.g) << " " << to_string(tc.b) << "\n";
        
        plyFile << ofToString(mandel[i].x-0.5) << " " << ofToString(mandel[i].y-0.5) << " " << ofToString(mandel[i].z-0.5) << " " << to_string(tc.r) << " " << to_string(tc.g) << " " << to_string(tc.b) << "\n";
        
        plyFile << ofToString(mandel[i].x-0.5) << " " << ofToString(mandel[i].y-0.5) << " " << ofToString(mandel[i].z+0.5) << " " << to_string(tc.r) << " " << to_string(tc.g) << " " << to_string(tc.b) << "\n";
        
    }
    
    for(int i=0; i<mandel.size(); i++){
        plyFile << "4 " << ofToString(i*8 + 0) << " " << ofToString(i*8 + 1) << " " << ofToString(i*8 + 2) << " " << ofToString(i*8 + 3) << "\n";
        
        plyFile << "4 " << ofToString(i*8 + 3) << " " << ofToString(i*8 + 2) << " " << ofToString(i*8 + 6) << " " << ofToString(i*8 + 7) << "\n";
        
        plyFile << "4 " << ofToString(i*8 + 7) << " " << ofToString(i*8 + 6) << " " << ofToString(i*8 + 5) << " " << ofToString(i*8 + 4) << "\n";
        
        plyFile << "4 " << ofToString(i*8 + 4) << " " << ofToString(i*8 + 5) << " " << ofToString(i*8 + 1) << " " << ofToString(i*8 + 0) << "\n";
        
        
        plyFile << "4 " << ofToString(i*8 + 0) << " " << ofToString(i*8 + 3) << " " << ofToString(i*8 + 7) << " " << ofToString(i*8 + 4) << "\n";
        
        plyFile << "4 " << ofToString(i*8 + 5) << " " << ofToString(i*8 + 6) << " " << ofToString(i*8 + 2) << " " << ofToString(i*8 + 1) << "\n";
    }
    
    
    cout << fileName << " is exported safely\n";
    
 
}

