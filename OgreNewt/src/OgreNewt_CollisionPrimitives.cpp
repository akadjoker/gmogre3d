#include "OgreNewt_stdafx.h"
#include "OgreNewt_CollisionPrimitives.h"
#include "OgreNewt_Tools.h"
#include "OgreNewt_RayCast.h"
#include "OgreNewt_World.h"

#ifdef __APPLE__
#   include <Ogre/OgreEntity.h>
#   include <Ogre/OgreSubMesh.h>
#   include <Ogre/OgreSceneNode.h>
#else
#   include <OgreEntity.h>
#   include <OgreSubMesh.h>
#   include <OgreSceneNode.h>
#endif

namespace OgreNewt
{

    namespace CollisionPrimitives
    {

        // OgreNewt::CollisionPrimitives::Null
        Null::Null(const OgreNewt::World *world) : Collision( world )
        {
            m_col = NewtonCreateNull( m_world->getNewtonWorld() );
        }


        // OgreNewt::CollisionPrimitives::Box
        Box::Box(const World* world) : ConvexCollision( world )
        {}

        Box::Box( const World* world, const Ogre::Vector3& size, int id, const Ogre::Quaternion& orient, const Ogre::Vector3& pos ) : ConvexCollision( world )
        {
            float matrix[16];

            OgreNewt::Converters::QuatPosToMatrix( orient, pos, &matrix[0] );

            m_col = NewtonCreateBox( m_world->getNewtonWorld(), (float)size.x, (float)size.y, (float)size.z, id, &matrix[0] );
        }



        // OgreNewt::CollisionPrimitives::Ellipsoid
        Ellipsoid::Ellipsoid(const World* world) : ConvexCollision( world )
        {}

        Ellipsoid::Ellipsoid( const World* world, const Ogre::Vector3& size, int id, const Ogre::Quaternion& orient, const Ogre::Vector3& pos ) : ConvexCollision( world )
        {
            float matrix[16];

            OgreNewt::Converters::QuatPosToMatrix( orient, pos, &matrix[0] );

            m_col = NewtonCreateSphere( m_world->getNewtonWorld(), (float)size.x, (float)size.y, (float)size.z, id, &matrix[0] );
        }


        // OgreNewt::CollisionPrimitives::Cylinder
        Cylinder::Cylinder(const World* world) : ConvexCollision( world )
        {}

        Cylinder::Cylinder( const World* world, Ogre::Real radius, Ogre::Real height, int id,
                                    const Ogre::Quaternion& orient, const Ogre::Vector3& pos ) : ConvexCollision( world )
        {
            float matrix[16];

            OgreNewt::Converters::QuatPosToMatrix( orient, pos, &matrix[0] );

            m_col = NewtonCreateCylinder( m_world->getNewtonWorld(), (float)radius, (float)height, id, &matrix[0] );
        }


        // OgreNewt::CollisionPrimitives::Capsule
        Capsule::Capsule(const World* world) : ConvexCollision( world )
        {}

        Capsule::Capsule( const World* world, Ogre::Real radius, Ogre::Real height, int id,
                                    const Ogre::Quaternion& orient, const Ogre::Vector3& pos ) : ConvexCollision( world )
        {
            float matrix[16];

            OgreNewt::Converters::QuatPosToMatrix( orient, pos, &matrix[0] );

            m_col = NewtonCreateCapsule( m_world->getNewtonWorld(), (float)radius, (float)height, id, &matrix[0] );
        }


        // OgreNewt::CollisionPrimitives::Cone
        Cone::Cone(const World* world) : ConvexCollision( world )
        {}

        Cone::Cone( const World* world, Ogre::Real radius, Ogre::Real height, int id,
                                    const Ogre::Quaternion& orient, const Ogre::Vector3& pos ) : ConvexCollision( world )
        {
            float matrix[16];

            OgreNewt::Converters::QuatPosToMatrix( orient, pos, &matrix[0] );

            m_col = NewtonCreateCone( m_world->getNewtonWorld(), (float)radius, (float)height, id, &matrix[0] );
        }

        // OgreNewt::CollisionPrimitives::ChamferCylinder
        ChamferCylinder::ChamferCylinder(const World* world) : ConvexCollision( world )
        {}

