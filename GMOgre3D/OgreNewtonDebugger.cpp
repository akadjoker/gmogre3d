#include "stdafx.h"
#include "OgreNewtonDebugger.h"
#include "OgreEuler.h"

#include <sstream>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreManualObject.h>


void LogMsg(Ogre::String error_msg)
{
   Ogre::LogManager::getSingleton().getDefaultLog()->logMessage(error_msg, Ogre::LML_CRITICAL);
}



Ogre::Real ConvertFromGMYaw2(double yaw)
{
   Ogre::Real ogre_yaw = yaw;

   // We may have passed in values that are greater or less than
   // the yaw constraints, so wrap these around.
   if (ogre_yaw >= 360)
      ogre_yaw -= 360;
   else if (ogre_yaw < 0)
      ogre_yaw += 360;

   if (ogre_yaw <= 90.0)
      ogre_yaw = abs(ogre_yaw - 90);
   else if (ogre_yaw <= 180.0)
      ogre_yaw = 270 + abs(ogre_yaw - 180);
   else if (ogre_yaw <= 270.0)
      ogre_yaw = 180 + abs(ogre_yaw - 270);
   else
      ogre_yaw = 90 + abs(ogre_yaw - 360);

   return ogre_yaw;
}


//////////////////////////////////////////////////////////
// DEUBBER FUNCTIONS
//////////////////////////////////////////////////////////
OgreNewtonDebugger::OgreNewtonDebugger(const NewtonWorld* world)
{
    m_world = world;
    m_debugnode = NULL;
    m_raycastsnode = NULL;
    m_defaultcolor = Ogre::ColourValue::White;

    m_recordraycasts = false;
    m_markhitbodies = false;
    m_raycol = Ogre::ColourValue::Green;
    m_convexcol = Ogre::ColourValue::Blue;
    m_hitbodycol = Ogre::ColourValue::Red;
    m_prefilterdiscardedcol = Ogre::ColourValue::Black;

    m_font_name = "BlueHighway";
    m_font_size = 0.5;
}

OgreNewtonDebugger::~OgreNewtonDebugger()
{
    deInit();
}

void OgreNewtonDebugger::init( Ogre::SceneManager* smgr )
{
    if( !m_debugnode )
    {
        m_debugnode = smgr->getRootSceneNode()->createChildSceneNode("__OgreNewt__Debugger__Node__");
        m_debugnode->setListener(this);
    }

    if( !m_raycastsnode )
    {
        m_raycastsnode = smgr->getRootSceneNode()->createChildSceneNode("__OgreNewt__Raycasts_Debugger__Node__");
        m_raycastsnode->setListener(this);
    }
}

void OgreNewtonDebugger::deInit()
{
    clearBodyDebugDataCache();
    if (m_debugnode)
    {
        m_debugnode->setListener(NULL);
        m_debugnode->removeAndDestroyAllChildren();
        m_debugnode->getParentSceneNode()->removeAndDestroyChild( m_debugnode->getName() );
        m_debugnode = NULL;
    }


    clearRaycastsRecorded();
    if( m_raycastsnode )
    {
        m_raycastsnode->setListener(NULL);
        m_raycastsnode->removeAndDestroyAllChildren();
        m_raycastsnode->getParentSceneNode()->removeAndDestroyChild( m_raycastsnode->getName() );
        m_raycastsnode = NULL;
    }
}

void OgreNewtonDebugger::nodeDestroyed (const Ogre::Node *node)
{
    if(node == m_debugnode)
    {
        m_debugnode = NULL;
        clearBodyDebugDataCache();
    }

    if(node == m_raycastsnode)
    {
        m_raycastsnode = NULL;
        clearRaycastsRecorded();
    }
}


void OgreNewtonDebugger::clearBodyDebugDataCache()
{
        for(BodyDebugDataMap::iterator it = m_cachemap.begin(); it != m_cachemap.end(); it++)
        {
            Ogre::ManualObject* mo = it->second.m_lines;
            if( mo )
                delete mo;
            MovableText *text = it->second.m_text;
            if( text )
                delete text;
        }
        m_cachemap.clear();
}


