#include "ofApp.h"




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
    
    

    //cout << ofGetElapsedTimeMillis() << endl;
    man.calcMandelbulb();
    //cout << ofGetElapsedTimeMillis() << endl;
    voxelize.voxelize(man.getPointCloud(), man.getColorCloud());
    

    //man.exportAsPly();
     
    
    
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
