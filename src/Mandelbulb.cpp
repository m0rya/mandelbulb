//
//  Mandelbulb.cpp
//  mandelbulb3d
//
//  Created by m0Rya on 2018/04/01.
//

#include "Mandelbulb.hpp"




void Mandelbulb::calcMandelbulb(){
    
    for(int i=0; i<resolution; i++){
        for(int j=0; j<resolution; j++){
            for(int k=0; k<resolution; k++){
                
                ofVec3f tmp = ofVec3f( float((i-resolution/2.0)/resolution) * size, float((j-resolution/2.0)/resolution) * size, float((k-resolution/2.0)/resolution)*size);
                
                point.push_back(tmp);
                cValue.push_back(tmp);
                result.push_back(true);
            }
        }
    }
    
    
    for(int i=0; i<iteration; i++){
        
        for(int a=0; a<resolution; a++){
            for(int b=0; b<resolution; b++){
                for(int c=0; c<resolution; c++){
                    
                    if(result[a*resolution*resolution + b*resolution +c] == true){
                        
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

    
}


void Mandelbulb::draw(){
    
    for(int i=0; i<mandel.size(); i++){
        ofDrawBox(mandel[i].x, mandel[i].y, mandel[i].z, 1, 1, 1);
    }
    
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
