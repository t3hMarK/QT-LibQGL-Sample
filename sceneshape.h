/************************************************************************************************************
 *  Description   : Class defining a basic shape in a scene, shape is understood to be a collection of points with at least one point
 *  Author        : Marc Legault
 *  Creation Date : 09/21/2013
 ************************************************************************************************************
 *  Author          Date        Description of change(s)
 ************************************************************************************************************
 *  Marc Legault    09/26/2013  Defined class from stub
 *  Marc Legault    11/05/2013  Code cleanup
 ************************************************************************************************************/

#ifndef SCENESHAPE_H
#define SCENESHAPE_H

#include <scenenode.h>

class SceneShape : public SceneNode
{
    private :
        float _r, _g, _b; //RGB primitive for color of shape

    public :
        ///
        /// \brief SceneShape, create an instance of SceneShape
        /// \param parentNode, parent SceneNode instance
        /// \param r, red primitive 0 to 255
        /// \param g, green primitive 0 to 255
        /// \param b, blue primitive 0 to 255
        ///
        SceneShape(SceneNode* parentNode, int r, int g, int b);

        ///
        /// \brief setColor, set the color of the shape
        /// \param r, red primitive 0 to 255
        /// \param g, green primitive 0 to 255
        /// \param b, blue primitive 0 to 255
        ///
        virtual void setColor(float r, float g, float b);

        ///
        /// \brief getColor, get the color of the shape
        /// \return SceneColorRGB structure containing RGB primaries
        ///
        virtual SceneColorRGB getColor();

        ///
        /// \brief draw, pure virtual function draw to be implemented by subclasses
        ///
        virtual void draw() = 0;
};

#endif // SCENESHAPE_H