        ChamferCylinder::ChamferCylinder( const World* world, Ogre::Real radius, Ogre::Real height, int id,
                                    const Ogre::Quaternion& orient, const Ogre::Vector3& pos ) : ConvexCollision( world )
        {
            float matrix[16];

            OgreNewt::Converters::QuatPosToMatrix( orient, pos, &matrix[0] );

            m_col = NewtonCreateChamferCylinder( m_world->getNewtonWorld(), (float)radius, (float)height, id, &matrix[0] );
        }


        
        // OgreNewt::CollisionPrimitives::ConvexHull
        ConvexHull::ConvexHull(const World* world) : ConvexCollision( world )
        {}

        ConvexHull::ConvexHull( const World* world, Ogre::Entity* obj, int id, const Ogre::Quaternion& orient, const Ogre::Vector3& pos, Ogre::Real tolerance, const Ogre::Vector3& forceScale ) : ConvexCollision( world )
        {
            Ogre::Vector3 scale(1.0,1.0,1.0);
            

            //get the mesh!
            //Ogre::Entity* obj = (Ogre::Entity*)node->getAttachedObject(0);
            Ogre::MeshPtr mesh = obj->getMesh();

                       
            // get scale, if attached to node
            Ogre::Node * node = obj->getParentNode();
            if (node) scale = node->getScale();
            if (forceScale != Ogre::Vector3::ZERO) scale = forceScale;

            //find number of submeshes
            unsigned short sub = mesh->getNumSubMeshes();

            size_t total_verts = 0;

            Ogre::VertexData* v_data;
            bool addedShared = false;

            for (unsigned short i=0;i<sub;i++)
            {
                Ogre::SubMesh* sub_mesh = mesh->getSubMesh(i);
                if (sub_mesh->useSharedVertices)
                {
                    if (!addedShared)
                    {
                        v_data = mesh->sharedVertexData;
                        total_verts += v_data->vertexCount;

                        addedShared = true;
                    }
                }
                else
                {
                    v_data = sub_mesh->vertexData;
                    total_verts += v_data->vertexCount;
                }
            }
        
            addedShared = false;

            //make array to hold vertex positions!
            Ogre::Vector3* vertices = new Ogre::Vector3[total_verts];
            unsigned int offset = 0;

            //loop back through, adding vertices as we go!
            for (unsigned short i=0;i<sub;i++)
            {
                Ogre::SubMesh* sub_mesh = mesh->getSubMesh(i);
                Ogre::VertexDeclaration* v_decl;
                const Ogre::VertexElement* p_elem;
                float* v_Posptr;
                size_t v_count;
        
                v_data = NULL;

                if (sub_mesh->useSharedVertices)
                {
                    if (!addedShared)
                    {
                        v_data = mesh->sharedVertexData;
                        v_count = v_data->vertexCount;
                        v_decl = v_data->vertexDeclaration;
                        p_elem = v_decl->findElementBySemantic( Ogre::VES_POSITION );
                        addedShared = true;
                    }
                }
                else
                {
                    v_data = sub_mesh->vertexData;
                    v_count = v_data->vertexCount;
                    v_decl = v_data->vertexDeclaration;
                    p_elem = v_decl->findElementBySemantic( Ogre::VES_POSITION );
                }

                if (v_data)
                {
                    size_t start = v_data->vertexStart;
                    //pointer
                    Ogre::HardwareVertexBufferSharedPtr v_sptr = v_data->vertexBufferBinding->getBuffer( p_elem->getSource() );
                    unsigned char* v_ptr = static_cast<unsigned char*>(v_sptr->lock( Ogre::HardwareBuffer::HBL_READ_ONLY ));
                    unsigned char* v_offset;

                    //loop through vertex data...
                    for (size_t j=start; j<(start+v_count); j++)
                    {
                        //get offset to Position data!
                        v_offset = v_ptr + (j * v_sptr->getVertexSize());
                        p_elem->baseVertexPointerToElement( v_offset, &v_Posptr );

                        //now get vertex positions...
                        vertices[offset].x = *v_Posptr; v_Posptr++;
                        vertices[offset].y = *v_Posptr; v_Posptr++;
                        vertices[offset].z = *v_Posptr; v_Posptr++;

                        vertices[offset] *= scale;

                        offset++;
                    }

                    //unlock buffer
                    v_sptr->unlock();
                }

        
            }

            float matrix[16];

            OgreNewt::Converters::QuatPosToMatrix( orient, pos, &matrix[0] );
    
            //okay, let's try making the ConvexHull!
            m_col = NewtonCreateConvexHull( m_world->getNewtonWorld(), (int)total_verts, (float*)&vertices[0].x, sizeof(Ogre::Vector3), tolerance, id, &matrix[0] );

            delete []vertices;

        }


