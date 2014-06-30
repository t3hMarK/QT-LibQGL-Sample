#ifndef SCENECIRCLE_H
#define SCENECIRCLE_H

#include <sceneshape.h>

class SceneCircle : public SceneShape
{
    private:
        static const int _circlePoints = 100;                       //number of line to draw
        static const float _angle = 2.0f * 3.1416f / _circlePoints; //amount used to increment drawing angle

        float _radius;                                              //radius of the circle

    public:
        ///
        /// \brief SceneCircle, Create an instance of SceneCircle
        /// \param parentNode, parent SceneNode of this SceneCircle
        /// \param radius, radius of circle
        /// \param r, red primitive 0 to 255
        /// \param g, green primitive 0 to 255
        /// \param b, blue primitive 0 to 255
        ///
        SceneCircle(SceneNode* parentNode, float radius, int r, int g, int b);

        ///
        /// \brief draw
        ///
        virtual void draw(int id);
};

#endif // SCENECIRCLE_H
