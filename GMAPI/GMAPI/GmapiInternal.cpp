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
  GmapiInternal.cpp
  - Definitions of all GMAPI components, excluding wrapped gm functions

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiInternal.h"
#include "GmapiMacros.h"

#include "GmapiResources.h"
#include "GmapiGameGraphics.h"

#ifdef __GNUC__
#define sprintf_s snprintf
#endif

using namespace gm::core;

namespace gm {
  bool                    CGlobals::m_alternativeStructures;

  PGMFUNCTIONINFOSTORAGE  CGMAPI::m_pFunctionData;
  PGMBACKGROUNDSTORAGE    CGMAPI::m_pBackgroundData;
  PGMSPRITESTORAGE        CGMAPI::m_pSpriteData;
  PGMSURFACE*             CGMAPI::m_pSurfaces;
  PGMTEXTURE*             CGMAPI::m_pTextures;
  PGMDIRECT3DDATA         CGMAPI::m_pDirect3dData;
  PGMSCRIPTSTORAGE        CGMAPI::m_pScriptData;
  PGMSOUNDSTORAGE         CGMAPI::m_pSoundData;
  PGMFONTSTORAGE          CGMAPI::m_pFontData;
  PGMPARTICLESTORAGE      CGMAPI::m_pParticleData;

  PGMVARIABLELIST*        CGMAPI::m_pGlobalVarList;
  void**                  CGMAPI::m_pCurrentRoom;
  int*                    CGMAPI::m_pRoomIdArray;
  int*                    CGMAPI::m_pSurfaceArraySize;
  int*                    CGMAPI::m_pRoomCount;
  const char*             CGMAPI::m_pSwapTable;
  void*                   CGMAPI::m_pPatchIdTypeCheck;
  const BYTE*             CGMAPI::m_pPatchDataIdTypeCheck;

  HWND**                  CGMAPI::m_pFormMain;
  HWND**                  CGMAPI::m_pFormDebug;
  HWND**                  CGMAPI::m_pFormScore;

  int*                    IProperties::m_pTransitionKind;
  int*                    IProperties::m_pTransitionSteps;
  int*                    IProperties::m_pCursorSprite;

  PGMSPRITE               ISprite::m_sprite;
  int                     ISprite::m_spriteId;
  int                     ISpriteSubimage::m_subimage;
  PGMBACKGROUND           IBackground::m_background;
  int                     IBackground::m_backgroundId;
  int                     ISurface::m_surfaceId;
  int                     IScript::m_scriptId;
  int                     ISound::m_soundId;
  int                     IFont::m_fontId;
  int                     IParticleSystem::m_particleSystemId;
  PGMPARTICLESYSTEM       IParticleSystem::m_particleSystem;

  /************************************************************************/
  /* CGMAPI class implementation                                          */
  /************************************************************************/

  CGMAPI* CGMAPI::m_self = NULL;
  unsigned long CGMAPI::m_gmVersion = GM_VERSION_INCOMPATIBLE;

  void* CGMAPI::m_gmFunctions[1000];

  CGMAPI* CGMAPI::Create( unsigned long* aResult ) {
    if ( !m_self ) {
      bool success = false;
      m_self = new CGMAPI( &success );

      if ( !success ) {
        delete m_self;
        m_self = NULL;

        *aResult = GMAPI_INITIALIZATION_FAILED;
      } else
        *aResult = GMAPI_INITIALIZATION_SUCCESS;
    } else
      *aResult = GMAPI_ALREADY_INITIALIZED;

    return m_self;
  }

  CGMAPI::CGMAPI( bool* aSuccess ) {
    m_gmVersion = GMAPIInitialize();

    if ( !m_gmVersion )
      *aSuccess = false;
    else {
      GMAPIHookInstall();
      RetrieveDataPointers();
      RetrieveFunctionPointers();

      CGlobals::m_alternativeStructures = ( m_gmVersion == GM_VERSION_80 );
      *aSuccess = true;
    }
  }

  void CGMAPI::Destroy() {
    if ( m_self ) {
      delete m_self;
      m_self = NULL;
    }
  }

  CGMAPI::~CGMAPI() {
    if ( m_gmVersion != GM_VERSION_INCOMPATIBLE )
      GMAPIHookUninstall();
  }

