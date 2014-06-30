/***********************************************************************************************
 *  Description   : GRASP controller class, used as a link between view and model,
 *                  Singleton pattern since only one instance is needed
 *  Author        : Marc Legault
 *  Creation Date : 09/21/2013
 ***********************************************************************************************
 *  Author          Date        Description of change(s)
 ***********************************************************************************************
 *  Marc Legault    09/29/2013  Added 3 new slots (create Rectangle, Circle and Text)
 *                              Removed setColor for the moment will be added at a later date
 *                              Added attach/detach function for observer/subject interaction
 *  Marc Legault    11/05/2013  Removed observer/subject pattern and replaced with signal slot
 *                              and code cleanup
 ***********************************************************************************************/

#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H

#include <QDir>
#include <QObject>
#include <ui_untitled.h>
#include <math.h>
#include <iostream>

#include <scene.h>
#include <scenetransformation.h>
#include <scenetranslation.h>
#include <scenerotation.h>
#include <scenescaling.h>
#include <scenesphere.h>
#include <scenedisk.h>

#define GLUT_DISABLE_ATEXIT_HACK
#ifdef Q_OS_WIN32
#include <GL/glut.h>
#endif
#ifdef Q_OS_MAC
#include "GLUT/glut.h"
#endif

#define PI 3.14159265 //pre-processor value for PI since Math.h uses radian values

class SceneController : public QObject
{
    Q_OBJECT

    private :
        Scene* _scene;  //pointer to scene instanciated by sceneController

        //textures
        GLuint _textureOrion;
        GLuint _texturePhoton;
        GLuint _textureSatellite;
        GLuint _textureSoleil;

        //scene variables
        SceneSphere* _sphereOrion;
        SceneSphere* _spherePhoton;
        SceneSphere* _sphereSatellite;
        SceneSphere* _sphereSoleil;
        SceneSphere* _sphereComet;
        SceneDisk* _diskOrion;
        SceneDisk* _diskOrionSatellite;
        SceneDisk* _diskPhoton;
        SceneDisk* _diskComet;
        SceneTranslation* _translOrion;
        SceneTranslation* _translOrionSatellite;
        SceneTranslation* _translPhoton;
        SceneTranslation* _translComet;
        SceneRotation* _rotOrion;
        SceneRotation* _rotInclPhoton;
        SceneRotation* _rotPhoton;
        SceneScaling* _scaleDiskComet;

        //animation variable
        double _timeOrion;
        double _timeOrionDay;
        double _timeOrionSat;
        double _timePhoton;
        double _timePhotonDay;
        double _timeComet;
        unsigned int _timeLapse;

        ///
        /// \brief loadTextures
        ///
        virtual void loadTextures();

        ///
        /// \brief createSolarSystem, create a solar system scene
        ///
        virtual void createSolarSystem();

    public :
        ///
        /// \brief SceneController, create an instance of SceneController
        ///
        SceneController();

    signals :
        void sceneChanged(SceneNode* scene);

    public slots :

        ///
        /// \brief refreshScene, refresh solar system
        /// \param timeLapse, the time elapsed between consecutive calls of this functions
        ///
        virtual void refreshScene();

        ///
        /// \brief glContext_Created, create scene once signal is received
        ///
        virtual void glContext_Created();

        ///
        /// \brief toggleLighting, Switches between Lighting activated on and off base on the Eclairage ActionGroup checked value
        /// \param isActivated, True if the ActionGroup Eclairage is checked, else false.
        ///
        virtual void toggleLighting(bool isActivated);

        ///
        /// \brief toggleTexture, Switched between Texture activated on and off based on the Texture ActionGroup checked value
        /// \param isActivated, True if the ActionGroup Texture is checked, else false.
        ///
        virtual void toggleTexture(bool isActivated);

        ///
        /// \brief Activates the Mag(close to) filter GL_NEAREST on all planets
        ///
        virtual void triggerMagFilter1();

        ///
        /// \brief Activates the Mag(close to) filter GL_LINEAR on all planets
        ///
        virtual void triggerMagFilter2();

        ///
        /// \brief Activates the Min(far away) filter GL_NEAREST_MIPMAP_NEAREST on all planets
        ///
        virtual void triggerMnFilter1();

        ///
        /// \brief Activates the Min(far away) filter GL_LINEAR_MIPMAP_NEAREST on all planets
        ///
        virtual void triggerMnFilter2();

        ///
        /// \brief Activates the Min(far away) filter GL_NEAREST_MIPMAP_LINEAR on all planets
        ///
        virtual void triggerMnFilter3();

        ///
        /// \brief Activates the Min(far away) filter GL_LINEAR_MIPMAP_LINEAR on all planets
        ///
        virtual void triggerMnFilter4();

        ///
        /// \brief Activates the Min(far away) filter GL_NEAREST on all planets
        ///
        virtual void triggerMnFilter5();

        ///
        /// \brief Activates the Min(far away) filter GL_LINEAR on all planets
        ///
        virtual void triggerMnFilter6();

        ///
        /// \brief Adjust the speed of the animation the of solar system.
        /// \param The animation speed.
        ///
        virtual void adjustSpeed(int speed);
};

#endif // SCENECONTROLLER_H
