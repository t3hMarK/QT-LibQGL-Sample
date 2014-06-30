#include "scenepolygon.h"

ScenePolygon::ScenePolygon(SceneNode *parentNode, float x, float y, float z, int r, int g, int b) : SceneShape(parentNode, r, g, b) {
    //define initial point
    _shapePoints = std::vector<ScenePoint3D>();
    addPoint(x,y,z);
}

void ScenePolygon::addPoint(float x, float y, float z) {
    //make sure shapePoints list is instanciated
    if(&_shapePoints){

        //define initial point
        ScenePoint3D point;
        point.x = x;
        point.y = y;
        point.z = z;

        //add point at the back of the list
        _shapePoints.push_back(point);
    }
}

std::vector<ScenePoint3D> ScenePolygon::getShapePoints(){
    return _shapePoints;
}

void ScenePolygon::draw(int id) {

    //make sure shapePoints list is instanciated
    if(&_shapePoints != 0){

        //draw outline if id matches
        if(getNodeId() == id) {

             //source for line stipple : http://fly.cc.fer.hr/~unreal/theredbook/chapter02.html

            glLineStipple(4, 0xAAAA);
            glEnable(GL_LINE_STIPPLE);
            glLineWidth(3.0f);
            glBegin(GL_LINE_LOOP);
            {
                //assign color to shape
                if(getColor().r == 1 && getColor().g == 1 && getColor().b == 1){
                    glColor3f(1, 0, 0);
                } else {
                    glColor3f(1, 1, 1);
                }

                //define point as glVertex one by one
                for(unsigned int i = 0; i < _shapePoints.size(); i++) {
                    glVertex3f(_shapePoints.at(i).x, _shapePoints.at(i).y, _shapePoints.at(i).z);
                }
            }
            glEnd();
            glLineWidth(1.0f);
            glDisable(GL_LINE_STIPPLE);
        }

        //draw shape
        glPushName(getNodeId());
        glBegin(GL_POLYGON);
        {
            //assign color to shape
            glColor3f(getColor().r, getColor().g, getColor().b);

            //define point as glVertex one by one
            for(unsigned int i = 0; i < _shapePoints.size(); i++) {
                glVertex3f(_shapePoints.at(i).x, _shapePoints.at(i).y, _shapePoints.at(i).z);
            }
        }
        glEnd();
        glPopName();
    }
}
