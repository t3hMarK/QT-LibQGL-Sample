/***********************************************************************************************
 *  Description   : Class that defines a scale change to a number of child SceneNode
 *  Author        : Marc Legault
 *  Creation Date : 10/27/2013
 ***********************************************************************************************
 *  Author          Date        Description of change(s)
 ***********************************************************************************************
 *  Marc Legault    11/05/2013  Code cleanup
 ***********************************************************************************************/

#ifndef SCENESCALING_H
#define SCENESCALING_H

#include <scenetransformation.h>

class SceneScaling : public SceneTransformation
{
    private :
        float _x;   //X axis scaling factor
        float _y;   //Y axis scaling factor
        float _z;   //Z axis scaling factor

    public :
        ///
        /// \brief SceneScaling, Create a new SceneScaling
        /// \param parentNode, parent SceneNode of scaling
        /// \param x, X axis scaling factor
        /// \param y, Y axis scaling factor
        /// \param z, Z axis scaling factor
        ///
        SceneScaling(SceneNode* parentNode, float x, float y, float z);

        ///
        /// \brief setScalingFactorX, set the X axis scaling factor
        /// \param x, X axis scaling factor
        ///
        virtual void setScalingFactorX(float x);

        ///
        /// \brief setScalingFactorY, set the Y axis scaling factor
        /// \param y, Y axis scaling factor
        ///
        virtual void setScalingFactorY(float y);

        ///
        /// \brief setScalingFactorZ, set the Z axis scaling factor
        /// \param z, Z axis scaling factor
        ///
        virtual void setScalingFactorZ(float z);

        ///
        /// \brief getScalingFactorX, return the X axis scaling factor
        /// \return X axis scaling factor
        ///
        virtual float getScalingFactorX();

        ///
        /// \brief getScalingFactorY, return the Y axis scaling factor
        /// \return Y axis scaling factor
        ///
        virtual float getScalingFactorY();

        ///
        /// \brief getScalingFactorZ, return the Z axis scaling factor
        /// \return Z axis scaling factor
        ///
        virtual float getScalingFactorZ();

        ///
        /// \brief draw, encapsulate child node inside an opengl Push/Pop matrix where the scale change is applied
        /// \param id, id of the selected shape
        ///
        virtual void draw();
};

#endif // SCENESCALING_H