  void CGMAPI::RetrieveDataPointers() {
    if ( m_gmVersion == GM_VERSION_80 ) {

      m_pFunctionData =     GM80_ADDRESS_ARRAY_GMFUNCTIONS;
      m_pSpriteData =       GM80_ADDRESS_STORAGE_SPRITES;
      m_pBackgroundData =   GM80_ADDRESS_STORAGE_BACKGROUNDS;
      m_pSurfaces =         GM80_ADDRESS_ARRAY_SURFACES;
      m_pTextures =         GM80_ADDRESS_ARRAY_TEXTURES;
      m_pDirect3dData =     GM80_ADDRESS_STORAGE_DIRECTX;
      m_pScriptData =       GM80_ADDRESS_STORAGE_SCRIPTS;
      m_pSoundData =        GM80_ADDRESS_STORAGE_SOUNDS;
      m_pFontData =         GM80_ADDRESS_STORAGE_FONTS;
      m_pParticleData =     GM80_ADDRESS_STORAGE_PARTICLES;
      m_pSwapTable =        GM80_ADDRESS_PTR_SWAPTABLE;
      m_pSurfaceArraySize = GM80_ADDRESS_ARRAYSIZE_SURFACES;
      m_pRoomIdArray =      GM80_ADDRESS_ARRAY_ROOMIDS;
      m_pRoomCount =        GM80_ADDRESS_PTR_ROOMCOUNT;

      m_pFormMain =         GM80_ADDRESS_FORM_TRUNNER;
      m_pFormDebug =        GM80_ADDRESS_FORM_TDEBUG;
      m_pFormScore =        GM80_ADDRESS_FORM_TSCORE;

      m_pCurrentRoom =         GM80_ADDRESS_PTR_CURRENTROOM;
      m_pGlobalVarList =       GM80_ADDRESS_PTR_GLOBALVARLIST;

      m_pPatchIdTypeCheck =     GM80_ADDRESS_PATCH_IDENTIFIERTYPECHECKING;
      m_pPatchDataIdTypeCheck = GM80_PATCH_IDENTIFIERTYPECHECKING;

      //////////////////////////////////////////////////////////////////////////

      Properties.m_pGameId =          GM80_ADDRESS_PROPERTY_GAMEID;
      Properties.m_pTempDirectory =   GM80_ADDRESS_PROPERTY_TEMPDIRECTORY;
      Properties.m_pFps =             GM80_ADDRESS_PROPERTY_FPS;
      Properties.m_pRoom =            GM80_ADDRESS_PROPERTY_ROOM;
      Properties.m_pScore =           GM80_ADDRESS_PROPERTY_SCORE;
      Properties.m_pLives =           GM80_ADDRESS_PROPERTY_LIVES;
      Properties.m_pHealth =          GM80_ADDRESS_PROPERTY_HEALTH;
      Properties.m_pShowScore =       GM80_ADDRESS_PROPERTY_SHOWSCORE;
      Properties.m_pShowLives =       GM80_ADDRESS_PROPERTY_SHOWLIVES;
      Properties.m_pShowHealth =      GM80_ADDRESS_PROPERTY_SHOWHEALTH;
      Properties.m_pEventType =       GM80_ADDRESS_PROPERTY_EVENTTYPE;
      Properties.m_pEventNumber =     GM80_ADDRESS_PROPERTY_EVENTNUMBER;
      Properties.m_pEventObject =     GM80_ADDRESS_PROPERTY_EVENTOBJECT;
      Properties.m_pEventAction =     GM80_ADDRESS_PROPERTY_EVENTACTION;
      Properties.m_pErrorLast =       GM80_ADDRESS_PROPERTY_ERRORLAST;
      Properties.m_pErrorOccured =    GM80_ADDRESS_PROPERTY_ERROROCCURED;
      Properties.m_pKeyboardKey =     GM80_ADDRESS_PROPERTY_KEYBOARDKEY;
      Properties.m_pKeyboardLastKey = GM80_ADDRESS_PROPERTY_KEYBOARDLASTKEY;
      Properties.m_pKeyboardString =  GM80_ADDRESS_PROPERTY_KEYBOARDSTRING;
      Properties.m_pMouseButton =     GM80_ADDRESS_PROPERTY_MOUSEBUTTON;
      Properties.m_pMouseLastButton = GM80_ADDRESS_PROPERTY_MOUSELASTBUTTON;
      Properties.m_pViewCurrent =     GM80_ADDRESS_PROPERTY_VIEWCURRENT;
      Properties.m_pTransitionKind =  GM80_ADDRESS_PROPERTY_TRANSITIONKIND;
      Properties.m_pTransitionSteps = GM80_ADDRESS_PROPERTY_TRANSITIONSTEPS;
      Properties.m_pCursorSprite =    GM80_ADDRESS_PROPERTY_CURSORSPRITE;

    } else if ( m_gmVersion == GM_VERSION_70 ) {

      m_pFunctionData =     GM70_ADDRESS_ARRAY_GMFUNCTIONS;
      m_pSpriteData =       GM70_ADDRESS_STORAGE_SPRITES;
      m_pBackgroundData =   GM70_ADDRESS_STORAGE_BACKGROUNDS;
      m_pSurfaces =         GM70_ADDRESS_ARRAY_SURFACES;
      m_pTextures =         GM70_ADDRESS_ARRAY_TEXTURES;
      m_pDirect3dData =     GM70_ADDRESS_STORAGE_DIRECTX;
      m_pScriptData =       GM70_ADDRESS_STORAGE_SCRIPTS;
      m_pSoundData =        GM70_ADDRESS_STORAGE_SOUNDS;
      m_pFontData =         GM70_ADDRESS_STORAGE_FONTS;
      m_pParticleData =     GM70_ADDRESS_STORAGE_PARTICLES;
      m_pSwapTable =        GM70_ADDRESS_PTR_SWAPTABLE;
      m_pSurfaceArraySize = GM70_ADDRESS_ARRAYSIZE_SURFACES;
      m_pRoomIdArray =      GM70_ADDRESS_ARRAY_ROOMIDS;
      m_pRoomCount =        GM70_ADDRESS_PTR_ROOMCOUNT;

      m_pFormMain =         GM70_ADDRESS_FORM_TRUNNER;
      m_pFormDebug =        GM70_ADDRESS_FORM_TDEBUG;
      m_pFormScore =        GM70_ADDRESS_FORM_TSCORE;

      m_pCurrentRoom =   GM70_ADDRESS_PTR_CURRENTROOM;
      m_pGlobalVarList = GM70_ADDRESS_PTR_GLOBALVARLIST;

      m_pPatchIdTypeCheck =     GM70_ADDRESS_PATCH_IDENTIFIERTYPECHECKING;
      m_pPatchDataIdTypeCheck = GM70_PATCH_IDENTIFIERTYPECHECKING;

      Properties.m_pGameId =          GM70_ADDRESS_PROPERTY_GAMEID;
      Properties.m_pTempDirectory =   GM70_ADDRESS_PROPERTY_TEMPDIRECTORY;
      Properties.m_pFps =             GM70_ADDRESS_PROPERTY_FPS;
      Properties.m_pRoom =            GM70_ADDRESS_PROPERTY_ROOM;
      Properties.m_pScore =           GM70_ADDRESS_PROPERTY_SCORE;
      Properties.m_pLives =           GM70_ADDRESS_PROPERTY_LIVES;
      Properties.m_pHealth =          GM70_ADDRESS_PROPERTY_HEALTH;
      Properties.m_pShowScore =       GM70_ADDRESS_PROPERTY_SHOWSCORE;
      Properties.m_pShowLives =       GM70_ADDRESS_PROPERTY_SHOWLIVES;
      Properties.m_pShowHealth =      GM70_ADDRESS_PROPERTY_SHOWHEALTH;
      Properties.m_pEventType =       GM70_ADDRESS_PROPERTY_EVENTTYPE;
      Properties.m_pEventNumber =     GM70_ADDRESS_PROPERTY_EVENTNUMBER;
      Properties.m_pEventObject =     GM70_ADDRESS_PROPERTY_EVENTOBJECT;
      Properties.m_pEventAction =     GM70_ADDRESS_PROPERTY_EVENTACTION;
      Properties.m_pErrorLast =       GM70_ADDRESS_PROPERTY_ERRORLAST;
      Properties.m_pErrorOccured =    GM70_ADDRESS_PROPERTY_ERROROCCURED;
      Properties.m_pKeyboardKey =     GM70_ADDRESS_PROPERTY_KEYBOARDKEY;
      Properties.m_pKeyboardLastKey = GM70_ADDRESS_PROPERTY_KEYBOARDLASTKEY;
      Properties.m_pKeyboardString =  GM70_ADDRESS_PROPERTY_KEYBOARDSTRING;
      Properties.m_pMouseButton =     GM70_ADDRESS_PROPERTY_MOUSEBUTTON;
      Properties.m_pMouseLastButton = GM70_ADDRESS_PROPERTY_MOUSELASTBUTTON;
      Properties.m_pViewCurrent =     GM70_ADDRESS_PROPERTY_VIEWCURRENT;
      Properties.m_pTransitionKind =  GM70_ADDRESS_PROPERTY_TRANSITIONKIND;
      Properties.m_pTransitionSteps = GM70_ADDRESS_PROPERTY_TRANSITIONSTEPS;
      Properties.m_pCursorSprite =    GM70_ADDRESS_PROPERTY_CURSORSPRITE;

    } else if ( m_gmVersion == GM_VERSION_61 ) {

      m_pFunctionData =     GM61_ADDRESS_ARRAY_GMFUNCTIONS;
      m_pSurfaces =         GM61_ADDRESS_ARRAY_SURFACES;
      m_pTextures =         GM61_ADDRESS_ARRAY_TEXTURES;
      m_pDirect3dData =     GM61_ADDRESS_STORAGE_DIRECTX;
      m_pScriptData =       GM61_ADDRESS_STORAGE_SCRIPTS;
      m_pSoundData =        GM61_ADDRESS_STORAGE_SOUNDS;
      m_pFontData =         GM61_ADDRESS_STORAGE_FONTS;
      m_pSpriteData =       GM61_ADDRESS_STORAGE_SPRITES;
      m_pBackgroundData =   GM61_ADDRESS_STORAGE_BACKGROUNDS;
      m_pParticleData =     GM61_ADDRESS_STORAGE_PARTICLES;
      m_pSurfaceArraySize = GM61_ADDRESS_ARRAYSIZE_SURFACES;
      m_pRoomIdArray =      GM61_ADDRESS_ARRAY_ROOMIDS;
      m_pRoomCount =        GM61_ADDRESS_PTR_ROOMCOUNT;

      m_pFormMain =         GM61_ADDRESS_FORM_TRUNNER;
      m_pFormDebug =        GM61_ADDRESS_FORM_TDEBUG;
      m_pFormScore = NULL;

      m_pCurrentRoom =         GM61_ADDRESS_PTR_CURRENTROOM;
      m_pGlobalVarList =       GM61_ADDRESS_PTR_GLOBALVARLIST;

      Properties.m_pGameId =          GM61_ADDRESS_PROPERTY_GAMEID;
      Properties.m_pTempDirectory =   GM61_ADDRESS_PROPERTY_TEMPDIRECTORY;
      Properties.m_pFps =             GM61_ADDRESS_PROPERTY_FPS;
      Properties.m_pRoom =            GM61_ADDRESS_PROPERTY_ROOM;
      Properties.m_pScore =           GM61_ADDRESS_PROPERTY_SCORE;
      Properties.m_pLives =           GM61_ADDRESS_PROPERTY_LIVES;
      Properties.m_pHealth =          GM61_ADDRESS_PROPERTY_HEALTH;
      Properties.m_pShowScore =       GM61_ADDRESS_PROPERTY_SHOWSCORE;
      Properties.m_pShowLives =       GM61_ADDRESS_PROPERTY_SHOWLIVES;
      Properties.m_pShowHealth =      GM61_ADDRESS_PROPERTY_SHOWHEALTH;
      Properties.m_pEventType =       GM61_ADDRESS_PROPERTY_EVENTTYPE;
      Properties.m_pEventNumber =     GM61_ADDRESS_PROPERTY_EVENTNUMBER;
      Properties.m_pEventObject =     GM61_ADDRESS_PROPERTY_EVENTOBJECT;
      Properties.m_pEventAction =     GM61_ADDRESS_PROPERTY_EVENTACTION;
      Properties.m_pErrorLast =       GM61_ADDRESS_PROPERTY_ERRORLAST;
      Properties.m_pErrorOccured =    GM61_ADDRESS_PROPERTY_ERROROCCURED;
      Properties.m_pKeyboardKey =     GM61_ADDRESS_PROPERTY_KEYBOARDKEY;
      Properties.m_pKeyboardLastKey = GM61_ADDRESS_PROPERTY_KEYBOARDLASTKEY;
      Properties.m_pKeyboardString =  GM61_ADDRESS_PROPERTY_KEYBOARDSTRING;
      Properties.m_pMouseButton =     GM61_ADDRESS_PROPERTY_MOUSEBUTTON;
      Properties.m_pMouseLastButton = GM61_ADDRESS_PROPERTY_MOUSELASTBUTTON;
      Properties.m_pViewCurrent =     GM61_ADDRESS_PROPERTY_VIEWCURRENT;

    }
  }