void OgreNewtonDebugger::showDebugInformation( )
{
    if (!m_debugnode)
        return;

    m_debugnode->removeAllChildren();

    // make the new lines.
    for( NewtonBody* body = NewtonWorldGetFirstBody(m_world); body; body = NewtonWorldGetNextBody(m_world, body) )
    {
        processBody(body);
    } 


    // delete old entries
    BodyDebugDataMap newmap;
    for(BodyDebugDataMap::iterator it = m_cachemap.begin(); it != m_cachemap.end(); it++)
    {
        if( it->second.m_updated )
            newmap.insert(*it);
        else
        {
            Ogre::ManualObject* mo = it->second.m_lines;
            if( mo )
                delete mo;
            MovableText *text = it->second.m_text;
            if( text )
                delete text;
        }
    }

    m_cachemap.swap(newmap);
}

void OgreNewtonDebugger::hideDebugInformation()
{
    // erase any existing lines!
    if( m_debugnode )
        m_debugnode->removeAllChildren();
}

void OgreNewtonDebugger::setMaterialColor(const int mat, Ogre::ColourValue col)
{
    m_materialcolors[mat] = col;
}

void OgreNewtonDebugger::setDefaultColor(Ogre::ColourValue col)
{
    m_defaultcolor = col;
}

void OgreNewtonDebugger::setFont(Ogre::String font_name, Ogre::Real font_size)
{
   m_font_name = font_name;
   m_font_size = font_size;
}

void OgreNewtonDebugger::processBody( NewtonBody* bod )
{
    NewtonBody* newtonBody = bod;
    MaterialIdColorMap::iterator it = m_materialcolors.find( NewtonBodyGetMaterialGroupID(newtonBody) );

    Ogre::Vector3 pos;
    Ogre::Quaternion ori;
    getBodyPositionOrientation(bod, pos, ori);

    // ----------- create debug-text ------------
    std::ostringstream oss_name;
    oss_name << "__OgreNewt__Debugger__Body__" << bod << "__";
    std::ostringstream oss_info;
    oss_info.precision(2);
    oss_info.setf(std::ios::fixed,std::ios::floatfield);
    Ogre::Vector3 inertia;
    Ogre::Real mass;

    NewtonBodyGetMassMatrix( bod, &mass, &inertia.x, &inertia.y, &inertia.z );

    oss_info << "mass: " << mass << std::endl << "inertia: " << inertia << std::endl;
    oss_info << "postion: " << pos << std::endl;

    oss_info << "orientation: Euler(";
    oss_info << Ogre::Radian(GmnBodyGetRotation(static_cast<double>(reinterpret_cast<intptr_t>(bod)), 0)).valueDegrees();
    oss_info << ", " << Ogre::Radian(GmnBodyGetRotation(static_cast<double>(reinterpret_cast<intptr_t>(bod)), 1)).valueDegrees();
    oss_info << ", " << Ogre::Radian(GmnBodyGetRotation(static_cast<double>(reinterpret_cast<intptr_t>(bod)), 2)).valueDegrees();
    oss_info << ")" << std::endl;

    oss_info << "velocity: " << getBodyVelocity(bod) << std::endl << "omega: " << getBodyOmega(bod) << std::endl;
    // ----------- ------------------ ------------


    // look for cached data
    BodyDebugData* data = &m_cachemap[bod];
    if( data->m_lastcol == NewtonBodyGetCollision(bod) ) // use cached data
    {
        // set new position...
        data->m_node->setPosition(pos);
        data->m_node->setOrientation(ori);
        data->m_updated = 1;
        m_debugnode->addChild(data->m_node);
        data->m_text->setCaption(oss_info.str());
        data->m_text->setLocalTranslation(getBodyAABB(bod).getSize().z*1.1*Ogre::Vector3::UNIT_Y);
    }
    else
    {
        data->m_lastcol = NewtonBodyGetCollision(bod);
        data->m_updated = 1;

        if( data->m_node )
        {
            data->m_node->detachAllObjects();
            data->m_node->setPosition(pos);
            data->m_node->setOrientation(ori);
        }
        else
            data->m_node = m_debugnode->createChildSceneNode(pos, ori);

        if( data->m_lines )
            data->m_lines->clear();
        else
        {
            std::ostringstream oss;
            oss << "__OgreNewt__Debugger__Lines__" << bod << "__";
            data->m_lines = new Ogre::ManualObject(oss.str());
        }

        if( data->m_text )
        {
            data->m_text->setCaption(oss_info.str());
            data->m_text->setLocalTranslation(getBodyAABB(bod).getMaximum().y*1.1*Ogre::Vector3::UNIT_Y);
        }
        else
        {
            data->m_text = new MovableText( oss_name.str(), oss_info.str(), m_font_name, m_font_size);
            data->m_text->setLocalTranslation(getBodyAABB(bod).getMaximum().z/2*Ogre::Vector3::UNIT_Y+Ogre::Vector3::UNIT_Y*0.1);
            data->m_text->setTextAlignment( MovableText::H_LEFT, MovableText::V_ABOVE );
        }

        data->m_node->attachObject(data->m_text);

        data->m_lines->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST );

        // set color
        if( it != m_materialcolors.end() )
            data->m_lines->colour(it->second);
        else
            data->m_lines->colour(m_defaultcolor);

        float matrix[16];
        QuatPosToMatrix(Ogre::Quaternion::IDENTITY, Ogre::Vector3::ZERO, &matrix[0]);
        
        NewtonCollisionForEachPolygonDo( NewtonBodyGetCollision(newtonBody), &matrix[0], newtonPerPoly, data->m_lines );
        
        data->m_lines->end();
        data->m_node->attachObject(data->m_lines);
    }
}

