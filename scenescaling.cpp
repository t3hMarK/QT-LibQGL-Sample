#include "scenescaling.h"

SceneScaling::SceneScaling(SceneNode *parentNode, float x, float y, float z) : SceneTransformation(parentNode) {
    setScalingFactorX(x);
    setScalingFactorY(y);
    setScalingFactorZ(z);
}

void SceneScaling::setScalingFactorX(float x) {
    _x = x;
}

void SceneScaling::setScalingFactorY(float y) {
    _y = y;
}

void SceneScaling::setScalingFactorZ(float z) {
    _z = z;
}

float SceneScaling::getScalingFactorX() {
    return _x;
}

float SceneScaling::getScalingFactorY() {
    return _y;
}

float SceneScaling::getScalingFactorZ() {
    return _z;
}

void SceneScaling::draw() {
    glPushMatrix();
    {
        glScalef(_x, _y, _z);
        for(unsigned int i = 0; i < getChildNodes().size(); i++) {
            getChildNodes().at(i)->draw();
        }
    }
    glPopMatrix();
}