  void CGMAPI::RetrieveFunctionPointers() {
    for ( int i = 0; i < GM_FUNCTION_COUNT; i++ )
      m_gmFunctions[i] = GetGMFunctionAddress( GM_FUNCTION_NAMES[i] );
  }

  GMFUCTION CGMAPI::GetGMFunctionAddress( const char* aFunctionName ) {
    int NAME_MAX = sizeof( m_pFunctionData->functions->name );

    int strLength = strlen( aFunctionName );

    if ( strLength <= NAME_MAX ) {
      for ( DWORD i = 0; i < m_pFunctionData->functionCount; i++ ) {
        if ( strLength != m_pFunctionData->functions[i].nameLength )
          continue;

        if ( strcmp( aFunctionName, m_pFunctionData->functions[i].name ) == 0 )
          return (GMFUCTION) m_pFunctionData->functions[i].address;
      }
    }

    return NULL;
  }

  void CGMAPI::EnumerateInstances( INSTANCEENUMPROC aInstanceEnumProc, void* aParam ) {
    BYTE* roomPtr = (BYTE*) GetCurrentRoomPtr();
    int instanceArraySize = *((DWORD*) (roomPtr + 0x68));
    GMINSTANCE** instanceArray = *((GMINSTANCE***) (roomPtr + 0x6C));

    if ( !aInstanceEnumProc || !instanceArray )
      return;

    for ( int i = 0; i < instanceArraySize; i++ ) {
      if ( instanceArray[i] )
        if ( !aInstanceEnumProc( *(instanceArray[i]), aParam ) )
          break;
    }
  }

