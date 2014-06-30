#include "sceneshape.h"

SceneShape::SceneShape(SceneNode* parentNode, int r, int g, int b) : SceneNode(parentNode) {
    setColor(r,g,b);
}

void SceneShape::setColor(float r, float g, float b) {
    _r = r/255.0f;
    _g = g/255.0f;
    _b = b/255.0f;
}

SceneColorRGB SceneShape::getColor() {
    SceneColorRGB colorStruct;
    colorStruct.r = _r;
    colorStruct.g = _g;
    colorStruct.b = _b;

    return colorStruct;
}
