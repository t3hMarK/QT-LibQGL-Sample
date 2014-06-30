#include "scenesphere.h"

SceneSphere::SceneSphere(SceneNode *parentNode, float radius, float slices, float stacks, unsigned int texture, int r, int g, int b) : SceneShape(parentNode, r, g, b) {
    //define sphere parameter
    setRadius(radius);
    setSlices(slices);
    setStacks(stacks);

    //define texture
    _texture = texture;

    //create the glQuadric needed to make a glSphere, disabled texture by default
    _quadric = gluNewQuadric();
    gluQuadricTexture(_quadric, GLU_TRUE);
}

void SceneSphere::setTexParameter(GLenum target, GLenum pname, GLuint params) {
    _target = target;
    _pname = pname;
    _params = params;
}

void SceneSphere::setRadius(float radius){
    _radius = radius;
}

void SceneSphere::setSlices(float slices) {
    _slices = slices;
}

void SceneSphere::setStacks(float stacks) {
    _stacks = stacks;
}

float SceneSphere::getRadius() {
    return _radius;
}

float SceneSphere::getSlices() {
    return _slices;
}

float SceneSphere::getStack() {
    return _stacks;
}

void SceneSphere::draw() {
    glPushMatrix();
    {
        glBindTexture(GL_TEXTURE_2D, _texture);
        glTexParameteri(GL_TEXTURE_2D,_pname,_params);
        gluSphere(_quadric,_radius,_slices,_stacks);
    }
    glPopMatrix();
}
