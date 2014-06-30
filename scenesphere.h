/***********************************************************************************************
 *  Description   : Class which represent a 3D oval in the scene
 *  Author        : Marc Legault
 *  Creation Date : 10/23/2013
 ***********************************************************************************************
 *  Author          Date        Description of change(s)
 ***********************************************************************************************
 *  Marc Legault    10/27/2013  Refactored class to use gluSphere as drawing primitive
 *  Marc Legault    10/31/2013  Added texture capabilities to class
 *  Marc Legault    11/05/2013  Code cleanup
 ***********************************************************************************************/

#ifndef SCENESPHERE_H
#define SCENESPHERE_H

#include <sceneshape.h>

class SceneSphere : public SceneShape
{

    private :
        //sphere parameter
        float _radius;
        float _slices;
        float _stacks;

        //Quadric
        GLUquadric* _quadric;

        //texture parameter
        GLuint _texture;
        GLenum _target;
        GLenum _pname;
        GLuint _params;

    public :
        ///
        /// \brief SceneSphere, Create a new sphere (gluSphere) with the specified SceneNode
        /// \param parentNode, parent SceneNode
        /// \param radius, radius of the sphere
        /// \param slices, number of vertical slices
        /// \param stacks, number of horizontal slices
        /// \param texture, texture id
        /// \param r, red primitive 0 to 255
        /// \param g, green primitive 0 to 255
        /// \param b, blue primitive 0 to 255
        ///
        SceneSphere(SceneNode* parentNode, float radius, float slices, float stacks, unsigned int texture, int r, int g, int b);

        ///
        /// \brief setTexParameter, set a texture parameter
        /// \param target,
        /// \param pname,
        /// \param params,
        ///
        virtual void setTexParameter(GLenum target, GLenum pname, GLuint params);

        ///
        /// \brief setRadius, set the radius of the sphere
        /// \param radius
        ///
        virtual void setRadius(float radius);

        ///
        /// \brief setSlices, set the number of vertical slices
        /// \param slices
        ///
        virtual void setSlices(float slices);

        ///
        /// \brief setStacks, set the number of horizontal slices
        /// \param stacks
        ///
        virtual void setStacks(float stacks);

        ///
        /// \brief getRadius, return the radius of the sphere
        /// \return
        ///
        virtual float getRadius();

        ///
        /// \brief getSlices, return the number of vertical slices
        /// \return
        ///
        virtual float getSlices();

        ///
        /// \brief getStack, return the number of horizontal slices
        /// \return
        ///
        virtual float getStack();

        ///
        /// \brief draw, render the sphere using OpenGL primitives
        /// \param id
        ///
        virtual void draw();
};

#endif // SCENESPHERE_H
