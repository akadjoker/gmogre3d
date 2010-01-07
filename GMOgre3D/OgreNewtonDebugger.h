/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2009 Robert Geiman
                   <robgeiman@gmail.com>

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
--------------------------------------------------------------------------------
*/
#ifndef OGRE_NEWTON_DEBUGGER
#define OGRE_NEWTON_DEBUGGER

#include "world.h"
#include "body.h"
#include "OgreMovableText.h"
//#include "OgreNewt_Prerequisites.h"
//#include "OgreNewt_Tools.h"


    //! For viewing the Newton rigid bodies visually.
    /*!
        This class implements a debug view of the Newton world. You can access it via World::getDebugger().
        It needs to be initialized (call World::getDebugger().init(...)).
    */
    class OgreNewtonDebugger : public Ogre::Node::Listener
    {
    
    public:
       OgreNewtonDebugger(const NewtonWorld* world);
        ~OgreNewtonDebugger();

        //! init the debugger.
        /*
            \param smgr pointer to your Ogre::SceneManager
        */
        void init( Ogre::SceneManager* smgr );

        //! de-init the debugger (cleantup)
        void deInit();

        //! called when one of the nodes used in this class are destroyed
        virtual void nodeDestroyed (const Ogre::Node *);

        //! show the newton world
        /*!
            Draws the Newton world as 3D lines with informative text above each body
        */
        void showDebugInformation();

        //! remove lines and text drawn
        void hideDebugInformation();
    
        //! set default color
        void setDefaultColor(Ogre::ColourValue col);

        //! set font
        void setFont(Ogre::String font_name, Ogre::Real font_size);

        //! set Material color
        void setMaterialColor(const int mat, Ogre::ColourValue col);

        //! enable additional raycast-debugging (this also enables displaying of recorded raycasts!)
        void startRaycastRecording(bool markhitbodies = false);

        //! returns true, if currently recording raycasts
        bool isRaycastRecording();

        //! returns true, if hit bodies are currently recording
        bool isRaycastRecordingHitBodies();

        //! clears all raycasts, that are currently shown, should probably be done once per frame!
        void clearRaycastsRecorded();

        //! disables raycast-debugging
        void stopRaycastRecording();

        //! set the color of the raycast-debug-lines
        void setRaycastRecordingColor(Ogre::ColourValue rayCol, Ogre::ColourValue convexCol, Ogre::ColourValue hitBodyCol, Ogre::ColourValue prefilterDiscardedBodyCol);

        //! this function is used internally
        void addRay(const Ogre::Vector3 &startpt, const Ogre::Vector3 &endpt);

        //! this function is used internally
        void addConvexRay(const NewtonCollision *col, const Ogre::Vector3 &startpt, const Ogre::Quaternion &colori, const Ogre::Vector3 &endpt);

        //! this function is used internally
        void addDiscardedBody(const NewtonBody* body);

        //! this function is used internally
        void addHitBody(const NewtonBody* body);

    protected:
        Ogre::Vector3 collisionSupportVertex( const NewtonCollision *col, const Ogre::Vector3& dir );
        Ogre::AxisAlignedBox collisionCalculateFittingAABB( const NewtonCollision *col, const Ogre::Quaternion& orient, const Ogre::Vector3& pos );
        Ogre::AxisAlignedBox getCollisionAABB(NewtonCollision *col, const Ogre::Quaternion& orient, const Ogre::Vector3& pos );
        Ogre::AxisAlignedBox getBodyAABB(NewtonBody *body) const;
        void getBodyPositionOrientation( NewtonBody *body, Ogre::Vector3& pos, Ogre::Quaternion& orient );
        Ogre::Vector3 getBodyVelocity(NewtonBody *body) const;
        Ogre::Vector3 getBodyOmega(NewtonBody *body) const;
        void QuatPosToMatrix( const Ogre::Quaternion& _quat, const Ogre::Vector3 &pos, float* matrix );

    protected:
        const NewtonWorld*        m_world;
        Ogre::SceneNode*        m_debugnode;
        typedef std::map<int, Ogre::ColourValue> MaterialIdColorMap;
        MaterialIdColorMap      m_materialcolors;
        Ogre::ColourValue       m_defaultcolor;

        // raycast-debugging
        Ogre::SceneNode*        m_raycastsnode;
        bool                    m_recordraycasts;
        Ogre::ColourValue       m_raycol, m_convexcol, m_hitbodycol, m_prefilterdiscardedcol;
        bool                    m_markhitbodies;

        Ogre::String m_font_name;
        Ogre::Real m_font_size;

        struct BodyDebugData
        {
            BodyDebugData() :
#ifdef OGRENEWT_NO_COLLISION_SHAREDPTR
                m_lastcol(NULL),
#endif
                m_node(NULL), m_lines(NULL), m_text(NULL), m_updated(false) {}
            NewtonCollision *m_lastcol;
            Ogre::SceneNode* m_node;
            Ogre::ManualObject* m_lines;
            MovableText* m_text;
            int m_updated;
        };            
        typedef std::map<NewtonBody*, BodyDebugData> BodyDebugDataMap;
        BodyDebugDataMap m_cachemap;

        //! create debug information for one body
        void processBody(NewtonBody* body);

        //! clear debug data cache fo bodies (m_cachemap)
        void clearBodyDebugDataCache();

        typedef std::list<Ogre::ManualObject*> ManualObjectList;
        ManualObjectList mRecordedRaycastObjects;


    private:
        //! this function is declared private, so nobody can use it!
        OgreNewtonDebugger() {}

        //! this function is declared private, so nobody can use it!
        OgreNewtonDebugger(const OgreNewtonDebugger&) {}

        //! this function is declared private, so nobody can use it!
        const OgreNewtonDebugger& operator=(const OgreNewtonDebugger& d) { return d; } // actually this implementation must *never* be used!

        static void newtonPerPoly( void* userData, int vertexCount, const float* faceVertec, int id );
    };

#endif