  void CGMAPI::With( int aId, bool aCheckInheritance, bool aIncludeDeactivated, WITHPROC aProc, void* aParam ) {
    BYTE* roomPtr = (BYTE*) GetCurrentRoomPtr();
    int instanceArraySize = *((DWORD*) (roomPtr + 0x68));
    GMINSTANCE** instanceArray = *((PGMINSTANCE**) (roomPtr + 0x6C));

    if ( !aProc || !instanceArray || aId <= gm::noone || aId == gm::other )
      return;

    GMINSTANCE* previousInstance = GetCurrentInstancePtr(),
              * currentInstance = NULL;

    if ( aId >= 0 ) {
      if ( aId < 100000 ) { // Object
        for ( int i = 0; i < instanceArraySize; i++ ) {
          currentInstance = instanceArray[i];

          if ( currentInstance ) {
            if ( currentInstance->object_index == aId ) {
              if ( aIncludeDeactivated || !currentInstance->deactivated ) {
                SetCurrentInstance( currentInstance );
                aProc( aParam );
              }
            } else if ( aCheckInheritance ) {
              if ( object_is_ancestor( currentInstance->object_index, aId ) ) {
                SetCurrentInstance( currentInstance );
                aProc( aParam );
              }
            }
          }
        }
      } else { // Instance
        currentInstance = GetInstancePtr( aId );
        if ( currentInstance ) {
          SetCurrentInstance( currentInstance );
          aProc( aParam );
        }
      }
    } else if ( aId >= -3 ) { // GM keyword
      if ( aId == gm::self ) {
        aProc( aParam );
        return;
      } else if ( aId == gm::all ) {
        for ( int i = 0; i < instanceArraySize; i++ ) {
          currentInstance = instanceArray[i];

          if ( currentInstance ) {
            SetCurrentInstance( currentInstance );
            aProc( aParam );
          }
        }
      }
    }

    SetCurrentInstance( previousInstance );
  }

  int CGMAPI::GetSymbolID( const char* aSymbol ) {
    CGMVariable delphiString( aSymbol );
    int id = core::RunnerFindSymbolID( delphiString.c_str() );

    if ( id < 10000 || id >= 100000 + m_pScriptData->symbolCount )
      id = 0;

    return id;
  }

  PGMVARIABLE CGMAPI::GetLocalVariablePtr( int aInstanceId, int aSymbolId ) {
    GMINSTANCE* instance = NULL;

    if ( aInstanceId == self )
      instance = GetCurrentInstancePtr();
    else if ( aInstanceId >= 100000 )
      instance = GetInstancePtr( aInstanceId );
    else
      return NULL;

    if ( aSymbolId >= 10000 && instance )
      return GetLocalVariablePtr( instance, aSymbolId );

    return NULL;
  }

  PGMVARIABLE CGMAPI::GetLocalVariablePtr( PGMINSTANCE aInstancePtr, int aSymbolId ) {
    if ( aSymbolId >= 10000 && aInstancePtr ) {
      GMVARIABLE* varArray = aInstancePtr->variableListPtr->variables;
      int varCount = aInstancePtr->variableListPtr->count;

      for ( int i = 0; i < varCount; i++ ) {
        if ( varArray[i].symbolId == aSymbolId )
          return (PGMVARIABLE) (varArray + i);
      }
    }

    return NULL;
  }

  PGMVARIABLE CGMAPI::GetGlobalVariablePtr( int aSymbolId ) {
    if ( aSymbolId >= 10000 ) {
      GMVARIABLE* varArray = (GMVARIABLE*) GetGlobalVariableListPtr()->variables;
      int varCount = GetGlobalVariableListPtr()->count;

      for ( int i = 0; i < varCount; i++ ) {
        if ( varArray[i].symbolId == aSymbolId )
          return (PGMVARIABLE) (varArray + i);
      }
    }

    return NULL;
  }

  void CGMAPI::GMFunctionRegister( const char* aName, int aNumberOfArguments, GMFUCTION aFunction ) {
    int requestedLength = strlen( aName );

    if ( requestedLength > 67 )
      return;

    if ( GetGMFunctionAddress( aName ) ) {
      GMFUNCTIONINFO* functions = m_pFunctionData->functions;
      int functionCount = m_pFunctionData->functionCount;

      for ( int i = 0; i < functionCount; i++ ) {
        if ( requestedLength != functions[i].nameLength )
          continue;

        if ( strcmp( aName, functions[i].name ) == 0 ) {
          functions[i].address = aFunction;

          if ( aNumberOfArguments > -2 )
            functions[i].argumentNumber = aNumberOfArguments;
          return;
        }
      }
    } else {
      CGMVariable delphiString( aName );
      RunnerGMFunctionAdd( delphiString.c_str(), aNumberOfArguments, aFunction );
    }
  }

  PFUNCTIONDATA CGMAPI::PreserveFunctionData() {
    PFUNCTIONDATA functionData = new FUNCTIONDATA;
    GMFUNCTIONINFO* functions = new GMFUNCTIONINFO[m_pFunctionData->functionCount];
    if ( m_pFunctionData->functions )
      memcpy( functions, m_pFunctionData->functions, sizeof( GMFUNCTIONINFO ) * m_pFunctionData->functionCount );

    functionData->functionCount = m_pFunctionData->functionCount;
    functionData->functions = functions;
    return functionData;
  }

  void CGMAPI::RestoreFunctionData( PFUNCTIONDATA aData ) {
    if ( m_pFunctionData->functions )
      memcpy( m_pFunctionData->functions, aData->functions, sizeof( GMFUNCTIONINFO ) * m_pFunctionData->functionCount );

    delete [] aData->functions;
    delete aData;
  }

  void CGMAPI::PatchIdentifierTypeCheckOrder() {
    if ( GetGMVersion() == GM_VERSION_61 )
      return;

    DWORD oldProtect;
    VirtualProtect( m_pPatchIdTypeCheck, 
                    GM_PATCHSIZE_IDENTIFIERTYPECHECKING,
                    PAGE_EXECUTE_READWRITE,
                    &oldProtect );

    memcpy( m_pPatchIdTypeCheck, 
            m_pPatchDataIdTypeCheck,
           GM_PATCHSIZE_IDENTIFIERTYPECHECKING );

    VirtualProtect( m_pPatchIdTypeCheck,
                    GM_PATCHSIZE_IDENTIFIERTYPECHECKING,
                    oldProtect,
                    &oldProtect );

    FlushInstructionCache( GetCurrentProcess(),
                           m_pPatchIdTypeCheck,
                           GM_PATCHSIZE_IDENTIFIERTYPECHECKING );
  }