void OgreNewtonDebugger::newtonPerPoly( void* userData, int vertexCount, const float* faceVertec, int id )
{
    Ogre::ManualObject* lines = (Ogre::ManualObject*)userData;
    Ogre::Vector3 p0, p1;

        if( vertexCount < 2 )
            return;

    int i= vertexCount - 1;
    p0 = Ogre::Vector3( faceVertec[(i*3) + 0], faceVertec[(i*3) + 1], faceVertec[(i*3) + 2] );


    for (i=0;i<vertexCount;i++)
    {
        p1 = Ogre::Vector3( faceVertec[(i*3) + 0], faceVertec[(i*3) + 1], faceVertec[(i*3) + 2] );

        lines->position( p0 );
        lines->position( p1 );

        p0 = p1;
    }
}


// ----------------- raycast-debugging -----------------------
void OgreNewtonDebugger::startRaycastRecording(bool markhitbodies)
{
    m_recordraycasts = true;
    m_markhitbodies = markhitbodies;
}

bool OgreNewtonDebugger::isRaycastRecording()
{
    return m_recordraycasts;
}

bool OgreNewtonDebugger::isRaycastRecordingHitBodies()
{
    return m_markhitbodies;
}

void OgreNewtonDebugger::clearRaycastsRecorded()
{
    if( m_raycastsnode )
    {
/*
        while( m_raycastsnode->numAttachedObjects() > 0 )
        {
            delete m_raycastsnode->detachObject((unsigned short)0);
        }
*/
        m_raycastsnode->removeAndDestroyAllChildren();
    }

    for(ManualObjectList::iterator it = mRecordedRaycastObjects.begin(); it != mRecordedRaycastObjects.end(); it++)
    {
        delete (*it);
    }
    mRecordedRaycastObjects.clear();
}

void OgreNewtonDebugger::stopRaycastRecording()
{
    m_recordraycasts = false;
}

void OgreNewtonDebugger::setRaycastRecordingColor(Ogre::ColourValue rayCol, Ogre::ColourValue convexCol, Ogre::ColourValue hitBodyCol, Ogre::ColourValue prefilterDiscardedBodyCol)
{
    m_raycol = rayCol;
    m_convexcol = convexCol;
    m_hitbodycol = hitBodyCol;
    m_prefilterdiscardedcol = prefilterDiscardedBodyCol;
}

void OgreNewtonDebugger::addRay(const Ogre::Vector3 &startpt, const Ogre::Vector3 &endpt)
{
    if (!m_raycastsnode)
        return;

    static int i = 0;
    std::ostringstream oss;
    oss << "__OgreNewt__Raycast_Debugger__Lines__Raycastline__" << i++ << "__";
    Ogre::ManualObject *line = new Ogre::ManualObject(oss.str());

    line->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST );
    line->colour(m_raycol);
    line->position(startpt);
    line->position(endpt);
    line->end();

