//
//  Voxelize.hpp
//  mandelbulb3d
//
//  Created by m0Rya on 2018/04/05.
//

#ifndef Voxelize_hpp
#define Voxelize_hpp

#include <stdio.h>
#include <ofMain.h>

class Voxelize{
    
private:
    ofVbo myVbo;
    ofVec3f voxelSize = ofVec3f(1.0, 1.0, 1.0);
    int numVerts = 0;
    
public:
    
    void voxelize(vector<ofVec3f> pointCloud);
    void voxelize(vector<ofVec3f> pointCloud, vector<ofFloatColor> colorColoud);
    void draw();
    
};

#endif /* Voxelize_hpp */