        // OgreNewt::CollisionPrimitives::ConvexHull
        ConvexHull::ConvexHull( const World* world, const Ogre::Vector3* verts, int vertcount, int id, const Ogre::Quaternion& orient, const Ogre::Vector3& pos, Ogre::Real tolerance ) : ConvexCollision( world )
        {
            float matrix[16];
            OgreNewt::Converters::QuatPosToMatrix( orient, pos, &matrix[0] );

            //make the collision primitive.
            m_col = NewtonCreateConvexHull( m_world->getNewtonWorld(), vertcount, (float*)&verts[0].x, sizeof(Ogre::Vector3), tolerance, id, &matrix[0]);
        }




        TreeCollision::TreeCollision( const World* world) : Collision(world)
        {
        }


        TreeCollision::TreeCollision( const World* world, Ogre::Entity* obj, bool optimize, int id, FaceWinding fw ) : Collision( world )
        {
            Ogre::Vector3 scale;

            start(id);

            Ogre::MeshPtr mesh = obj->getMesh();

                        // get scale, if attached to node
                        Ogre::Node * node = obj->getParentNode();
                        if (node) scale = node->getScale();

            //find number of sub-meshes
            unsigned short sub = mesh->getNumSubMeshes();

            for (unsigned short cs=0;cs<sub;cs++)
            {
                Ogre::SubMesh* sub_mesh = mesh->getSubMesh(cs);

                //vertex data!
                Ogre::VertexData* v_data;

                if (sub_mesh->useSharedVertices)
                {
                    v_data = mesh->sharedVertexData;
                }
                else
                {
                    v_data = sub_mesh->vertexData;
                }
        
                //let's find more information about the Vertices...
                Ogre::VertexDeclaration* v_decl = v_data->vertexDeclaration;
                const Ogre::VertexElement* p_elem = v_decl->findElementBySemantic( Ogre::VES_POSITION );
        
                // get pointer!
                Ogre::HardwareVertexBufferSharedPtr v_sptr = v_data->vertexBufferBinding->getBuffer( p_elem->getSource() );
                unsigned char* v_ptr = static_cast<unsigned char*>(v_sptr->lock( Ogre::HardwareBuffer::HBL_READ_ONLY ));
        
                //now find more about the index!!
                Ogre::IndexData* i_data = sub_mesh->indexData;
                size_t index_count = i_data->indexCount;
                size_t poly_count = index_count / 3;
        
                // get pointer!
                Ogre::HardwareIndexBufferSharedPtr i_sptr = i_data->indexBuffer;
        
                // 16 or 32 bit indices?
                bool uses32bit = ( i_sptr->getType() == Ogre::HardwareIndexBuffer::IT_32BIT );
                unsigned long* i_Longptr;
                unsigned short* i_Shortptr;
        
        
                if ( uses32bit)
                {
                    i_Longptr = static_cast<unsigned long*>(i_sptr->lock( Ogre::HardwareBuffer::HBL_READ_ONLY ));
                    
                }
                else
                {
                    i_Shortptr = static_cast<unsigned short*>(i_sptr->lock( Ogre::HardwareBuffer::HBL_READ_ONLY ));
                }


                //now loop through the indices, getting polygon info!
                int i_offset = 0;

                for (size_t i=0; i<poly_count; i++)
                {
                    Ogre::Vector3 poly_verts[3];
                    unsigned char* v_offset;
                    float* v_Posptr;
                    int idx;

                    if (uses32bit)
                    {
                        for (int j=0;j<3;j++)
                        {
                            idx = i_Longptr[i_offset+j];        // index to first vertex!
                            v_offset = v_ptr + (idx * v_sptr->getVertexSize());
                            p_elem->baseVertexPointerToElement( v_offset, &v_Posptr );
                            //now get vertex position from v_Posptr!
                            poly_verts[j].x = *v_Posptr; v_Posptr++;
                            poly_verts[j].y = *v_Posptr; v_Posptr++;
                            poly_verts[j].z = *v_Posptr; v_Posptr++;

                            poly_verts[j] *= scale;
                        }
                    }
                    else
                    {
                        for (int j=0;j<3;j++)
                        {
                            idx = i_Shortptr[i_offset+j];       // index to first vertex!
                            v_offset = v_ptr + (idx * v_sptr->getVertexSize());
                            p_elem->baseVertexPointerToElement( v_offset, &v_Posptr );
                            //now get vertex position from v_Posptr!

                            // switch poly winding.
                            poly_verts[j].x = *v_Posptr; v_Posptr++;
                            poly_verts[j].y = *v_Posptr; v_Posptr++;
                            poly_verts[j].z = *v_Posptr; v_Posptr++;
                            
                            poly_verts[j] *= scale;
                        }
                    }
                    
                    if (fw == FW_DEFAULT)
                    {
                        addPoly( poly_verts, cs );  
                    }
                    else
                    {
                        Ogre::Vector3 rev_poly_verts[3];
                        rev_poly_verts[0] = poly_verts[0];
                        rev_poly_verts[0] = poly_verts[2];
                        rev_poly_verts[0] = poly_verts[1];

                        addPoly( rev_poly_verts, cs );
                    }

                    i_offset += 3;
                }

                //unlock the buffers!
                v_sptr->unlock();
                i_sptr->unlock();
    
            }
            //done!
            finish( optimize );
        }


