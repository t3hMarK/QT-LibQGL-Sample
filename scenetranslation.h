/***********************************************************************************************
 *  Description   : Class that defines a transformation to a number of SceneNode
 *  Author        : Marc Legault
 *  Creation Date : 10/23/2013
 ***********************************************************************************************
 *  Author          Date        Description of change(s)
 ***********************************************************************************************
 *  Marc Legault    10/23/2013  Added this header and refactored class to support 3D translation
 *  Marc Legault    11/05/2013  Code cleanup
 ***********************************************************************************************/

#ifndef SCENETRANSLATION_H
#define SCENETRANSLATION_H

#include <scenenode.h>
#include <scenetransformation.h>

class SceneTranslation : public SceneTransformation
{
    private :
        ScenePoint3D _translation;

    public :
        ///
        /// \brief SceneTranslation, Create a new instance of SceneTranslation without a link to an existing scene, only use is to create a root SceneNode
        ///
        SceneTranslation();

        ///
        /// \brief SceneTranslation, Create a new instance of SceneTranslation with a link to an existing scene
        /// \param parentNode, parentNode of transformation
        /// \param x, X coordinate of the translation
        /// \param y, Y coordinate of the translation
        /// \param z, Z coordinate of the translation
        ///
        SceneTranslation(SceneNode* parentNode, float x, float y, float z);

        ///
        /// \brief setTranslation, Set translation applied to childNodes
        /// \param x, X coordinate of the translation
        /// \param y, Y coordinate of the translation
        /// \param z, Z coordinate of the translation
        ///
        virtual void setTranslation(float x, float y, float z);

        ///
        /// \brief getTranslation, get a translation coordinates applied to childNodes
        /// \return translation coordinates in a ScenePoint3D structure
        ///
        virtual ScenePoint3D getTranslation();

        ///
        /// \brief draw, encapsulate child node inside an opengl Push/Pop matrix where the translation is applied
        /// \param id, id of the selected shape
        ///
        virtual void draw();
};

#endif // SCENETRANSLATION_H