#ifndef WIN32
    m_world->ogreCriticalSectionLock();
#endif
    mRecordedRaycastObjects.push_back(line);
    m_raycastsnode->attachObject(line);
#ifndef WIN32
    m_world->ogreCriticalSectionUnlock();
#endif
}

void OgreNewtonDebugger::addConvexRay(const NewtonCollision *col, const Ogre::Vector3 &startpt, const Ogre::Quaternion &colori, const Ogre::Vector3 &endpt)
{
    if (!m_raycastsnode)
        return;

    static int i = 0;
    // lines from aab
    std::ostringstream oss;
    oss << "__OgreNewt__Raycast_Debugger__Lines__Convexcastlines__" << i++ << "__";
    Ogre::ManualObject *line = new Ogre::ManualObject(oss.str());

    line->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST );
    line->colour(m_convexcol);

    // aab1
    Ogre::AxisAlignedBox aab1 = getCollisionAABB((NewtonCollision*)col, colori, startpt);
    const Ogre::Vector3* corners1 = aab1.getAllCorners();
    Ogre::AxisAlignedBox aab2 = getCollisionAABB((NewtonCollision*)col, colori, endpt);
    const Ogre::Vector3* corners2 = aab2.getAllCorners();
    for(int i = 0; i < 4; i++)
    {
        line->position(corners1[i]); line->position(corners1[(i+1)%4]);
        line->position(corners1[i+4]); line->position(corners1[(i+1)%4+4]);
        line->position(corners2[i]); line->position(corners2[(i+1)%4]);
        line->position(corners2[i+4]); line->position(corners2[(i+1)%4+4]);
        line->position(corners1[i]); line->position(corners2[i]);
        line->position(corners1[i+4]); line->position(corners2[i+4]);
    }
    line->position(corners1[0]); line->position(corners1[6]);
    line->position(corners1[1]); line->position(corners1[5]);
    line->position(corners1[2]); line->position(corners1[4]);
    line->position(corners1[3]); line->position(corners1[7]);
    line->position(corners2[0]); line->position(corners2[6]);
    line->position(corners2[1]); line->position(corners2[5]);
    line->position(corners2[2]); line->position(corners2[4]);
    line->position(corners2[3]); line->position(corners2[7]);

    // bodies
    float matrix[16];
    QuatPosToMatrix(colori, startpt, &matrix[0]);
    NewtonCollisionForEachPolygonDo( col, &matrix[0], newtonPerPoly, line );
    QuatPosToMatrix(colori, endpt, &matrix[0]);
    NewtonCollisionForEachPolygonDo( col, &matrix[0], newtonPerPoly, line );


    line->end();


#ifndef WIN32
    m_world->ogreCriticalSectionLock();
#endif
    mRecordedRaycastObjects.push_back(line);
    m_raycastsnode->attachObject(line);
#ifndef WIN32
    m_world->ogreCriticalSectionUnlock();
#endif
}

void OgreNewtonDebugger::addDiscardedBody(const NewtonBody* body)
{
    if (!m_raycastsnode)
        return;

    static int i = 0;
    float matrix[16];
    Ogre::Vector3 pos;
    Ogre::Quaternion ori;

    std::ostringstream oss;
    oss << "__OgreNewt__Raycast_Debugger__Lines__DiscardedBody__" << i++ << "__";
    Ogre::ManualObject *line = new Ogre::ManualObject(oss.str());

    line->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST );
    line->colour(m_prefilterdiscardedcol);

    getBodyPositionOrientation((NewtonBody*)body, pos, ori);
    QuatPosToMatrix(ori, pos, &matrix[0]);
    NewtonCollisionForEachPolygonDo(  NewtonBodyGetCollision(body) , &matrix[0], newtonPerPoly, line );

    line->end();


#ifndef WIN32
    m_world->ogreCriticalSectionLock();
#endif
    mRecordedRaycastObjects.push_back(line);
    m_raycastsnode->attachObject(line);
#ifndef WIN32
    m_world->ogreCriticalSectionUnlock();
#endif
}