        TreeCollision::TreeCollision(const OgreNewt::World *world, int numVertices, int numIndices, const float *vertices, const int *indices, bool optimize, int id, FaceWinding fw) : OgreNewt::Collision( world )
        {
            start(id);
 
            int numPolys = numIndices / 3;
 
            Ogre::Vector3 *vecVertices = new Ogre::Vector3[numVertices];
 
            for (int curVertex = 0; curVertex < numVertices; curVertex++)
            {
                vecVertices[curVertex].x = vertices[0 + curVertex * 3];
                vecVertices[curVertex].y = vertices[1 + curVertex * 3];
                vecVertices[curVertex].z = vertices[2 + curVertex * 3];
            }
 
            for ( int poly = 0; poly < numPolys; poly++ )
            {
                Ogre::Vector3 poly_verts[3];
 
                if (fw == FW_DEFAULT)
                {
                    poly_verts[0] = vecVertices[indices[0 + poly * 3]];
                    poly_verts[1] = vecVertices[indices[1 + poly * 3]];
                    poly_verts[2] = vecVertices[indices[2 + poly * 3]];
                }
                else
                {
                    poly_verts[0] = vecVertices[indices[0 + poly * 3]];
                    poly_verts[2] = vecVertices[indices[1 + poly * 3]];
                    poly_verts[1] = vecVertices[indices[2 + poly * 3]];
                }
 
                addPoly( poly_verts, 0 );
            }
 
            delete [] vecVertices;
     
             finish( optimize );
        }


        TreeCollision::TreeCollision( const World* world, int numVertices, Ogre::Vector3* vertices, Ogre::IndexData* indexData, bool optimize, int id, FaceWinding fw) : Collision( world )
        {
            start(id);

            unsigned int numPolys = indexData->indexCount / 3;
            Ogre::HardwareIndexBufferSharedPtr hwIndexBuffer=indexData->indexBuffer;
            size_t indexSize=hwIndexBuffer->getIndexSize();
            void* indices=hwIndexBuffer->lock(Ogre::HardwareBuffer::HBL_READ_ONLY);

            assert((indexSize==2) || (indexSize==4));

            if (indexSize==2)
            {
                unsigned short* curIndex=(unsigned short*)indices;
                for ( unsigned int poly = 0; poly < numPolys; poly++ )
                {
                    Ogre::Vector3 poly_verts[3];

                    //invert vertex winding (otherwise, raycasting won't work???)
                    if (fw == FW_DEFAULT)
                    {
                        poly_verts[0] = vertices[*curIndex]; curIndex++;
                        poly_verts[1] = vertices[*curIndex]; curIndex++;
                        poly_verts[2] = vertices[*curIndex]; curIndex++;
                    }
                    else
                    {
                        poly_verts[0] = vertices[*curIndex]; curIndex++;
                        poly_verts[2] = vertices[*curIndex]; curIndex++;
                        poly_verts[1] = vertices[*curIndex]; curIndex++;
                    }

                    addPoly( poly_verts, 0 );
                }
            }
            else
            {
                unsigned int* curIndex=(unsigned int*)indices;
                for ( unsigned int poly = 0; poly < numPolys; poly++ )
                {
                    Ogre::Vector3 poly_verts[3];

                    if (fw == FW_DEFAULT)
                    {
                        poly_verts[0] = vertices[*curIndex]; curIndex++;
                        poly_verts[1] = vertices[*curIndex]; curIndex++;
                        poly_verts[2] = vertices[*curIndex]; curIndex++;
                    }
                    else
                    {
                        poly_verts[0] = vertices[*curIndex]; curIndex++;
                        poly_verts[2] = vertices[*curIndex]; curIndex++;
                        poly_verts[1] = vertices[*curIndex]; curIndex++;
                    }

                    addPoly( poly_verts, 0 );
                }
            }
      
            hwIndexBuffer->unlock();
            finish( optimize );
        } 


