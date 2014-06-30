#include "scenecircle.h"

#include <math.h>

SceneCircle::SceneCircle(SceneNode *parentNode, float radius, int r, int g, int b) : SceneShape(parentNode, r, g, b) {
    _radius = radius;
    setColor(r,g,b);
}

void SceneCircle::draw(int id) {

    /*
     *  Code for this circle generation algorithm inspired from
     *
     *  URL: http://stackoverflow.com/questions/4197062/using-the-following-function-that-draws-a-filled-circle-in-opengl-how-do-i-make
     *  Jerry Coffin - StackOverflow,   Using the following function that draws a filled circle in opengl,
     *                                  how do I make it show at different coordinates of the window?,
     *
     *  Date: 16 novembre 2010,
     *  Consulté le: 30 septembre 2013
     */

    //draw outline if id matches
    if(getNodeId() == id) {
        /*
         * source for line stipple : http://fly.cc.fer.hr/~unreal/theredbook/chapter02.html
         */
        glLineStipple(4, 0xAAAA);
        glEnable(GL_LINE_STIPPLE);
        glLineWidth(3.0f);
        glBegin(GL_LINE_LOOP);
        {
            //assign color to shape
            if(getColor().r == 1 && getColor().g == 1 && getColor().b == 1){
                glColor3f(0, 1, 0);
            } else {
                glColor3f(1, 1, 1);
            }

            //define tempAngle and draw initial line
            double currentAngle = 0.0;
            glVertex2d(_radius * cos(currentAngle) , _radius * sin(currentAngle));

            //with every circlePoint draw a line of lenght radius at angle currentAngle then increment currentAngle
            for (unsigned int i=0; i < _circlePoints; i++) {
                glVertex2d(_radius * cos(currentAngle), _radius * sin(currentAngle));
                currentAngle += _angle;
            }
        }
        glEnd();
        glLineWidth(1.0f);
        glDisable(GL_LINE_STIPPLE);
    }

    glPushName(getNodeId());
    glBegin(GL_POLYGON);
    {
        //assign color to shape
        glColor3f(getColor().r, getColor().g, getColor().b);

        //define tempAngle and draw initial line
        double currentAngle = 0.0;
        glVertex2d(_radius * cos(currentAngle) , _radius * sin(currentAngle));

        //with every circlePoint draw a line of lenght radius at angle currentAngle then increment currentAngle
        for (unsigned int i=0; i < _circlePoints; i++) {
            glVertex2d(_radius * cos(currentAngle), _radius * sin(currentAngle));
            currentAngle += _angle;
        }
    }
    glEnd();
    glPopName();
}
