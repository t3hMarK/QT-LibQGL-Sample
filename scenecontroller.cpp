#include <scenecontroller.h>

SceneController::SceneController() {
    //create a new scene
    _scene = new Scene();

    //initialize animation variable
    _timeOrion = 0;
    _timeOrionDay = 0;
    _timeOrionSat = 0;
    _timePhoton = 0;
    _timePhotonDay = 0;
    _timeComet = 0;
    _timeLapse = 50;
}

void SceneController::loadTextures(){
    glEnable(GL_TEXTURE_2D);

    QImage orion = QImage("assets/orion_b.jpg");
    QImage photon = QImage("assets/photon_b.jpg");
    QImage satellite = QImage("assets/satellite_b.jpg");
    QImage soleil = QImage("assets/soleil_b.jpg");

    if (orion.isNull() || photon.isNull() || satellite.isNull() || soleil.isNull())
    {
        std::cout << "Impossible de charger toutes les textures à partir du répertoire " << QDir::current().path().toStdString() << std::endl;
        std::cout << "Lire le fichier readme.html" << std::endl;
    }
    else
    {
        QImage imageOrion = QGLWidget::convertToGLFormat(orion);
        glGenTextures(1, &_textureOrion);
        glBindTexture(GL_TEXTURE_2D, _textureOrion);
        gluBuild2DMipmaps(GL_TEXTURE_2D,     // texture to specify
                          GL_RGBA,           // internal texture storage format
                          imageOrion.width(),     // texture width
                          imageOrion.height(),    // texture height
                          GL_RGBA,           // pixel format
                          GL_UNSIGNED_BYTE,  // color component format
                          imageOrion.bits());     // pointer to texture image

        QImage imagePhoton = QGLWidget::convertToGLFormat(photon);
        glGenTextures(1, &_texturePhoton);
        glBindTexture(GL_TEXTURE_2D, _texturePhoton);
        gluBuild2DMipmaps(GL_TEXTURE_2D,     // texture to specify
                          GL_RGBA,           // internal texture storage format
                          imagePhoton.width(),     // texture width
                          imagePhoton.height(),    // texture height
                          GL_RGBA,           // pixel format
                          GL_UNSIGNED_BYTE,  // color component format
                          imagePhoton.bits());     // pointer to texture image

        QImage imageSatellite = QGLWidget::convertToGLFormat(satellite);
        glGenTextures(1, &_textureSatellite);
        glBindTexture(GL_TEXTURE_2D, _textureSatellite);
        gluBuild2DMipmaps(GL_TEXTURE_2D,     // texture to specify
                          GL_RGBA,           // internal texture storage format
                          imageSatellite.width(),     // texture width
                          imageSatellite.height(),    // texture height
                          GL_RGBA,           // pixel format
                          GL_UNSIGNED_BYTE,  // color component format
                          imageSatellite.bits());     // pointer to texture image

        QImage imageSoleil = QGLWidget::convertToGLFormat(soleil);
        glGenTextures(1, &_textureSoleil);
        glBindTexture(GL_TEXTURE_2D, _textureSoleil);
        gluBuild2DMipmaps(GL_TEXTURE_2D,     // texture to specify
                          GL_RGBA,           // internal texture storage format
                          imageSoleil.width(),     // texture width
                          imageSoleil.height(),    // texture height
                          GL_RGBA,           // pixel format
                          GL_UNSIGNED_BYTE,  // color component format
                          imageSoleil.bits());     // pointer to texture image
    }
}

