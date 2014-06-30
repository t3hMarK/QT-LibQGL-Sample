/***********************************************************************************************
 *  Description   : Class which represent a 3D disk in the scene
 *  Author        : Marc Legault
 *  Creation Date : 11/04/2013
 ***********************************************************************************************
 *  Author          Date        Description of change(s)
 ***********************************************************************************************
 *  Marc Legault    11/05/2013  Code cleanup
 ***********************************************************************************************/

#ifndef SCENEDISK_H
#define SCENEDISK_H

#include <sceneshape.h>

class SceneDisk : public SceneShape
{
    private:
        //disk variables
        float _innerRadius;
        float _outerRadius;
        float _slices;
        float _stacks;

        //Quadric
        GLUquadric* _quadric;

    public:
        ///
        /// \brief SceneDisk, Create a new disk (gluDisk) with the specified SceneNode
        /// \param parentNode, parent SceneNode
        /// \param innerRadius, inner radius of the disk
        /// \param outerRadius, outer radius of the disk
        /// \param slices, number of vertical slices
        /// \param stacks, number of horizontal slices
        /// \param r, red primitive 0 to 255
        /// \param g, green primitive 0 to 255
        /// \param b, blue primitive 0 to 255
        ///
        SceneDisk(SceneNode* parentNode, float innerRadius, float outerRadius, float slices, float stacks, int r, int g, int b);

        ///
        /// \brief setInnerRadius, set inner radius of the disk
        /// \param radius
        ///
        virtual void setInnerRadius(float innerRadius);

        ///
        /// \brief setOuterRadius, set outer radius of the disk
        /// \param radius
        ///
        virtual void setOuterRadius(float outerRadius);

        ///
        /// \brief setSlices, set the number of vertical slices
        /// \param slices,
        ///
        virtual void setSlices(float slices);

        ///
        /// \brief setStacks, set the number of horizontal slices
        /// \param stacks,
        ///
        virtual void setStacks(float stacks);

        ///
        /// \brief getInnerRadius, return inner radius of the disk
        /// \return
        ///
        virtual float getInnerRadius();

        ///
        /// \brief getOuterRadius, return outer radius of the disk
        /// \return
        ///
        virtual float getOuterRadius();

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
        /// \brief draw, render the disk using OpenGL primitive
        ///
        virtual void draw();
};

#endif // SCENEDISK_H