  int CGMAPI::ResourceFindID( const char* aName, char** aResourceNames, int aArraySize ) {
    if ( aResourceNames ) {
      int nameLength = strlen( aName );

      for ( int i = 0; i < aArraySize; i++ ) {
        if ( !aResourceNames[i] )
          continue;

        if ( nameLength != *((int*) aResourceNames[i] - 1) )
          continue;

        if ( strcmp( aName, aResourceNames[i] ) == 0 )
          return i;
      }
    }

    return -1;
  }

  int CGMAPI::ResourceGetCount( void** aResourceInstances, int aArraySize ) {
    if ( !aResourceInstances )
      return 0;

    int count = 0;

    for ( int i = 0; i < aArraySize; i++ )
      if ( aResourceInstances[i] )
        ++count;

    return count;
  }

  unsigned long CGMAPI::GetBitmapSize( GMBITMAP* aBitmap ) {
    if ( CGlobals::UseNewStructs() ) {
      return aBitmap->structNew.width * aBitmap->structNew.height * 4;
    } else
      return aBitmap->structOld.width * aBitmap->structOld.height * 4;
  }

  HWND CGMAPI::GetMainWindowHandle() {
    if ( !*m_pFormMain )
      return NULL;

    return (*m_pFormMain)[( GetGMVersion() == GM_VERSION_80 ? 109 : 12)];
  }

  HWND CGMAPI::GetDebugWindowHandle() {
    if ( !*m_pFormDebug )
      return NULL;

    return (*m_pFormDebug)[( GetGMVersion() == GM_VERSION_80 ? 109 : 96)];
  }

  HWND CGMAPI::GetHighscoreWindowHandle() {
    if ( !*m_pFormScore )
      return NULL;

    return (*m_pFormScore)[( GetGMVersion() == GM_VERSION_80 ? 109 : 46)];
  }

  /************************************************************************/
  /* Exceptions                                                           */
  /************************************************************************/