void SceneController::createSolarSystem() {
    //instanciate sun
    _sphereSoleil = new SceneSphere(_scene->getParentNode(), 25,32,32, _textureSoleil,0,0,0);
    dynamic_cast<SceneTransformation*>(_scene->getParentNode())->addChildNode(_sphereSoleil);

    //instanciate orion translation
    _translOrion = new SceneTranslation(_scene->getParentNode(), 110,0,0);
    dynamic_cast<SceneTransformation*>(_scene->getParentNode())->addChildNode(_translOrion);

    //instanciate orion animation disk
    _diskOrion = new SceneDisk(_scene->getParentNode(), 109.75, 110.25, 32, 32, 255, 255, 255);
    dynamic_cast<SceneTransformation*>(_scene->getParentNode())->addChildNode(_diskOrion);

    //instance orion rotation
    _rotOrion = new SceneRotation(_translOrion, 0, 0, 0, 1);
    dynamic_cast<SceneTransformation*>(_translOrion)->addChildNode(_rotOrion);

    //instanciate orion
    _sphereOrion = new SceneSphere(_rotOrion, 10, 32, 32, _textureOrion, 0, 0, 0);
    dynamic_cast<SceneTransformation*>(_rotOrion)->addChildNode(_sphereOrion);

    //instanciate orion satellite translation
    _translOrionSatellite = new SceneTranslation(_translOrion, 60, 0, 0);
    dynamic_cast<SceneTransformation*>(_translOrion)->addChildNode(_translOrionSatellite);

    //instanciate orion animation disk
    _diskOrionSatellite = new SceneDisk(_translOrion, 59.75, 60.25, 32, 32, 255, 255, 255);
    dynamic_cast<SceneTransformation*>(_translOrion)->addChildNode(_diskOrionSatellite);

    //instanciate orion satellite
    _sphereSatellite = new SceneSphere(_translOrionSatellite, 3, 32, 32, _textureSatellite, 0, 0, 0);
    dynamic_cast<SceneTransformation*>(_translOrionSatellite)->addChildNode(_sphereSatellite);

    //instanciate photon translation
    _translPhoton = new SceneTranslation(_scene->getParentNode(), 210, 0, 0);
    dynamic_cast<SceneTransformation*>(_scene->getParentNode())->addChildNode(_translPhoton);

    //instanciate orion animation disk
    _diskPhoton = new SceneDisk(_scene->getParentNode(), 209.75, 210.25, 32, 32, 255, 255, 255);
    dynamic_cast<SceneTransformation*>(_scene->getParentNode())->addChildNode(_diskPhoton);

    //instance photon inclination rotation
    _rotInclPhoton = new SceneRotation(_translPhoton, -70, 0, 1, 0);
    dynamic_cast<SceneTransformation*>(_translPhoton)->addChildNode(_rotInclPhoton);

    //instance photon rotation
    _rotPhoton = new SceneRotation(_rotInclPhoton, 0, 0, 0, 1);
    dynamic_cast<SceneTransformation*>(_rotInclPhoton)->addChildNode(_rotPhoton);

    //instanciate photon
    _spherePhoton = new SceneSphere(_rotPhoton, 6, 32, 32, _texturePhoton, 0, 0, 0);
    dynamic_cast<SceneTransformation*>(_rotPhoton)->addChildNode(_spherePhoton);

    //instanciate comet translation
    _translComet = new SceneTranslation(_scene->getParentNode(), 350, 0, 0);
    dynamic_cast<SceneTransformation*>(_scene->getParentNode())->addChildNode(_translComet);

    //instanciate comet disk scaling 1x : 2y
    _scaleDiskComet = new SceneScaling(_scene->getParentNode(), 1,2,1);
    dynamic_cast<SceneTransformation*>(_scene->getParentNode())->addChildNode(_scaleDiskComet);

    //instanciate orion animation disk
    _diskComet = new SceneDisk(_scaleDiskComet, 349.75, 350.25, 32, 32, 255,255,255);
    dynamic_cast<SceneTransformation*>(_scaleDiskComet)->addChildNode(_diskComet);

    //instanciate comet
    _sphereComet = new SceneSphere(_translComet, 3, 32, 32, 0, 0, 0, 0);
    dynamic_cast<SceneTransformation*>(_translComet)->addChildNode(_sphereComet);

    //signal change to scene
    sceneChanged(_scene->getParentNode());
}

