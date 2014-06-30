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

#include <simpleViewer.h>
#include <scenecontroller.h>
#include <ui_untitled.h>
#include <qapplication.h>
#include <qframe.h>
#include <QBoxLayout>
#include <QMessageBox>
#include <QSignalMapper>

#define GLUT_DISABLE_ATEXIT_HACK
#ifdef Q_OS_WIN32
#include "GL/glut.h"
#endif
#ifdef Q_OS_MAC
#include "GLUT/glut.h"
#endif

int main(int argc, char** argv)
{
  //Read command lines arguments.
  QApplication application(argc,argv);
  glutInit(&argc, argv);

  //intialize mainWindow
  QMainWindow* mainWindow = new QMainWindow;
  Ui_MainWindow form1;
  form1.setupUi(mainWindow);

  //Creation of the actiongroups
  QActionGroup actiongroupAffichageTexture(mainWindow);
  QActionGroup actiongroupAffichageEclairage(mainWindow);
  QAction optionTexture("Texture", &actiongroupAffichageTexture);
  QAction optionEclairage("Éclairage", &actiongroupAffichageEclairage);
  optionTexture.setCheckable(true);
  optionTexture.setChecked(true);
  optionEclairage.setCheckable(true);
  optionEclairage.setChecked(true);
  actiongroupAffichageTexture.setExclusive(false);
  actiongroupAffichageEclairage.setExclusive(false);

  QActionGroup actiongroupMnFilter(mainWindow);
  QAction optionMn1("Nearest Mipmap Nearest", &actiongroupMnFilter);
  optionMn1.setCheckable(true);
  QAction optionMn2("Linerar Mipmap Nearest", &actiongroupMnFilter);
  optionMn2.setCheckable(true);
  QAction optionMn3("Nearest Mipmap Linear", &actiongroupMnFilter);
  optionMn3.setCheckable(true);
  QAction optionMn4("Linear Mipmap Linear", &actiongroupMnFilter);
  optionMn4.setCheckable(true);
  QAction optionMn5("Nearest", &actiongroupMnFilter);
  optionMn5.setCheckable(true);
  QAction optionMn6("Linerar", &actiongroupMnFilter);
  optionMn6.setCheckable(true);

  QActionGroup actiongroupMagFilter(mainWindow);
  QAction optionMag1("Nearest", &actiongroupMagFilter);
  optionMag1.setCheckable(true);
  QAction optionMag2("Linear", &actiongroupMagFilter);
  optionMag2.setCheckable(true);

  //Creation of the different menus of the menu bar
  QMenu affichageMenu("Affichage", mainWindow);
  affichageMenu.addAction(&optionTexture);
  affichageMenu.addAction(&optionEclairage);

  QMenu filtrageMenu("Filtrage", mainWindow);
  QMenu magfilterMenu("Mag Filter");
  QMenu mnfilterMenu("Mn Filter");
  filtrageMenu.addMenu(&mnfilterMenu);
  filtrageMenu.addMenu(&magfilterMenu);
  magfilterMenu.addAction(&optionMag1);
  magfilterMenu.addAction(&optionMag2);
  mnfilterMenu.addAction(&optionMn1);
  mnfilterMenu.addAction(&optionMn2);
  mnfilterMenu.addAction(&optionMn3);
  mnfilterMenu.addAction(&optionMn4);
  mnfilterMenu.addAction(&optionMn5);
  mnfilterMenu.addAction(&optionMn6);

  mainWindow->menuBar()->addMenu(&affichageMenu);
  mainWindow->menuBar()->addMenu(&filtrageMenu);


  // Instantiate and layout the viewer.
  Viewer* v = new Viewer();
  QLayout* layout = new QHBoxLayout;
  layout->addWidget(v);
  form1.frame->setLayout(layout);
  form1.horizontalSlider->setValue(50);

  //instanciate SceneController
  SceneController* controller = new SceneController();

  //bind signal/slot between viewer and controller
  QObject::connect(v, SIGNAL(glContext_Created()),controller, SLOT(glContext_Created()));
  QObject::connect(v, SIGNAL(animationRefresh()),controller, SLOT(refreshScene()));
  QObject::connect(controller, SIGNAL(sceneChanged(SceneNode*)), v, SLOT(updateScene(SceneNode*)));

  //Bind actions to the menu options
  QObject::connect(&optionEclairage, SIGNAL(toggled(bool)), controller, SLOT(toggleLighting(bool)));
  QObject::connect(&optionTexture, SIGNAL(toggled(bool)), controller, SLOT(toggleTexture(bool)));
  QObject::connect(&optionMag1, SIGNAL(triggered()), controller, SLOT(triggerMagFilter1()));
  QObject::connect(&optionMag2, SIGNAL(triggered()), controller, SLOT(triggerMagFilter2()));
  QObject::connect(&optionMn1, SIGNAL(triggered()), controller, SLOT(triggerMnFilter1()));
  QObject::connect(&optionMn2, SIGNAL(triggered()), controller, SLOT(triggerMnFilter2()));
  QObject::connect(&optionMn3, SIGNAL(triggered()), controller, SLOT(triggerMnFilter3()));
  QObject::connect(&optionMn4, SIGNAL(triggered()), controller, SLOT(triggerMnFilter4()));
  QObject::connect(&optionMn5, SIGNAL(triggered()), controller, SLOT(triggerMnFilter5()));
  QObject::connect(&optionMn6, SIGNAL(triggered()), controller, SLOT(triggerMnFilter6()));

  //bind actions to the animation control controls
  QObject::connect(form1.pushBtn_Stop, SIGNAL(clicked()), v, SLOT(stopAnimation()));
  QObject::connect(form1.pushBtn_Start, SIGNAL(clicked()), v, SLOT(startAnimation()));
  QObject::connect(form1.horizontalSlider, SIGNAL(sliderMoved(int)), controller, SLOT(adjustSpeed(int)));
  mainWindow->show();

  //Set the background color of the Viewer
  QColor *backgroundColor = new QColor();
  v->setBackgroundColor(backgroundColor->black());

  // Run main loop.
  return application.exec();
}