  void EGMAPISpriteNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
              "%s:\n%s\n\n%s:\nSprite ID: %d",
              STR_GMAPI_ERROR, STR_EXC_SPRITENOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );

    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIInvalidSubimage::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];
    const char* spriteName = STR_GMAPI_NOACCESS;

    if ( CGMAPI::Ptr() )
      if ( CGMAPI::Ptr()->Sprites.Exists( m_resourceId ) )
        spriteName = CGMAPI::Ptr()->Sprites[m_resourceId].GetName();

    sprintf_s( buffer, sizeof( buffer ),
               "%s:\n%s\n\n%s:\nSprite: %s (ID: %d)\nSubimage: %d",
               STR_GMAPI_ERROR, STR_EXC_INVALIDSUBIMAGE, STR_GMAPI_DEBUG,
               spriteName, m_resourceId, m_subimage );
    
    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIBackgroundNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
              "%s:\n%s\n\n%s:\nBackground ID: %d",
              STR_GMAPI_ERROR, STR_EXC_BACKGROUNDNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );
    
    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIScriptNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
              "%s:\n%s\n\n%s:\nScript ID: %d",
              STR_GMAPI_ERROR, STR_EXC_SCRIPTNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );
    
    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPISoundNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
              "%s:\n%s\n\n%s:\nSound ID: %d",
              STR_GMAPI_ERROR, STR_EXC_SOUNDNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );
    
    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPISurfaceNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
              "%s:\n%s\n\n%s:\nSurface ID: %d",
              STR_GMAPI_ERROR, STR_EXC_SURFACENOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );
    
    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIFontNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
               "%s:\n%s\n\n%s:\nFont ID: %d",
               STR_GMAPI_ERROR, STR_EXC_FONTNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );

    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIParticleSystemNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
               "%s:\n%s\n\n%s:\nParticle system ID: %d",
               STR_GMAPI_ERROR, STR_EXC_PARTICLESYSTEMNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );

    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIParticleTypeNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
               "%s:\n%s\n\n%s:\nParticle type ID: %d",
               STR_GMAPI_ERROR, STR_EXC_PARTICLETYPENOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );

    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIDeflectorNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
               "%s:\n%s\n\n%s:\nDeflector ID: %d",
               STR_GMAPI_ERROR, STR_EXC_DEFLECTORNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );

    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIAttractorNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
               "%s:\n%s\n\n%s:\nAttractor ID: %d",
               STR_GMAPI_ERROR, STR_EXC_ATTRACTORNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );

    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIDestroyerNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
               "%s:\n%s\n\n%s:\nDestroyer ID: %d",
               STR_GMAPI_ERROR, STR_EXC_DESTROYERNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );

    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIChangerNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
               "%s:\n%s\n\n%s:\nChanger ID: %d",
               STR_GMAPI_ERROR, STR_EXC_CHANGERNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );

    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIEmitterNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
               "%s:\n%s\n\n%s:\nEmitter ID: %d",
               STR_GMAPI_ERROR, STR_EXC_EMITTERNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );

    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  /************************************************************************/
  /* Operator overloading                                                 */
  /************************************************************************/

  std::ostream& operator<<( std::ostream& aStream, const CGMVariable& aValue ) {
    if ( aValue.IsString() )
      aStream << aValue.c_str();
    else
      aStream << aValue.real();

    return aStream;
  }

  std::ostream& operator<<( std::ostream& aStream, const GMVALUE& aValue ) {
    if ( aValue.type == VT_REAL )
      aStream << aValue.real;
    else
      aStream << aValue.string;

    return aStream;
  }

  /************************************************************************/
  /* CGMVariable class implementation                                     */
  /************************************************************************/

  CGMVariable::CGMVariable( const GMVALUE& aValue ): m_real( 0.0 ),
                                                     m_stringPtr( NULL ),
                                                     m_stringDispose( true ) {
    m_isString = ( aValue.type == VT_STRING );
    *this = aValue;
  }

  void CGMVariable::StringSet( const char* aValue ) {
    if ( !m_stringPtr ) 
      m_stringPtr = DelphiStringAllocate();

    DelphiStringSetFromPChar( aValue, m_stringPtr );
  }

  void CGMVariable::StringClear() {
    if ( m_stringPtr )
      DelphiStringClear( m_stringPtr );
  }

  void CGMVariable::StringDeallocate() {
    if ( m_stringPtr ) {
      DelphiStringDeallocate( m_stringPtr );
      m_stringPtr = NULL;
    }
  }

  CGMVariable& CGMVariable::operator=( const GMVALUE& aValue ) {
    if ( aValue.type ) {
      Set( aValue.string );
    } else
      Set( aValue.real );

    return *this;
  }

  /************************************************************************/
  /* GMVALUE structure operator overloading                               */
  /************************************************************************/

  GMVALUE& GMVALUE::operator=( double aValue ) {
    ZeroMemory( this, sizeof( GMVALUE ) );
    type = VT_REAL;
    real = aValue;

    return *this;
  }

  GMVALUE& GMVALUE::operator=( const char* aValue ) {
    ZeroMemory( this, sizeof( GMVALUE ) );
    type = VT_STRING;
    string = aValue;

    return *this;
  }

  GMVALUE& GMVALUE::operator=( const CGMVariable& aValue ) {
    ZeroMemory( this, sizeof( GMVALUE ) );

    if ( aValue.IsString() )
      string = aValue.c_str();
    else
      real = aValue.real();

    type = (GMValueType) aValue.IsString();
    return *this;
  }

  GMVARIABLE& GMVARIABLE::operator=( double aValue ) {
    type = VT_REAL;
    real = aValue;

    return *this;
  }

  /************************************************************************/
  /* GMVARIABLE structure operator overloading                            */
  /************************************************************************/

  GMVARIABLE& GMVARIABLE::operator=( const char* aValue ) {
    type = VT_STRING;
    string = aValue;

    return *this;
  }

  GMVARIABLE& GMVARIABLE::operator=( const CGMVariable& aValue ) {
    if ( aValue.IsString() )
      string = aValue.c_str();
    else
      real = aValue.real();

    type = (GMValueType) aValue.IsString();
    return *this;
  }

  /************************************************************************/
  /* ISprites interface implementation                                    */
  /************************************************************************/

  bool ISprites::Exists( int aSpriteId ) {
    if ( aSpriteId >= GetArraySize() || aSpriteId < 0 || !CGMAPI::SpriteData()->sprites )
      return false;
    else
      return ( CGMAPI::SpriteData()->sprites[aSpriteId] != NULL );
  }

  int ISprites::GetID( const char* aSpriteName ) {
    return CGMAPI::ResourceFindID( aSpriteName, CGMAPI::SpriteData()->names, GetArraySize() );
  }

  int ISprites::GetCount() {
    return CGMAPI::ResourceGetCount( (void**) CGMAPI::SpriteData()->sprites, GetArraySize() );
  }

  int ISprite::GetWidth() {
    if ( CGlobals::UseNewStructs() ) {
      if ( !m_sprite->structNew.bitmaps )
        return 0;
      else
        return m_sprite->structNew.bitmaps[0]->structNew.width;
    } else
      return m_sprite->structOld.width;
  }

  int ISprite::GetHeight() {
    if ( CGlobals::UseNewStructs() ) {
      if ( !m_sprite->structNew.bitmaps )
        return 0;
      else
        return m_sprite->structNew.bitmaps[0]->structNew.height;
    } else
      return m_sprite->structOld.height;
  }

  void ISprite::SetOffset( int aOffsetX, int aOffsetY ) {
    if ( CGlobals::UseNewStructs() ) {
      m_sprite->structNew.originX = aOffsetX;
      m_sprite->structNew.originY = aOffsetY;
    } else {
      m_sprite->structOld.originX = aOffsetX;
      m_sprite->structOld.originY = aOffsetY;
    }
  }

  void ISprite::SetBoundingBox( int aLeft, int aRight, int aTop, int aBottom ) {
    if ( CGlobals::UseNewStructs() ) {
      m_sprite->structNew.bboxLeft = aLeft;
      m_sprite->structNew.bboxRight = aRight;
      m_sprite->structNew.bboxTop = aTop;
      m_sprite->structNew.bboxBottom = aBottom;
    } else {
      m_sprite->structOld.bboxLeft = aLeft;
      m_sprite->structOld.bboxRight = aRight;
      m_sprite->structOld.bboxTop = aTop;
      m_sprite->structOld.bboxBottom = aBottom;
    }
  }

  /************************************************************************/
  /* IBackgrounds interface implementation                                */
  /************************************************************************/

  bool IBackgrounds::Exists( int aBackgroundId ) {
    if ( aBackgroundId >= GetArraySize() || aBackgroundId < 0 || !CGMAPI::BackgroundData()->backgrounds )
      return false;
    else
      return ( CGMAPI::BackgroundData()->backgrounds[aBackgroundId] != NULL );
  }

  int IBackgrounds::GetID( const char* aBackgroundName ) {
    return CGMAPI::ResourceFindID( aBackgroundName, CGMAPI::BackgroundData()->names, GetArraySize() );
  }

  int IBackgrounds::GetCount() {
    return CGMAPI::ResourceGetCount( (void**) CGMAPI::BackgroundData()->backgrounds, GetArraySize() );
  }

  /************************************************************************/
  /* IBackground interface implementation                                 */
  /************************************************************************/

  int IBackground::GetHeight() {
    if ( CGlobals::UseNewStructs() ) {
      if ( m_background->structNew.bitmap )
        return m_background->structNew.bitmap->structNew.height;
      else 
        return 0;
    } else
      return m_background->structOld.height;
  }

  int IBackground::GetWidth() {
    if ( CGlobals::UseNewStructs() ) {
      if ( m_background->structNew.bitmap )
        return m_background->structNew.bitmap->structNew.width;
      else 
        return 0;
    } else
      return m_background->structOld.width;
  }

  unsigned long IBackground::GetBitmapSize() {
    return CGMAPI::GetBitmapSize( ( CGlobals::UseNewStructs() ? m_background->structNew.bitmap :
                                                                m_background->structOld.bitmap ) );
  }

  const char* IBackground::GetName() {
    return CGMAPI::BackgroundData()->names[m_backgroundId];
  }

  unsigned char* IBackground::GetBitmap() {
    return ( CGlobals::UseNewStructs() ? m_background->structNew.bitmap->structNew.bits :
                                         m_background->structOld.bitmap->structOld.bits );
  }

  int IBackground::GetTextureID() {
    return ( CGlobals::UseNewStructs() ? m_background->structNew.textureId :
                                         m_background->structOld.textureId );
  }

  /************************************************************************/
  /* ISurfaces interface implementation                                   */
  /************************************************************************/

  int ISurfaces::GetCount() {
    if ( !CGMAPI::GetSurfaceArray() )
      return 0;

    int count = 0;

    for ( int i = 0; i < GetArraySize(); i++ ) {
      if ( CGMAPI::GetSurfaceArray()[i].exists )
        ++count;
    }

    return count;
  }

  /************************************************************************/
  /* IScripts interface implementation                                    */
  /************************************************************************/

  int IScripts::GetCount() {
    return CGMAPI::ResourceGetCount( (void**) CGMAPI::ScriptData()->scripts, GetArraySize() );
  }

  int IScripts::GetID( const char* aScriptName ) {
    return CGMAPI::ResourceFindID( aScriptName, CGMAPI::ScriptData()->names, GetArraySize() );
  }

  /************************************************************************/
  /* IScript interface implementation                                     */
  /************************************************************************/

  char* IScript::GetScript( char* aBuffer ) {
    unsigned long scrLength = GetScriptLength();
    char* script;

    if ( CGlobals::UseNewStructs() ) {
      script = CGMAPI::ScriptData()->scripts[m_scriptId]->structNew.debugInfo->code;
    } else
      script = CGMAPI::ScriptData()->scripts[m_scriptId]->structOld.debugInfo->code;

    memcpy( aBuffer, script, scrLength );

    if ( CGMAPI::GetGMVersion() >= GM_VERSION_70 ) {
      for ( unsigned long i = 0; i < scrLength; i++ )
        aBuffer[i] = CGMAPI::ScriptSwapTable()[ aBuffer[i] ];
    }

    return aBuffer;
  }

  unsigned long IScript::GetScriptLength() {
    if ( CGlobals::UseNewStructs() ) {
      return ((DWORD*) (CGMAPI::ScriptData()->scripts[m_scriptId]->structNew.debugInfo->code))[-1];
    } else
      return ((DWORD*) (CGMAPI::ScriptData()->scripts[m_scriptId]->structOld.debugInfo->code))[-1];
  }

  /************************************************************************/
  /* ISounds interface implementation                                     */
  /************************************************************************/

  int ISounds::GetCount() {
    return CGMAPI::ResourceGetCount( (void**) CGMAPI::SoundData()->sounds, GetArraySize() );
  }

  int ISounds::GetID( const char* aSoundName ) {
    return CGMAPI::ResourceFindID( aSoundName, CGMAPI::SoundData()->names, GetArraySize() );
  }

  /************************************************************************/
  /* IFonts interface implementation                                      */
  /************************************************************************/

  int IFonts::GetCount() {
    return CGMAPI::ResourceGetCount( (void**) CGMAPI::FontData()->fonts, GetArraySize() );
  }

  int IFonts::GetID( const char* aFontName ) {
    return CGMAPI::ResourceFindID( aFontName, CGMAPI::FontData()->names, GetArraySize() );
  }

  /************************************************************************/
  /* IParticleTypes interface implementation                              */
  /************************************************************************/

  int IParticleTypes::GetCount() {
    int count = 0;

    for ( int i = 0; i < GetArraySize(); i++ ) {
      if ( CGMAPI::ParticleData()->particleTypes[i].isValid )
        ++count;
    }

    return count;
  }

  /************************************************************************/
  /* IParticleSystems interface implementation                            */
  /************************************************************************/

  int IParticleSystems::GetCount() {
    int count = 0;

    for ( int i = 0; i < GetArraySize(); i++ ) {
      if ( CGMAPI::ParticleData()->particleSystems[i].isValid )
        ++count;
    }

    return count;
  }

  /************************************************************************/
  /* IParticleSystem interface implementation                             */
  /************************************************************************/

  void IParticleSystem::EnumerateParticles( PARTICLEENUMPROC aParticleEnumProc, void* aParam ) {
    GMPARTICLE* particles = CGMAPI::ParticleData()->particleSystems[m_particleSystemId].particles;
    int arraySize = GetParticleCount();

    if ( !particles )
      return;

    for ( int i = 0; i < arraySize; i++ ) {
      if ( particles[i].isValid ) {
        if ( !aParticleEnumProc( particles[i], aParam ) )
          return;
      }
    }
  }

  /************************************************************************/
  /* IEmitters interface implementation                                   */
  /************************************************************************/

  int IEmitters::GetCount() {
    int count = 0;

    for ( int i = 0; i < GetArraySize(); i++ ) {
      if ( IParticleSystem::GetPtr()->emitters[i].isValid )
        ++count;
    }

    return count;
  }

  /************************************************************************/
  /* IAttractors interface implementation                                 */
  /************************************************************************/

  int IAttractors::GetCount() {
    int count = 0;

    for ( int i = 0; i < GetArraySize(); i++ ) {
      if ( IParticleSystem::GetPtr()->attractors[i].isValid )
        ++count;
    }

    return count;
  }

  /************************************************************************/
  /* IDeflectors interface implementation                                 */
  /************************************************************************/

  int IDeflectors::GetCount() {
    int count = 0;

    for ( int i = 0; i < GetArraySize(); i++ ) {
      if ( IParticleSystem::GetPtr()->deflectors[i].isValid )
        ++count;
    }

    return count;
  }

  /************************************************************************/
  /* IDestroyers interface implementation                                 */
  /************************************************************************/

  int IDestroyers::GetCount() {
    int count = 0;

    for ( int i = 0; i < GetArraySize(); i++ ) {
      if ( IParticleSystem::GetPtr()->destroyers[i].isValid )
        ++count;
    }

    return count;
  }

  /************************************************************************/
  /* IChangers interface implementation                                   */
  /************************************************************************/

  int IChangers::GetCount() {
    int count = 0;

    for ( int i = 0; i < GetArraySize(); i++ ) {
      if ( IParticleSystem::GetPtr()->changers[i].isValid )
        ++count;
    }

    return count;
  }

  /************************************************************************/
  /* IProperties interface implementation                                 */
  /************************************************************************/

  void IProperties::SetRoomCaption( const char* aCaption ) {
    core::DelphiStringSetFromPChar( aCaption, ((const char**) CGMAPI::GetCurrentRoomPtr()) + 1 );
  }

  void IProperties::SetKeyboardString( const char* aString ) {
    core::DelphiStringSetFromPChar( aString, m_pKeyboardString );
  }

  bool IProperties::GetBackgroundVisible( int aId ) {
    bool* backgroundDataPtr = (bool*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return false;

    return backgroundDataPtr[4];
  }

  bool IProperties::GetBackgroundForeground( int aId ) {
    bool* backgroundDataPtr = (bool*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return false;

    return backgroundDataPtr[5];
  }

  int IProperties::GetBackgroundIndex( int aId ) {
    int* backgroundDataPtr = (int*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return 0;

    return backgroundDataPtr[2];
  }
  
  double IProperties::GetBackgroundX( int aId ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return 0;

    return backgroundDataPtr[2];
  }

  double IProperties::GetBackgroundY( int aId ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return 0;

    return backgroundDataPtr[3];
  }

  bool IProperties::GetBackgroundHTiled( int aId ) {
    bool* backgroundDataPtr = (bool*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return false;

    return backgroundDataPtr[0x20];
  }

  bool IProperties::GetBackgroundVTiled( int aId ) {
    bool* backgroundDataPtr = (bool*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return false;

    return backgroundDataPtr[0x21];
  }

  double IProperties::GetBackgroundXScale( int aId ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return 0;

    return backgroundDataPtr[7];
  }

  double IProperties::GetBackgroundYScale( int aId ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return 0;

    return backgroundDataPtr[8];
  }

  double IProperties::GetBackgroundHSpeed( int aId ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return 0;

    return backgroundDataPtr[5];
  }

  double IProperties::GetBackgroundVSpeed( int aId ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return 0;

    return backgroundDataPtr[6];
  }

  int IProperties::GetBackgroundBlend( int aId ) {
    int* backgroundDataPtr = (int*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return 0;

    return backgroundDataPtr[18];
  }

  double IProperties::GetBackgroundAlpha( int aId ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return 0;

    return backgroundDataPtr[10];
  }

  void IProperties::SetBackgroundVisible( int aId, bool aVisible ) {
    bool* backgroundDataPtr = (bool*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[4] = aVisible;
  }

  void IProperties::SetBackgroundForeground( int aId, bool aForeground ) {
    bool* backgroundDataPtr = (bool*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[5] = aForeground;
  }

  void IProperties::SetBackgroundIndex( int aId, int aBackground ) {
    int* backgroundDataPtr = (int*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[2] = aBackground;
  }

  void IProperties::SetBackgroundX( int aId, double aX ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[2] = aX;
  }

  void IProperties::SetBackgroundY( int aId, double aY ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[3] = aY;
  }

  void IProperties::SetBackgroundHTiled( int aId, bool aTiled ) {
    bool* backgroundDataPtr = (bool*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[0x20] = aTiled;
  }

  void IProperties::SetBackgroundVTiled( int aId, bool aTiled ) {
    bool* backgroundDataPtr = (bool*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[0x21] = aTiled;
  }

  void IProperties::SetBackgroundXScale( int aId, double aScale ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[7] = aScale;
  }

  void IProperties::SetBackgroundYScale( int aId, double aScale ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[8] = aScale;
  }

  void IProperties::SetBackgroundHSpeed( int aId, double aSpeed ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[5] = aSpeed;
  }

  void IProperties::SetBackgroundVSpeed( int aId, double aSpeed ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[6] = aSpeed;
  }

  void IProperties::SetBackgroundBlend( int aId, int aColor ) {
    int* backgroundDataPtr = (int*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[18] = aColor;
  }

  void IProperties::SetBackgroundAlpha( int aId, double aAlpha ) {
    double* backgroundDataPtr = (double*) GetPointerToRoomBackgroundData( aId );
    if ( !backgroundDataPtr )
      return;

    backgroundDataPtr[10] = aAlpha;
  }

  bool IProperties::GetViewVisible( int aId ) {
    bool* viewDataPtr = (bool*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return false;

    return viewDataPtr[4];
  }

  int IProperties::GetViewXView( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[2];
  }

  int IProperties::GetViewYView( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[3];
  }

  int IProperties::GetViewWView( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[4];
  }

  int IProperties::GetViewHView( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[5];
  }

  int IProperties::GetViewXPort( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[6];
  }

  int IProperties::GetViewYPort( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[7];
  }

  int IProperties::GetViewWPort( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[8];
  }

  int IProperties::GetViewHPort( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[9];
  }

  double IProperties::GetViewAngle( int aId ) {
    double* viewDataPtr = (double*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[5];
  }

  int IProperties::GetViewHBorder( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[12];
  }

  int IProperties::GetViewVBorder( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[13];
  }

  int IProperties::GetViewHSpeed( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[14];
  }

  int IProperties::GetViewVSpeed( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[15];
  }

  int IProperties::GetViewObject( int aId ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return 0;

    return viewDataPtr[16];
  }

  void IProperties::SetViewVisible( int aId, bool aVisible ) {
    bool* viewDataPtr = (bool*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[4] = aVisible;
  }

  void IProperties::SetViewXView( int aId, int aX ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[2] = aX;
  }

  void IProperties::SetViewYView( int aId, int aY ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[3] = aY;
  }

  void IProperties::SetViewWView( int aId, int aWidth ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[4] = aWidth;
  }

  void IProperties::SetViewHView( int aId, int aHeight ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[5] = aHeight;
  }

  void IProperties::SetViewXPort( int aId, int aX ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[6] = aX;
  }

  void IProperties::SetViewYPort( int aId, int aY ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[7] = aY;
  }

  void IProperties::SetViewWPort( int aId, int aWidth ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[8] = aWidth;
  }

  void IProperties::SetViewHPort( int aId, int aHeight ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[9] = aHeight;
  }

  void IProperties::SetViewAngle( int aId, double aAngle ) {
    double* viewDataPtr = (double*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[5] = aAngle;
  }

  void IProperties::SetViewHBorder( int aId, int aWidth ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[12] = aWidth;
  }

  void IProperties::SetViewVBorder( int aId, int aWidth ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[13] = aWidth;
  }

  void IProperties::SetViewHSpeed( int aId, int aSpeed ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[14] = aSpeed;
  }

  void IProperties::SetViewVSpeed( int aId, int aSpeed ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[15] = aSpeed;
  }

  void IProperties::SetViewObject( int aId, int aObject ) {
    int* viewDataPtr = (int*) GetPointerToRoomViewData( aId );
    if ( !viewDataPtr )
      return;

    viewDataPtr[16] = aObject;
  }

  int IProperties::GetMouseX() {
    return window_views_mouse_get_x();
  }

  int IProperties::GetMouseY() {
    return window_views_mouse_get_y();
  }

  const char* IProperties::GetProgramDirectory() {
    char buffer[MAX_PATH];
    GetModuleFileNameA( NULL, buffer, MAX_PATH );

    m_tempString = buffer;
    m_tempString.erase( m_tempString.find_last_of( "\\/" ) );
    return m_tempString.c_str();
  }

  const char* IProperties::GetWorkingDirectory() {
    char buffer[MAX_PATH];
    GetCurrentDirectoryA( MAX_PATH, buffer );

    m_tempString = buffer;
    return m_tempString.c_str();
  }

}
