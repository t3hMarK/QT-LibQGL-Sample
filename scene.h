/*****************************************************************************************************************
 *  Description   : Class whose purpose is to manage a scene, inherits subject in order to be observed
 *  Author        : Marc Legault
 *  Creation Date : 09/24/2013
 *****************************************************************************************************************
 *  Author          Date        Description of change(s)
 *****************************************************************************************************************
 *  Marc Legault    10/03/2013  Added getNode function which will return nodes corresponding to the passed nodeId
 *  Marc Legault    10/23/2013  Added missing function documentation
 *  Marc Legault    11/05/2013  Removed observer/subject pattern and replaced with signal slot
 *  Marc Legault    11/05/2013  Added missing documentation
 *****************************************************************************************************************/

#ifndef SCENE_H
#define SCENE_H

#include <scenenode.h>
#include <scenetransformation.h>

class Scene
{
    private :
        SceneNode* _parentNode;
        virtual SceneNode* findNode(SceneTransformation* transformNode, int nodeId);

    public :
        ///
        /// \brief Scene, Create a new instance of scene
        ///
        Scene();

        ///
        /// \brief getParentNode, return parent SceneNode
        /// \return
        ///
        virtual SceneNode* getParentNode();

        ///
        /// \brief getNode, return a specific node
        /// \param nodeId, id of node to find
        /// \return SceneNode with passed nodeId
        ///
        virtual SceneNode* getNode(int nodeId);
};

#endif // SCENE_H