        void TreeCollision::start(int id)
        {
            m_col = NewtonCreateTreeCollision( m_world->getNewtonWorld(), id );
            NewtonTreeCollisionBeginBuild( m_col );
        }

        void TreeCollision::addPoly( Ogre::Vector3* polys, unsigned int ID )
        {
            NewtonTreeCollisionAddFace( m_col, 3, (float*)&polys[0].x, sizeof(Ogre::Vector3), ID );
        }

        void TreeCollision::finish( bool optimize )
        {
            NewtonTreeCollisionEndBuild( m_col, optimize );
        }


        float _CDECL TreeCollision::newtonRayCastCallback(float interception, float *normal, int faceId, void *userData)
        {
            Body* bod = ((Raycast*)userData)->m_treecollisioncallback_lastbody;
            
            //! TODO: what do we need to return here?
            if(!bod)
                return 0;

            ((Raycast*)userData)->userCallback( bod, interception, Ogre::Vector3(normal[0], normal[1], normal[2]), faceId );

            ((Raycast*)userData)->m_treecollisioncallback_bodyalreadyadded = true;

            return interception;
        }

        void TreeCollision::setRayCastCallbackactive(bool active, const NewtonCollision *col )
        {
            if(active)
                NewtonTreeCollisionSetUserRayCastCallback( col, newtonRayCastCallback );
            else
                NewtonTreeCollisionSetUserRayCastCallback( col, NULL );
        }

        int TreeCollisionSceneParser::count = 0;
        
        
        TreeCollisionSceneParser::TreeCollisionSceneParser( OgreNewt::World* world ) : TreeCollision( world )
        {
        }
        
        void TreeCollisionSceneParser::parseScene( Ogre::SceneNode *startNode, int id, bool optimize, FaceWinding fw)
        {
            count = 0;

            start(id);

            // parse the individual nodes.
            Ogre::Quaternion rootOrient = Ogre::Quaternion::IDENTITY;
            Ogre::Vector3 rootPos = Ogre::Vector3::ZERO;
            Ogre::Vector3 rootScale = startNode->getScale();;

            _parseNode( startNode, rootOrient, rootPos, rootScale, fw );

            finish( optimize );
        }

