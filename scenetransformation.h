/***********************************************************************************************
 *  Description   : Class that defines a transformation to a number of SceneNode
 *  Author        : Marc Legault
 *  Creation Date : 09/21/2013
 ***********************************************************************************************
 *  Author          Date        Description of change(s)
 ***********************************************************************************************
 *  Marc Legault    09/29/2013  Refactored addChildNode, getChildNodes into virtual functions
 *                              Constructor are now protected since class has become abstract
 *  Marc Legault    10/03/2013  Added removeChildNode and swapChildNode functions
 *  Marc Legault    11/05/2013  Code cleanup
 ***********************************************************************************************/

#ifndef SCENETRANSFORMATION_H
#define SCENETRANSFORMATION_H

#include <vector>
#include <scenenode.h>

class SceneTransformation : public SceneNode
{

    private :
        std::vector<SceneNode*> _childNodes;   //list of childNode pointer

    protected :
        ///
        /// \brief SceneTransformation, Create a new instance of SceneTransformation without a link to an existing scene
        ///
        SceneTransformation();

        ///
        /// \brief SceneTransformation, Create a new instance of SceneTransformation with a link to an existing scene
        /// \param parentNode, parentNode of transformation
        ///
        SceneTransformation(SceneNode* parentNode);

    public :

        ///
        /// \brief addChildNode, add child node to the list
        /// \param childNode
        ///
        virtual void addChildNode(SceneNode* childNode);

        ///
        /// \brief removeChildNode, remove child node from list
        /// \param childNode
        ///
        virtual void removeChildNode(SceneNode* childNode);

        ///
        /// \brief swapChildNode, remove old child node and replace it by a new child node
        /// \param oldChildNode, child node to remove
        /// \param newChildNode, new child node
        ///
        virtual void swapChildNode(SceneNode* oldChildNode, SceneNode* newChildNode);

        ///
        /// \brief getChildNodes return a vector of child SceneNodes
        /// \return
        ///
        virtual std::vector<SceneNode*> getChildNodes();

        ///
        /// \brief draw, pure virtual function draw to be implemented by subclasses
        ///
        virtual void draw() = 0;
};

#endif // SCENETRANSFORMATION_H
