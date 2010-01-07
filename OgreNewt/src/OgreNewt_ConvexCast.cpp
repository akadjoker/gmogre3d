#include "OgreNewt_stdafx.h"
#include "OgreNewt_Body.h"
#include "OgreNewt_World.h"
#include "OgreNewt_ConvexCast.h"
#include "OgreNewt_Tools.h"
#include "OgreNewt_Debugger.h"
#include "OgreNewt_Collision.h"



namespace OgreNewt
{
	Convexcast::Convexcast() :
		mReturnInfoList(NULL),
		mReturnInfoListLength(0),
		mReturnInfoListSize(0)
	{
	}

	Convexcast::~Convexcast()
	{
		if( mReturnInfoList )
		{
			delete[] mReturnInfoList;
		}
	}


	void Convexcast::go(const OgreNewt::World* world, const OgreNewt::ConvexCollisionPtr& col, const Ogre::Vector3& startpt, const Ogre::Quaternion &colori, const Ogre::Vector3& endpt, int maxcontactscount, int threadIndex)
	{

		if( world->getDebugger().isRaycastRecording() )
		{
			world->getDebugger().addConvexRay(col, startpt, colori, endpt);
		}
		// reserve memory
		if( mReturnInfoListSize < maxcontactscount )
		{
			mReturnInfoListSize = 0;
			if( mReturnInfoList )
				delete[] mReturnInfoList;
			mReturnInfoList = new NewtonWorldConvexCastReturnInfo[maxcontactscount];
			mReturnInfoListSize = maxcontactscount;
		}

		memset(mReturnInfoList, 0, sizeof(mReturnInfoList[0])*mReturnInfoListSize);
		// perform the cast
		float matrix[16];
		OgreNewt::Converters::QuatPosToMatrix(colori, startpt, &matrix[0] );
		mFirstContactDistance = -1;


		mReturnInfoListLength = 
			NewtonWorldConvexCast( world->getNewtonWorld(), &matrix[0], (float*)&endpt, col->getNewtonCollision(),
			&mFirstContactDistance, this, OgreNewt::Convexcast::newtonConvexcastPreFilter,
			mReturnInfoList, mReturnInfoListSize, threadIndex);


		if( world->getDebugger().isRaycastRecording() && world->getDebugger().isRaycastRecordingHitBodies() )
		{
			Body* body;
			for(int i = 0; i < mReturnInfoListLength; i++)
			{
				body = (OgreNewt::Body*) NewtonBodyGetUserData(mReturnInfoList[i].m_hitBody);
				world->getDebugger().addHitBody(body);
			}
		}
	}

	unsigned _CDECL Convexcast::newtonConvexcastPreFilter(const NewtonBody *body, const NewtonCollision *collision, void* userData)
	{
		// get our object!
		Convexcast* me = (Convexcast*)userData;

		Body* bod = (Body*)NewtonBodyGetUserData( body );
		const World* world = bod->getWorld();

		if (me->userPreFilterCallback( bod ))
			return 1;
		else
		{

			if( world->getDebugger().isRaycastRecording() && world->getDebugger().isRaycastRecordingHitBodies() )
			{
				world->getDebugger().addDiscardedBody(bod);
			}

			return 0;
		}
	}



	//-------------------------------------------------------------------------------------
	BasicConvexcast::ConvexcastContactInfo::ConvexcastContactInfo()
	{
		mBody = NULL;
	}

	BasicConvexcast::ConvexcastContactInfo::~ConvexcastContactInfo() {}

	BasicConvexcast::BasicConvexcast()
	{
	}

	BasicConvexcast::BasicConvexcast(const OgreNewt::World* world, const OgreNewt::ConvexCollisionPtr& col, const Ogre::Vector3& startpt, const Ogre::Quaternion &colori, const Ogre::Vector3& endpt, int maxcontactscount, int threadIndex)
	{
		go( world, col, startpt, colori, endpt, maxcontactscount, threadIndex);
	}

	BasicConvexcast::~BasicConvexcast() {}


	int BasicConvexcast::calculateBodyHitCount() const
	{
		int count = 0;
		for( int i = 0; i < mReturnInfoListLength; i++ )
		{
			int j;
			for( j = 0; j < i; j++ )
				if( mReturnInfoList[i].m_hitBody == mReturnInfoList[j].m_hitBody )
					break;

			if( j == i )
				count++;
		}

		return count;
	}


	int BasicConvexcast::getContactsCount() const
	{
		return mReturnInfoListLength;
	}

	BasicConvexcast::ConvexcastContactInfo BasicConvexcast::getInfoAt( int hitnum ) const
	{
		ConvexcastContactInfo info;

		if( hitnum < 0 || hitnum >= mReturnInfoListLength )
			return info;


		info.mBody = (OgreNewt::Body*) NewtonBodyGetUserData(mReturnInfoList[hitnum].m_hitBody);
		info.mCollisionID = mReturnInfoList[hitnum].m_contactID;
		info.mContactNormal.x = mReturnInfoList[hitnum].m_normal[0];
		info.mContactNormal.y = mReturnInfoList[hitnum].m_normal[1];
		info.mContactNormal.z = mReturnInfoList[hitnum].m_normal[2];
		info.mContactNormalOnHitPoint.x = mReturnInfoList[hitnum].m_normalOnHitPoint[0];
		info.mContactNormalOnHitPoint.y = mReturnInfoList[hitnum].m_normalOnHitPoint[1];
		info.mContactNormalOnHitPoint.z = mReturnInfoList[hitnum].m_normalOnHitPoint[2];
		info.mContactPoint.x = mReturnInfoList[hitnum].m_point[0];
		info.mContactPoint.y = mReturnInfoList[hitnum].m_point[1];
		info.mContactPoint.z = mReturnInfoList[hitnum].m_point[2];
		info.mContactPenetration = mReturnInfoList[hitnum].m_penetration;

		return info;
	}

	Ogre::Real BasicConvexcast::getDistanceToFirstHit() const
	{
		return mFirstContactDistance;
	}

}   // end NAMESPACE OgreNewt

