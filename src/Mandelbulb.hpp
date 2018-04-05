//
//  Mandelbulb.hpp
//  mandelbulb3d
//
//  Created by m0Rya on 2018/04/01.
//

#ifndef Mandelbulb_hpp
#define Mandelbulb_hpp

#include <stdio.h>
#include "ofMain.h"


class Mandelbulb{
public:
    
    //Mandelbulb();
    
    
    
    void calcMandelbulb();
    vector<ofVec3f> getPointCloud();
    vector<ofFloatColor> getColorCloud();
    void draw();
    
    
    void setResolution(int _resolution);
    void setIteration(int _iteration);
    void setNValue(int _nValue);
    void setSize(float _size);
    void setEmmisionValue(float _emmisionValue);
    
    
    void exportAsPly();
    
    
    
private:
    int resolution = 200;
    int iteration = 5;
    int nValue = 8;
    float size = 3.0;
    
    int emmisionValue = 5;
    
    
    vector<ofVec3f> point;
    vector<ofVec3f> cValue;
    vector<bool> result;
    vector<ofVec3f> mandel;

    
    
    vector<double> lenOfMan;
    
    vector<double> colorItr;
    vector<ofFloatColor> colorForMandel;
    
    
    
    
};


#endif /* Mandelbulb_hpp */