        void TreeCollisionSceneParser::_parseNode(Ogre::SceneNode *node, const Ogre::Quaternion &curOrient, const Ogre::Vector3 &curPos, const Ogre::Vector3 &curScale, FaceWinding fw)
        {
            // parse this scene node.
            // do children first.
            Ogre::Quaternion thisOrient = curOrient * node->getOrientation();
            Ogre::Vector3 thisPos = curPos + (curOrient * (node->getPosition() * curScale));
            Ogre::Vector3 thisScale = curScale * node->getScale();

            Ogre::SceneNode::ChildNodeIterator child_it = node->getChildIterator();

            while (child_it.hasMoreElements())
            {
                _parseNode( (Ogre::SceneNode*)child_it.getNext(), thisOrient, thisPos, thisScale, fw );
            }


            // now add the polys from this node.
            //now get the mesh!
            unsigned int num_obj = node->numAttachedObjects();
            for (unsigned int co=0; co<num_obj; co++)
            {
                Ogre::MovableObject* obj = node->getAttachedObject(co);
                if (obj->getMovableType() != "Entity")
                    continue;
            
                Ogre::Entity* ent = (Ogre::Entity*)obj;

                if (!entityFilter(node, ent, fw))
                    continue;

                Ogre::MeshPtr mesh = ent->getMesh();

                //find number of sub-meshes
                unsigned short sub = mesh->getNumSubMeshes();

                for (unsigned short cs=0;cs<sub;cs++)
                {
                    Ogre::SubMesh* sub_mesh = mesh->getSubMesh(cs);

                    //vertex data!
                    Ogre::VertexData* v_data;

                    if (sub_mesh->useSharedVertices)
                    {   
                        v_data = mesh->sharedVertexData;
                    }
                    else
                    {
                        v_data = sub_mesh->vertexData;
                    }
        
                    //let's find more information about the Vertices...
                    Ogre::VertexDeclaration* v_decl = v_data->vertexDeclaration;
                    const Ogre::VertexElement* p_elem = v_decl->findElementBySemantic( Ogre::VES_POSITION );
        
                    // get pointer!
                    Ogre::HardwareVertexBufferSharedPtr v_sptr = v_data->vertexBufferBinding->getBuffer( p_elem->getSource() );
                    unsigned char* v_ptr = static_cast<unsigned char*>(v_sptr->lock( Ogre::HardwareBuffer::HBL_READ_ONLY ));
        
                    //now find more about the index!!
                    Ogre::IndexData* i_data = sub_mesh->indexData;
                    size_t index_count = i_data->indexCount;
                    size_t poly_count = index_count / 3;
        
                    // get pointer!
                    Ogre::HardwareIndexBufferSharedPtr i_sptr = i_data->indexBuffer;
        
                    // 16 or 32 bit indices?
                    bool uses32bit = ( i_sptr->getType() == Ogre::HardwareIndexBuffer::IT_32BIT );
                    unsigned long* i_Longptr;
                    unsigned short* i_Shortptr;
        
                    if ( uses32bit)
                    {
                        i_Longptr = static_cast<unsigned long*>(i_sptr->lock( Ogre::HardwareBuffer::HBL_READ_ONLY ));
                    }
                    else
                    {
                        i_Shortptr = static_cast<unsigned short*>(i_sptr->lock( Ogre::HardwareBuffer::HBL_READ_ONLY ));
                    }

                    //now loop through the indices, getting polygon info!
                    int i_offset = 0;

                    for (size_t i=0; i<poly_count; i++)
                    {
                        Ogre::Vector3 poly_verts[3];
                        unsigned char* v_offset;
                        float* v_Posptr;
                        int idx;

                        if (uses32bit)
                        {
                            for (int j=0;j<3;j++)
                            {
                                idx = i_Longptr[i_offset+j];        // index to first vertex!
                                v_offset = v_ptr + (idx * v_sptr->getVertexSize());
                                p_elem->baseVertexPointerToElement( v_offset, &v_Posptr );
                                //now get vertex position from v_Posptr!
                                poly_verts[j].x = *v_Posptr; v_Posptr++;
                                poly_verts[j].y = *v_Posptr; v_Posptr++;
                                poly_verts[j].z = *v_Posptr; v_Posptr++;
    
                                poly_verts[j] = thisPos + (thisOrient * (poly_verts[j] * curScale));
                            }
                        }
                        else
                        {
                            for (int j=0;j<3;j++)
                            {
                                idx = i_Shortptr[i_offset+j];       // index to first vertex!
                                v_offset = v_ptr + (idx * v_sptr->getVertexSize());
                                p_elem->baseVertexPointerToElement( v_offset, &v_Posptr );
                                //now get vertex position from v_Posptr!

                                // switch poly winding.
                                poly_verts[j].x = *v_Posptr; v_Posptr++;
                                poly_verts[j].y = *v_Posptr; v_Posptr++;
                                poly_verts[j].z = *v_Posptr; v_Posptr++;
                            
                                poly_verts[j] = thisPos + (thisOrient * (poly_verts[j] * curScale));
                            }
                        }
                    
                        if (fw == FW_DEFAULT)
                        {
                            addPoly( poly_verts, cs );  
                        }
                        else
                        {
                            Ogre::Vector3 rev_poly_verts[3];
                            rev_poly_verts[0] = poly_verts[0];
                            rev_poly_verts[0] = poly_verts[2];
                            rev_poly_verts[0] = poly_verts[1];

                            addPoly( rev_poly_verts, cs );
                        }
                        
                        i_offset += 3;
                    }

                    //unlock the buffers!
                    v_sptr->unlock();
                    i_sptr->unlock();

                }
            }

        }





        // OgreNewt::CollisionPrimitives::CompoundCollision
        CompoundCollision::CompoundCollision(const World* world) : Collision( world )
        {}
        
