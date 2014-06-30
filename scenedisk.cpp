#include "scenedisk.h"

SceneDisk::SceneDisk(SceneNode* parentNode, float innerRadius, float outerRadius, float slices, float stacks, int r, int g, int b) : SceneShape(parentNode, r, g, b) {
    //define sphere parameter
    setInnerRadius(innerRadius);
    setOuterRadius(outerRadius);
    setSlices(slices);
    setStacks(stacks);

    //create the glQuadric needed to make a glSphere, disabled texture by default
    _quadric = gluNewQuadric();
}

void SceneDisk::setInnerRadius(float innerRadius) {
    _innerRadius = innerRadius;
}

void SceneDisk::setOuterRadius(float outerRadius) {
    _outerRadius = outerRadius;
}

void SceneDisk::setSlices(float slices) {
    _slices = slices;
}

void SceneDisk::setStacks(float stacks) {
    _stacks = stacks;
}

float SceneDisk::getInnerRadius() {
    return _innerRadius;
}

float SceneDisk::getOuterRadius() {
    return _outerRadius;
}

float SceneDisk::getSlices() {
    return _slices;
}

float SceneDisk::getStack() {
    return _stacks;
}

void  SceneDisk::draw() {
    glPushMatrix();
    {
        //apply color
        glColor3f(getColor().r, getColor().g, getColor().b);

        //draw disk
        gluDisk(_quadric, _innerRadius, _outerRadius, _slices, _stacks);
    }
    glPopMatrix();
}