void SceneController::refreshScene() {
    //increment time variables
    _timeOrion      += _timeLapse;
    _timeOrionDay   += _timeLapse;
    _timeOrionSat   += _timeLapse;
    _timePhoton     += _timeLapse;
    _timePhotonDay  += _timeLapse;
    _timeComet      += _timeLapse;

     /*
     *  default,    1    :  3600000 tick for an orbit
     *  Orion,      50   :  72000   tick for an orbit
     *  Orion rot,  750  :  4800    tick for a day
     *  Orion sat,  2500 :  1440    tick for an orbit (around Orion)
     *  Photon,     100  :  36000   tick for an orbit
     *  Photon rot, 1000 :  3600    tick for a day
     *  Comet,      150  :  24000   tick for an orbit
     *
     *  translation are modified using this equation
     *  X = Sin(timeElapsed / time for an orbit) * distance from origin
     *  Y = Cos(timeElapsed / time for an orbit) * distance from origin
     *  Z = 0
     */

    float angle;

    //modify orion translation
    if(_timeOrion > 72000){
        _timeOrion = _timeOrion - 72000;
    }
    angle = (_timeOrion / 72000) * 360;
    _translOrion->setTranslation(sin(angle * PI / 180) * 110, cos(angle * PI / 180) * 110, 0);

    //modify orion rotation
    if(_timeOrionDay > 4800){
        _timeOrionDay = _timeOrionDay - 4800;
    }
    angle = (_timeOrionDay / 4800) * 360;
    _rotOrion->setAngle(angle);

    //modify orion satellite translation
    if(_timeOrionSat > 1440){
        _timeOrionSat = _timeOrionSat - 1440;
    }
    angle = (_timeOrionSat / 1440) * 360;
    _translOrionSatellite->setTranslation(sin(angle * PI / 180) * 60, cos(angle * PI / 180) * 60, 0);

    //modify photon translation
    if(_timePhoton > 36000){
        _timePhoton = _timePhoton - 36000;
    }
    //sincea angle is negative (counter clockwise rotation) we need to make sure the value is never below -360
    angle = -1.0d * ((_timePhoton / 36000) * 360);
    if(angle < -360){
        angle = angle + 360;
    }
    _translPhoton->setTranslation(sin(angle * PI / 180) * 210, cos(angle * PI / 180) * 210, 0);

    //modify photon rotation
    if(_timePhotonDay > 3600){
        _timePhotonDay = _timePhotonDay - 3600;
    }
    angle = ((_timePhotonDay / 3600) * 360) - 70; //-70 is the initial offset of Photon
    _rotPhoton->setAngle(angle);

    //modify comet translation
    if(_timeComet > 24000){
        _timeComet = _timeComet - 24000;
    }
    angle = (_timeComet / 24000) * 360;
    _translComet->setTranslation(sin(angle * PI / 180) * 350, (cos(angle * PI / 180) * 350) * 2, 0);
}

void SceneController::glContext_Created() {
    loadTextures();
    createSolarSystem();
}

void SceneController::toggleLighting(bool isActivated){
    if(isActivated){
        glEnable(GL_LIGHTING);
    }
    else
    {
        glDisable(GL_LIGHTING);
    }
}

void SceneController::toggleTexture(bool isActivated){
    if(isActivated){
        glEnable(GL_TEXTURE_2D);
    }
    else
    {
        glDisable(GL_TEXTURE_2D);
    }
}

void SceneController::triggerMagFilter1(){
    _sphereOrion->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    _spherePhoton->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    _sphereSatellite->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    _sphereSoleil->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    _sphereComet->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    //signal change to scene
    sceneChanged(_scene->getParentNode());
}

void SceneController::triggerMagFilter2(){
    _sphereOrion->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    _spherePhoton->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    _sphereSatellite->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    _sphereSoleil->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    _sphereComet->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //signal change to scene
    sceneChanged(_scene->getParentNode());
}

void SceneController::triggerMnFilter1(){
    _sphereOrion->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    _spherePhoton->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    _sphereSatellite->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    _sphereSoleil->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    _sphereComet->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

    //signal change to scene
    sceneChanged(_scene->getParentNode());
}

void SceneController::triggerMnFilter2(){
    _sphereOrion->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    _spherePhoton->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    _sphereSatellite->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    _sphereSoleil->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    _sphereComet->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

    //signal change to scene
    sceneChanged(_scene->getParentNode());
}

void SceneController::triggerMnFilter3(){
    _sphereOrion->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    _spherePhoton->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    _sphereSatellite->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    _sphereSoleil->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    _sphereComet->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);

    //signal change to scene
    sceneChanged(_scene->getParentNode());
}

void SceneController::triggerMnFilter4(){
    _sphereOrion->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    _spherePhoton->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    _sphereSatellite->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    _sphereSoleil->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    _sphereComet->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    //signal change to scene
    sceneChanged(_scene->getParentNode());
}

void SceneController::triggerMnFilter5(){
    _sphereOrion->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    _spherePhoton->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    _sphereSatellite->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    _sphereSoleil->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    _sphereComet->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    //signal change to scene
    sceneChanged(_scene->getParentNode());
}

void SceneController::triggerMnFilter6(){
    _sphereOrion->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    _spherePhoton->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    _sphereSatellite->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    _sphereSoleil->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    _sphereComet->setTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    //signal change to scene
    sceneChanged(_scene->getParentNode());;
}

void SceneController::adjustSpeed(int speed){
    //+1 so that the animation is never stopped by the slider.
    _timeLapse = speed + 1;
}