Ogre::AxisAlignedBox OgreNewtonDebugger::getBodyAABB(NewtonBody *body) const
{
    Ogre::AxisAlignedBox ret;
    Ogre::Vector3 min, max;
    NewtonBodyGetAABB( body, &min.x, &max.x );

    ret.setExtents( min, max );
    return ret;
}

void OgreNewtonDebugger::addHitBody(const NewtonBody* body)
{
    if (!m_raycastsnode)
        return;

    static int i = 0;
    float matrix[16];
    Ogre::Vector3 pos;
    Ogre::Quaternion ori;

    std::ostringstream oss;
    oss << "__OgreNewt__Raycast_Debugger__Lines__HitBody__" << i++ << "__";
    Ogre::ManualObject *line = new Ogre::ManualObject(oss.str());

    line->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST );
    line->colour(m_hitbodycol);

    getBodyPositionOrientation((NewtonBody*)body, pos, ori);
    QuatPosToMatrix(ori, pos, &matrix[0]);
    NewtonCollisionForEachPolygonDo( NewtonBodyGetCollision(body) , &matrix[0], newtonPerPoly, line );

    line->end();

#ifndef WIN32
    m_world->ogreCriticalSectionLock();
#endif
    mRecordedRaycastObjects.push_back(line);
    m_raycastsnode->attachObject(line);
#ifndef WIN32
    m_world->ogreCriticalSectionUnlock();
#endif
}

Ogre::Vector3 OgreNewtonDebugger::collisionSupportVertex( const NewtonCollision *col, const Ogre::Vector3& dir )
{
   Ogre::Vector3 ret;
   NewtonCollisionSupportVertex( col, &dir.x, &ret.x );
   return ret;
}

Ogre::AxisAlignedBox OgreNewtonDebugger::collisionCalculateFittingAABB( const NewtonCollision *col, const Ogre::Quaternion& orient, const Ogre::Vector3& pos )
{
    Ogre::Vector3 max, min;

    for( int i = 0; i < 3; i++ )
    {
       Ogre::Vector3 currentDir, supportVertex;

       currentDir = Ogre::Vector3::ZERO;
       currentDir[i] = 1;
       currentDir = orient*currentDir;
       supportVertex = collisionSupportVertex( col, currentDir ) - pos;
       max[i] = supportVertex.dotProduct(currentDir);

       currentDir *= -1.0f;
       supportVertex = collisionSupportVertex( col, currentDir ) - pos;
       min[i] = -supportVertex.dotProduct(currentDir);
    }

    return Ogre::AxisAlignedBox(min, max);
}


Ogre::AxisAlignedBox OgreNewtonDebugger::getCollisionAABB(NewtonCollision *col, const Ogre::Quaternion& orient, const Ogre::Vector3& pos )
{
   Ogre::AxisAlignedBox box;
    
//  float matrix[16];
//  OgreNewt::QuatPosToMatrix( orient, pos, matrix );
    if( col )
    {
//      NewtonCollisionCalculateAABB( m_col, matrix, &min.x, &max.x );
		collisionCalculateFittingAABB (col, orient, pos );
		Ogre::Vector3 min, max;
        box = Ogre::AxisAlignedBox(min, max);
    }
    return box;
}

