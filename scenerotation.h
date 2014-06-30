/***********************************************************************************************
 *  Description   : Class that defines a rotation to a number of child SceneNode
 *  Author        : Marc Legault
 *  Creation Date : 10/27/2013
 ***********************************************************************************************
 *  Author          Date        Description of change(s)
 ***********************************************************************************************
 *  Marc Legault    11/05/2013  Code cleanup
 ***********************************************************************************************/

#ifndef SCENEROTATION_H
#define SCENEROTATION_H

#include <scenetransformation.h>

class SceneRotation : public SceneTransformation
{
    private :
        float _angle;                   //angle of rotation in degree
        ScenePoint3D _rotationPoint;    //point around which the rotation is performed

    public :
        ///
        /// \brief SceneRotation, Create a new SceneRotation
        /// \param parentNode, parent SceneNode of rotation
        /// \param angle, angle of rotation in degree
        /// \param x, X coordinate the point around which the rotation is performed
        /// \param y, Y coordinate the point around which the rotation is performed
        /// \param z, Z coordinate the point around which the rotation is performed
        ///
        SceneRotation(SceneNode* parentNode, float angle, float x, float y, float z);

        ///
        /// \brief setAngle, Set the angle of rotation in degree
        /// \param angle, angle of rotation (0 to 360)
        ///
        virtual void setAngle(float angle);

        ///
        /// \brief setRotationPoint, Set the point around which the rotation is performed
        /// \param x, X coordinate the point around which the rotation is performed
        /// \param y, Y coordinate the point around which the rotation is performed
        /// \param z, Z coordinate the point around which the rotation is performed
        ///
        virtual void setRotationPoint(float x, float y, float z);

        ///
        /// \brief getAngle, return the angle of rotation
        /// \return angle of rotation (0 to 360)
        ///
        virtual float getAngle();

        ///
        /// \brief getRotationPoint, the point around which the rotation is performed
        /// \return ScenePoint3D containing the coordinate of the point
        ///
        virtual ScenePoint3D getRotationPoint();

        ///
        /// \brief draw, encapsulate child node inside an opengl Push/Pop matrix where the rotation is applied
        /// \param id, id of the selected shape
        ///
        virtual void draw();
};

#endif // SCENEROTATION_H