        CompoundCollision::CompoundCollision( const World* world, std::vector<OgreNewt::CollisionPtr> col_array, int id ) : Collision( world )
        {
            //get the number of elements.
            unsigned int num = col_array.size();

            // create simple array.
            NewtonCollision** array = new NewtonCollision*[num];

            for (unsigned int i=0;i<num;i++)
            {
                array[i] = (NewtonCollision*)col_array[i]->getNewtonCollision();
            }

            m_col = NewtonCreateCompoundCollision( world->getNewtonWorld(), num, array, id );


            delete[] array;
        }

        
        // OgreNewt::CollisionPrimitives::Pyramid
        Pyramid::Pyramid(const World* world) : ConvexCollision( world )
        {}

        Pyramid::Pyramid( const World* world, const Ogre::Vector3& size, int id, const Ogre::Quaternion& orient, const Ogre::Vector3& pos, Ogre::Real tolerance ) : ConvexCollision( world )
        {
            float matrix[16];

            OgreNewt::Converters::QuatPosToMatrix( orient, pos, &matrix[0] );

            // create a simple pyramid collision primitive using the Newton Convex Hull interface.
            // this function places the center of mass 1/3 up y from the base.

            float* vertices = new float[15];
            unsigned short idx = 0;

            // make the bottom base.
            for (int ix=-1; ix<=1; ix+=2)
            {
                for (int iz=-1; iz<=1; iz+=2)
                {
                    vertices [idx++] = (size.x/2.0) * ix;
                    vertices [idx++] = -(size.y/3.0);
                    vertices [idx++] = (size.z/2.0) * iz;
                }
            }

            // make the tip.
            vertices [idx++] = 0.0f;
            vertices [idx++] = (size.y*2.0/3.0);
            vertices [idx++] = 0.0f;

            //make the collision primitive.
            m_col = NewtonCreateConvexHull( m_world->getNewtonWorld(), 5, vertices, sizeof(float)*3, tolerance, id, &matrix[0]);


            delete []vertices;
        }

		/*
		HeightField::HeightField(const OgreNewt::World *world, int width, int height, int gridsDiagonals, unsigned short *elevationMap, char *attributeMap, Ogre::Real horizontalScale, Ogre::Real verticleScale, int shapeID) : OgreNewt::Collision (world)
		{
			m_col = NewtonCreateHeightFieldCollision(world->getNewtonWorld(),width,height,gridsDiagonals,elevationMap,attributeMap,float(horizontalScale),float(verticleScale),shapeID);
		}

		HeightField::HeightField(const OgreNewt::World *world, Ogre::Terrain *terrain, int shapeID) : OgreNewt::Collision (world)
		{
			int width = terrain->getSize();
			int height = width;
			int gridsDiagonals = 0;

			char *attributes;
			unsigned short *elevations;

			float *hData = terrain->getHeightData();
			float verticleScale = 65535 / (terrain->getMaxHeight() - terrain->getMinHeight());
			Ogre::Real horizontalScale = terrain->getWorldSize() / (terrain->getSize() - 1);

			elevations = (unsigned short*) malloc (width * height * sizeof (unsigned short));
			attributes = (char*) malloc (width * height * sizeof (char));
			memset (attributes, 1, width * height * sizeof (char));

			//HeightData reversed and mirror on X axis
			int x = 0;

			for (int i = width * height - 1; i >= 0; i--)
			{
				elevations[i-width+(x*2)+1] = unsigned short(*(hData)*verticleScale);
				hData++;
				x++;
				if (x == width) x = 0; 
			}

			createHeightFieldCollision(world, width, height, gridsDiagonals, elevations, attributes, horizontalScale, float(1 / verticleScale), shapeID);

			free (elevations);
			free (attributes);
		}

		void HeightField::createHeightFieldCollision(const OgreNewt::World *world, int width, int height, int gridsDiagonals, unsigned short *elevationMap, char *attributeMap, Ogre::Real horizontalScale, Ogre::Real verticleScale, int shapeID) 
		{
			m_col = NewtonCreateHeightFieldCollision(world->getNewtonWorld(), width, height, gridsDiagonals, elevationMap, attributeMap, float(horizontalScale), float(verticleScale), shapeID);
		}
		*/
    }   // end namespace CollisionPrimitives
}   // end namespace OgreNewt
