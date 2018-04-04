//
//  Voxelize.cpp
//  mandelbulb3d
//
//  Created by m0Rya on 2018/04/05.
//

#include "Voxelize.hpp"

void Voxelize::voxelize(vector<ofVec3f> pointCloud){
    numVerts = pointCloud.size() * 24;
    
    ofVec3f *tmpP;
    ofVec3f *normal;
    tmpP = new ofVec3f[numVerts];
    normal = new ofVec3f[numVerts];
    
    for(int i=0; i<pointCloud.size(); i++){
        
        tmpP[i*24 + 0] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 1] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 2] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 3] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        
        normal[i*24 + 0] = ofVec3f(-1, 0, 0);
        normal[i*24 + 1] = ofVec3f(-1, 0, 0);
        normal[i*24 + 2] = ofVec3f(-1, 0, 0);
        normal[i*24 + 3] = ofVec3f(-1, 0, 0);
        
        
        tmpP[i*24 + 4] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 5] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 6] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 7] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        
        normal[i*24 + 4] = ofVec3f(0, 0, -1);
        normal[i*24 + 5] = ofVec3f(0, 0, -1);
        normal[i*24 + 6] = ofVec3f(0, 0, -1);
        normal[i*24 + 7] = ofVec3f(0, 0, -1);
        
        
        tmpP[i*24 + 8] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 9] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 10] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 11] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        
        normal[i*24 + 8] = ofVec3f(1, 0, 0);
        normal[i*24 + 9] = ofVec3f(1, 0, 0);
        normal[i*24 + 10] = ofVec3f(1, 0, 0);
        normal[i*24 + 11] = ofVec3f(1, 0, 0);
        
        tmpP[i*24 + 12] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 13] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 14] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 15] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        
        normal[i*24 + 12] = ofVec3f(0, 0, 1);
        normal[i*24 + 13] = ofVec3f(0, 0, 1);
        normal[i*24 + 14] = ofVec3f(0, 0, 1);
        normal[i*24 + 15] = ofVec3f(0, 0, 1);
        
        
        tmpP[i*24 + 16] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 17] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 18] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 19] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        
        normal[i*24 + 16] = ofVec3f(0, 1, 0);
        normal[i*24 + 17] = ofVec3f(0, 1, 0);
        normal[i*24 + 18] = ofVec3f(0, 1, 0);
        normal[i*24 + 19] = ofVec3f(0, 1, 0);
        
        tmpP[i*24 + 20] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 21] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 22] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 23] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        
        normal[i*24 + 20] = ofVec3f(0, -1, 0);
        normal[i*24 + 21] = ofVec3f(0, -1, 0);
        normal[i*24 + 22] = ofVec3f(0, -1, 0);
        normal[i*24 + 23] = ofVec3f(0, -1, 0);

        
        
        
    }
    
    myVbo.setVertexData(tmpP, numVerts, GL_DYNAMIC_DRAW);
    myVbo.setNormalData(normal, numVerts, GL_DYNAMIC_DRAW);
    
    
    
    delete[] tmpP;
    delete[] normal;
}

void Voxelize::voxelize(vector<ofVec3f> pointCloud, vector<ofFloatColor> colorCloud){
    numVerts = pointCloud.size() * 24;
    
    ofVec3f *tmpP;
    ofVec3f *normal;
    ofFloatColor *colors;
    tmpP = new ofVec3f[numVerts];
    normal = new ofVec3f[numVerts];
    colors = new ofFloatColor[numVerts];
    
    for(int i=0; i<pointCloud.size(); i++){
        
        tmpP[i*24 + 0] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 1] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 2] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 3] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        
        normal[i*24 + 0] = ofVec3f(-1, 0, 0);
        normal[i*24 + 1] = ofVec3f(-1, 0, 0);
        normal[i*24 + 2] = ofVec3f(-1, 0, 0);
        normal[i*24 + 3] = ofVec3f(-1, 0, 0);
        
        
        tmpP[i*24 + 4] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 5] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 6] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 7] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        
        normal[i*24 + 4] = ofVec3f(0, 0, -1);
        normal[i*24 + 5] = ofVec3f(0, 0, -1);
        normal[i*24 + 6] = ofVec3f(0, 0, -1);
        normal[i*24 + 7] = ofVec3f(0, 0, -1);
        
        
        tmpP[i*24 + 8] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 9] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 10] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 11] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        
        normal[i*24 + 8] = ofVec3f(1, 0, 0);
        normal[i*24 + 9] = ofVec3f(1, 0, 0);
        normal[i*24 + 10] = ofVec3f(1, 0, 0);
        normal[i*24 + 11] = ofVec3f(1, 0, 0);
        
        tmpP[i*24 + 12] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 13] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 14] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 15] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        
        normal[i*24 + 12] = ofVec3f(0, 0, 1);
        normal[i*24 + 13] = ofVec3f(0, 0, 1);
        normal[i*24 + 14] = ofVec3f(0, 0, 1);
        normal[i*24 + 15] = ofVec3f(0, 0, 1);
        
        
        tmpP[i*24 + 16] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 17] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 18] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 19] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y + voxelSize.y, pointCloud[i].z - voxelSize.z);
        
        normal[i*24 + 16] = ofVec3f(0, 1, 0);
        normal[i*24 + 17] = ofVec3f(0, 1, 0);
        normal[i*24 + 18] = ofVec3f(0, 1, 0);
        normal[i*24 + 19] = ofVec3f(0, 1, 0);
        
        tmpP[i*24 + 20] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        tmpP[i*24 + 21] = ofVec3f(pointCloud[i].x - voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 22] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z + voxelSize.z);
        tmpP[i*24 + 23] = ofVec3f(pointCloud[i].x + voxelSize.x, pointCloud[i].y - voxelSize.y, pointCloud[i].z - voxelSize.z);
        
        normal[i*24 + 20] = ofVec3f(0, -1, 0);
        normal[i*24 + 21] = ofVec3f(0, -1, 0);
        normal[i*24 + 22] = ofVec3f(0, -1, 0);
        normal[i*24 + 23] = ofVec3f(0, -1, 0);
        
        for(int j=0; j<24; j++){
            colors[i*24 + j] = colorCloud[i];
        }
        
        
        
        
    }
    
    myVbo.setVertexData(tmpP, numVerts, GL_DYNAMIC_DRAW);
    myVbo.setNormalData(normal, numVerts, GL_DYNAMIC_DRAW);
    myVbo.setColorData(colors, numVerts, GL_DYNAMIC_DRAW);
    
    
    
    delete[] tmpP;
    delete[] normal;
    delete[] colors;
}


void Voxelize::draw(){
    myVbo.draw(GL_QUADS, 0, numVerts);
    
}
