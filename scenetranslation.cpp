#include "scenetranslation.h"

SceneTranslation::SceneTranslation() {
    _translation.x = 0;
    _translation.y = 0;
}

SceneTranslation::SceneTranslation(SceneNode *parentNode, float x, float y, float z) : SceneTransformation(parentNode) {
    setTranslation(x,y,z);
}

void SceneTranslation::setTranslation(float x, float y, float z) {
    _translation.x = x;
    _translation.y = y;
    _translation.z = z;
}

ScenePoint3D SceneTranslation::getTranslation(){
    return _translation;
}

void SceneTranslation::draw(){
    glPushMatrix();
    {
        glTranslatef(_translation.x, _translation.y, _translation.z);
        for(unsigned int i = 0; i < getChildNodes().size(); i++) {
            getChildNodes().at(i)->draw();
        }
    }
    glPopMatrix();
}
