/*******************************************************************************************************************
 *  Description   : Class which represent the most abstract object in a scene,
 *  Author        : Marc Legault
 *  Creation Date : 09/21/2013
 *******************************************************************************************************************
 *  Author          Date        Description of change(s)
 *******************************************************************************************************************
 * Marc Legault     09/29/2013  Changed visibly of constructor to protected to guarantee instanciation by subclasses
 *                              Refactored GetParentNode to virtual getParentNode
 * Marc Legault     11/05/2013  Code cleanup
 *******************************************************************************************************************/

#ifndef SCENENODE_H
#define SCENENODE_H

#include <qgl.h>
#define GLUT_DISABLE_ATEXIT_HACK
#ifdef Q_OS_WIN32
#include <GL/glut.h>
#endif
#ifdef Q_OS_MAC
#include "GLUT/glut.h"
#endif

struct ScenePoint3D {
    float x,y,z;
};

struct SceneColorRGB {
    float r,g,b;
};

class SceneNode
{

    private :
        int _nodeId;
        SceneNode* _parentNode;

    protected :
        ///
        /// \brief SceneNode, create an instance of SceneNode with no parent Node
        ///
        SceneNode();

        ///
        /// \brief SceneNode, create an instance of SceneNode linked to a parentJe
        /// \param parentNode, parentNode of this new instance
        ///
        SceneNode(SceneNode* parentNode);

    public :
        ///
        /// \brief setNodeId, set nodeId
        /// \param id
        ///
        virtual void setNodeId(int id);

        ///
        /// \brief setParentNode, set SceneNode parent SceneNode
        /// \param parentNode
        ///
        virtual void setParentNode(SceneNode* parentNode);

        ///
        /// \brief getName, get the unique name of this SceneNode
        /// \return
        ///
        virtual int getNodeId();

        ///
        /// \brief GetParentNode, return parent SceneNode
        /// \return
        ///
        virtual SceneNode* getParentNode();

        ///
        /// \brief draw, pure virtual function draw to be implemented by subclasses
        ///
        virtual void draw() = 0;
};

#endif // SCENENODE_H
