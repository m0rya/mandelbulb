#include "ofApp.h"

const int resol = 250;
ofVec3f point[resol][resol][resol];
ofVec3f cValue[resol][resol][resol];
bool result[resol][resol][resol];
double lenOfMan[resol][resol][resol];


vector<ofVec3f> mandel;
vector<double> colorItr;
vector<ofColor> colorForMandel;

bool recording = false;
int startFrameNum = 0;
ofImage grabber;


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    ofEnableSmoothing();
    
    light.enable();
    light.setPointLight();
    light.setScale(100);
    light.setPosition(-100, 300, -100);
    
    light.setAmbientColor(ofFloatColor(0.5, 0.5, 0.5, 1.0));
    light.setDiffuseColor(ofFloatColor(0.5, 0.5, 1.0));
    light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    
    
    
    
    
    man.calcMandelbulb();
    voxelize.voxelize(man.getPointCloud(), man.getColorCloud());
     
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
  

}

//--------------------------------------------------------------
void ofApp::draw(){
    
   
    ofBackground(0);
    
    
    light.enable();
    
    cam.begin();
    
    /*
  
    if(recording){
        grabber.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        string numFrame = ofToString(ofGetFrameNum()-startFrameNum);
        while(numFrame.length() < 5){
            numFrame = "0" + numFrame;
        }
        
        string fileName = "mandel1/mandel_" + numFrame + ".tif";
        grabber.save(fileName);
    }
     */
    
    voxelize.draw();

    
    
    cam.end();
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == ' '){
        recording = true;
        startFrameNum = ofGetFrameNum();
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
