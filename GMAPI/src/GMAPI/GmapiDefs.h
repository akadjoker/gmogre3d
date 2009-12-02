/************************************************************************** 
  LICENSE:

    GMAPI is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    GMAPI is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with GMAPI; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301 USA
***************************************************************************/

/*************************************************************************
  GmapiDefs.h
  - Definitions and declarations of types used by GMAPI.

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once

#ifdef GMAPI_USE_D3D
  #include <d3d8.h>
#else
  #include <windows.h>
  typedef void IDirect3D8, IDirect3DDevice8, IDirect3DTexture8;
#endif

namespace gm {

  struct GMVALUE;
  typedef GMVALUE* PGMVALUE;

  struct GMVARIABLE;
  typedef GMVARIABLE* PGMVARIABLE;

  typedef char __PADDING1;
  typedef long __PADDING4;

  enum BoundingBoxType { BBOX_UNKNOWN = -1, BBOX_AUTOMATIC, BBOX_FULLIMAGE, BBOX_MANUAL };
  enum SoundType { SND_UNKNOWN = -1, SND_NORMAL, SND_BGMUSIC, SND_3DSOUND, SND_MULTIMEDIA };
  enum GMValueType { VT_REAL, VT_STRING };

  typedef struct __GMDIRECT3DINFO {
    IDirect3D8* d3dInterface;
    IDirect3DDevice8* d3dDevice;

    int renderWidth;
    int renderHeight;
  } GMDIRECT3DINFO, *PGMDIRECT3DINFO;

  typedef struct __GMBITMAP {
    void* _rttiData;

    BOOL exists;

    DWORD width;
    DWORD height;

    BYTE* bitmapData;
  } GMBITMAP, *PGMBITMAP;

  typedef struct __GMTEXTURE {
    IDirect3DTexture8* texture;

    DWORD imageWidth;
    DWORD imageHeight;

    DWORD textureWidth;
    DWORD textureHeight;

    BOOL isValid;
  } GMTEXTURE, *PGMTEXTURE;

  typedef __declspec( align( 4 ) ) struct __GMSPRITE {
    void* _rttiData;

    BoundingBoxType bboxType;
    int bboxLeft;
    int bboxTop;
    int bboxRight;
    int bboxBottom;

    DWORD nSubimages;

    DWORD width;
    DWORD height;

    int originX;
    int originY;

    BOOL maskExists;
    void* _collisionMask;
    BOOL preciseCollision;

    PGMBITMAP* bitmaps;

    bool transparent;
    bool smoothEdges;
    bool preload;

    DWORD* textureIDs;
  } GMSPRITE, *PGMSPRITE;

  typedef struct __GMSPRITESTORAGE {
    PGMSPRITE* sprites;
    char** names;

    int arraySize;
  } GMSPRITESTORAGE, *PGMSPRITESTORAGE;

  typedef __declspec( align( 4 ) ) struct __GMBACKGROUND {
    void* _rttiData;

    int width;
    int height;

    GMBITMAP* bitmap;

    bool transparent;
    bool smoothEdges;
    bool preload;

    int textureId;
    __PADDING4 _padding;
  } GMBACKGROUND, *PGMBACKGROUND;

  typedef struct __GMBACKGROUNDSTORAGE {
    PGMBACKGROUND* backgrounds;
    char** names;

    int arraySize;
  } GMBACKGROUNDSTORAGE, *PGMBACKGROUNDSTORAGE;

  typedef struct __GMSURFACE {
    int textureId;

    int width;
    int height;

    BOOL exists;
  } GMSURFACE, *PGMSURFACE;


  typedef __declspec( align( 1 ) ) struct __GMFUNCTIONINFO {
    BYTE nameLength;
    char name[67];

    void* address;
    char _padding[8];
  } GMFUNCTIONINFO, *PGMFUNCTIONINFO;

  typedef struct __GMFUNCTIONINFOSTORAGE {
    GMFUNCTIONINFO* functions;
    DWORD nFunctions;
  } GMFUNCTIONINFOSTORAGE, *PGMFUNCTIONINFOSTORAGE;

  typedef struct __GMSCRIPTCONTENT {
    void* _rttiData;
    char* code;
    
    __PADDING4 _padding[3];
  } GMSCRIPTCONTENT, *PGMSCRIPTCONTENT;

  typedef struct __GMSCRIPTDEBUGINFO {
    void* _rttiData;
    __PADDING4 _padding;

    BOOL isCompiled;

    char* code;

    DWORD type;
  } GMSCRIPTDEBUGINFO, *PGMSCRIPTDEBUGINFO;

  typedef struct __GMSCRIPT {
    void* _rttiData;

    GMSCRIPTCONTENT* pScriptContent;
    GMSCRIPTDEBUGINFO* debugInfo;
  } GMSCRIPT, *PGMSCRIPT;

  typedef struct __GMSCRIPTSTORAGE {
    char** symbols;
    int symbolCount;

    PGMSCRIPT* scripts;
    char** names;

    int arraySize;
  } GMSCRIPTSTORAGE, *PGMSCRIPTSTORAGE;

  typedef struct __GMSOUNDDATA {
    void* _rttiData;

    BYTE* file;
    DWORD fileSize;
  } GMSOUNDDATA, *PGMSOUNDDATA;

  typedef struct __GMSOUND {
    void* _rttiData;

    SoundType type;

    char* fileExt;
    char* filename;

    GMSOUNDDATA* sndData;

    BOOL preload;
    DWORD effectsBitmask;

    DWORD unknown;

    double volume;
    double pan;

    int sndId;

    char* filePath;
  } GMSOUND, *PGMSOUND;

  typedef struct __GMSOUNDSTORAGE {
    PGMSOUND* sounds;
    char** names;

    int arraySize;
  } GMSOUNDSTORAGE, *PGMSOUNDSTORAGE;

  typedef struct __GMVARIABLELIST {
    void* _rttiData;

    GMVARIABLE* variables;
    int count;
  } GMVARIABLELIST, *PGMVARIABLELIST;

  typedef struct __GMINSTANCE {
    void* _rttiData;
    int id;
    int sprite_index;
    double image_index;
    double image_speed;
    double image_xscale;
    double image_yscale;
    double image_angle;
    double image_alpha;
    int image_blend;
    int mask_index;
    double depth;

    __PADDING4 _padding1[2];

    double x;
    double y;
    double xstart;
    double ystart;
    double xprevious;
    double yprevious;
    double direction;
    double speed;
    double friction;
    double gravity_direction;
    double gravity;
    double hspeed;
    double vspeed;
    int bbox_left;
    int bbox_top;
    int bbox_right;
    int bbox_bottom;
    bool visible;
    bool solid;
    bool persistent;
    int object_index;

    __PADDING4 _padding2;

    int alarm[12];
    PGMVARIABLELIST variableListPtr;

    __PADDING1 _padding3;
    bool deactivated;
    __PADDING1 _padding4[2];

    int path_index;
    double path_position;
    double path_positionprevious;
    double path_speed;
    double path_scale;
    double path_orientation;
    int path_endaction;

    __PADDING4 _padding5[5];

    int timeline_index;

    __PADDING4 _padding6;

    double timeline_position;
    double timeline_speed;
  } GMINSTANCE, *PGMINSTANCE;

}
