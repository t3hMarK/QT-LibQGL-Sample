/****************************************************************************

 Copyright (C) 2002-2008 Gilles Debunne. All rights reserved.

 This file is part of the QGLViewer library version 2.3.6.

 http://www.libqglviewer.com - contact@libqglviewer.com

 This file may be used under the terms of the GNU General Public License 
 versions 2.0 or 3.0 as published by the Free Software Foundation and
 appearing in the LICENSE file included in the packaging of this file.
 In addition, as a special exception, Gilles Debunne gives you certain 
 additional rights, described in the file GPL_EXCEPTION in this package.

 libQGLViewer uses dual licensing. Commercial/proprietary software must
 purchase a libQGLViewer Commercial License.

 This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/

#include "simpleViewer.h"

#define GLUT_DISABLE_ATEXIT_HACK
#ifdef Q_OS_WIN32
#include <GL/glut.h>
#endif
#ifdef Q_OS_MAC
#include "GLUT/glut.h"
#endif

void Viewer::init(){
    //define axis and grid
    setAxisIsDrawn(false);
    setGridIsDrawn(false);

    //define scene
    setAnimationPeriod(16); //refresh every 16 ms (60+ refresh per seconds)
    setSceneRadius(700);
    showEntireScene();

    // Create lignts
    glEnable(GL_LIGHTING);

    //signal that the glContext has been created and start animating the scene
    glContext_Created();
    startAnimation();
}

void Viewer::animate() {
    //request an animation refresh
    animationRefresh();
}

void Viewer::draw(){
    //enable light1 only
    glDisable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    //light1 parameters, white positional light with quadratic attenuation of 0.05 (1 / 0.05^2)
    const float light_attenuation = 0.05;
    const GLfloat light_ambient[4]  = {255.0, 255.0, 255.0, 1.0};
    const GLfloat light_specular[4] = {255.0, 255.0, 255.0, 1.0};
    const GLfloat light_diffuse[4]  = {255.0, 255.0, 255.0, 1.0};
    GLfloat position[] = { 0, 0, 0, 1 };

    //define light1
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, light_attenuation);
    glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, position);

    //draw scene
    if(_sceneNode) {
        _sceneNode->draw();
    }
}

void Viewer::updateScene(SceneNode* scene){
    //update _sceneNode if needed
    if(scene && _sceneNode != scene){
        _sceneNode = scene;
    }

    //redraw scene
    updateGL();
}
