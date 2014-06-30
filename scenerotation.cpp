#include "scenerotation.h"

SceneRotation::SceneRotation(SceneNode *parentNode, float angle, float x, float y, float z) : SceneTransformation(parentNode) {
    setAngle(angle);
    setRotationPoint(x,y,z);
}

void SceneRotation::setAngle(float angle) {

    if(angle < 0){
        _angle = angle + 360;

        //recursive call if angle still negative
        if (_angle < 0) {
            setAngle(_angle);
        }
    } else if (angle >= 360) {
        _angle = angle - 360;

        //recursive call if angle still > 360
        if (_angle >= 0) {
            setAngle(_angle);
        }
    } else {
        _angle = angle;
    }
}

void SceneRotation::setRotationPoint(float x, float y, float z) {
    _rotationPoint.x = x;
    _rotationPoint.y = y;
    _rotationPoint.z = z;
}

float SceneRotation::getAngle() {
    return _angle;
}

ScenePoint3D SceneRotation::getRotationPoint() {
    return _rotationPoint;
}

void SceneRotation::draw() {
    glPushMatrix();
    {
        glRotatef(_angle, _rotationPoint.x, _rotationPoint.y, _rotationPoint.z);
        for(unsigned int i = 0; i < getChildNodes().size(); i++) {
            getChildNodes().at(i)->draw();
        }
    }
    glPopMatrix();
}