void OgreNewtonDebugger::getBodyPositionOrientation( NewtonBody *body, Ogre::Vector3& pos, Ogre::Quaternion& orient )
{
   float matrix[16];
   NewtonBodyGetMatrix ( body, matrix );
	
   Ogre::Real yaw = GmnBodyGetRotation(static_cast<double>(reinterpret_cast<intptr_t>(body)), 0);
   Ogre::Real pitch = GmnBodyGetRotation(static_cast<double>(reinterpret_cast<intptr_t>(body)), 1);
   Ogre::Real roll = GmnBodyGetRotation(static_cast<double>(reinterpret_cast<intptr_t>(body)), 2);
   orient = Euler(Ogre::Degree(ConvertFromGMYaw2(Ogre::Radian(yaw).valueDegrees())), Ogre::Radian(pitch), Ogre::Radian(roll));
	pos = Ogre::Vector3( matrix[12], matrix[13], matrix[14] );
return;

   //orient = Euler(Ogre::Degree(ConvertFromGMYaw2(Ogre::Radian(yaw).valueDegrees())), Ogre::Radian(pitch), Ogre::Radian(roll));
   //orient = Euler(Ogre::Degree(ConvertFromGMYaw2(Ogre::Radian(roll).valueDegrees())), Ogre::Radian(pitch), Ogre::Radian(yaw));

orient = Euler(Ogre::Radian(0), Ogre::Radian(0), Ogre::Radian(1.57));
orient = Euler(Ogre::Radian(-1.57), Ogre::Radian(0), Ogre::Radian(0));

orient = Euler(Ogre::Radian(0), Ogre::Radian(0), Ogre::Radian(0)); // nothing
//orient = Euler(Ogre::Radian(0), Ogre::Radian(1.57), Ogre::Radian(0)); // pitch down 90
//orient = Euler(Ogre::Radian(0), Ogre::Radian(4.71), Ogre::Radian(0)); // (-1.57) pitch up 90

std::ostringstream oss_info;
oss_info << "Yaw: " << yaw << std::endl;
oss_info << "Pitch: " << pitch << std::endl;
oss_info << "Roll: " << roll << std::endl;
//MessageBoxA(NULL, oss_info.str().c_str(), "", MB_OK);

//MessageBoxA(NULL, Ogre::StringConverter::toString(yaw).c_str(), "", MB_OK);
//MessageBoxA(NULL, Ogre::StringConverter::toString(ConvertFromGMYaw2(Ogre::Radian(yaw).valueDegrees())).c_str(), "", MB_OK);

//orient = Euler(Ogre::Radian(3.14), Ogre::Radian(0), Ogre::Radian(0)); // yaws 

//orient = Euler(Ogre::Degree(ConvertFromGMYaw2(Ogre::Radian(yaw).valueDegrees())), Ogre::Degree(00), Ogre::Degree(0)); // yaws 

//orient = Euler(Ogre::Degree(ConvertFromGMYaw2(Ogre::Radian(yaw).valueDegrees())), Ogre::Degree(0), Ogre::Radian(roll));
orient = Euler(Ogre::Degree(ConvertFromGMYaw2(Ogre::Radian(yaw).valueDegrees())), Ogre::Degree(pitch), Ogre::Radian(roll));

	pos = Ogre::Vector3( matrix[12], matrix[14], matrix[13] );
}

Ogre::Vector3 OgreNewtonDebugger::getBodyVelocity(NewtonBody *body) const
{
    Ogre::Vector3 ret;
    NewtonBodyGetVelocity( body, &ret.x );
    Ogre::Real z = ret.y;
    ret.y = ret.z;

    return ret;
}

Ogre::Vector3 OgreNewtonDebugger::getBodyOmega(NewtonBody *body) const
{
    Ogre::Vector3 ret;
    NewtonBodyGetOmega( body, &ret.x );
    Ogre::Real z = ret.y;
    ret.y = ret.z;

    return ret;
}

void OgreNewtonDebugger::QuatPosToMatrix( const Ogre::Quaternion& _quat, const Ogre::Vector3 &pos, float* matrix )
{
   // this takes a Quaternion and a Vector3 and creates a float array
   // which is more meaningful to Newton.

   using namespace Ogre;
   Matrix3 rot;
   Vector3 xcol, ycol, zcol;

   Ogre::Quaternion quat (_quat);
   quat.normalise();
   quat.ToRotationMatrix (rot);   // creates a 3x3 rotation matrix from the Quaternion.

   xcol = rot.GetColumn(0);
   ycol = rot.GetColumn(1);
   zcol = rot.GetColumn(2);

   // now fill the final matrix with the appropriate data:
   matrix[0] = xcol.x;
   matrix[1] = xcol.y;
   matrix[2] = xcol.z;
   matrix[3] = 0.0f;

   matrix[4] = ycol.x;
   matrix[5] = ycol.y;
   matrix[6] = ycol.z;
   matrix[7] = 0.0f;

   matrix[8] = zcol.x;
   matrix[9] = zcol.y;
   matrix[10] = zcol.z;
   matrix[11] = 0.0f;

   matrix[12] = pos.x;
   matrix[13] = pos.y;
   matrix[14] = pos.z;
   matrix[15] = 1.0;
}