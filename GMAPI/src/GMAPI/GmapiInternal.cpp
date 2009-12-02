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

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiInternal.h"
#include "GmapiMacros.h"

#include "GmapiResources.h"


using namespace gm::core;

namespace gm {

  PGMFUNCTIONINFOSTORAGE  CGMAPI::m_functionData;
  PGMBACKGROUNDSTORAGE    CGMAPI::m_backgroundData;
  PGMSPRITESTORAGE        CGMAPI::m_spriteData;
  PGMSURFACE*             CGMAPI::m_surfaces;
  PGMTEXTURE*             CGMAPI::m_textures;
  PGMDIRECT3DINFO         CGMAPI::m_d3dInfo;
  PGMSCRIPTSTORAGE        CGMAPI::m_scriptData;
  PGMSOUNDSTORAGE         CGMAPI::m_soundData;

  PGMVARIABLELIST*        CGMAPI::m_globalVarListPtr;
  void**                  CGMAPI::m_currentRoomPtr;
  int*                    CGMAPI::m_surfaceArraySize;
  char*                   CGMAPI::m_scriptSwapTable;

  HWND                    CGMAPI::m_mainHwnd;
  HWND                    CGMAPI::m_debugHwnd;
  HWND                    CGMAPI::m_hScrHwnd;

  PGMSPRITE               ISprite::m_sprite;
  int                     ISprite::m_spriteId;
  int                     ISpriteSubimage::m_subimage;
  PGMBACKGROUND           IBackground::m_background;
  int                     IBackground::m_backgroundId;
  int                     ISurface::m_surfaceId;
  int                     IScript::m_scriptId;
  int                     ISound::m_soundId;

  /********************************************
   * CGMAPI class implementation
   ********************************************/

  CGMAPI* CGMAPI::m_self = NULL;
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

  CGMAPI::CGMAPI( bool* aSuccess ): m_gmVersion( 0 ) {
    m_gmVersion = GMAPIInitialize();

    if ( !m_gmVersion ) {
      *aSuccess = false;
      return;
    }

    GMAPIHookInstall();
    RetrieveDataPointers();
    RetrieveFunctionPointers();

    *aSuccess = true;
  }

  void CGMAPI::Destroy() {
    if ( m_self ) {
      delete m_self;
      m_self = NULL;
    }
  }

  CGMAPI::~CGMAPI() {
    GMAPIHookUninstall();
  }

  void CGMAPI::RetrieveDataPointers() {
    if ( m_gmVersion == GM_VERSION_70 ) {
      m_functionData =                   GM70_ADDRESS_ARRAY_GMFUNCTIONS;
      m_spriteData =                     GM70_ADDRESS_STORAGE_SPRITES;
      m_backgroundData =                 GM70_ADDRESS_STORAGE_BACKGROUNDS;
      m_surfaces =         (PGMSURFACE*) GM70_ADDRESS_ARRAY_SURFACES;
      m_textures =         (PGMTEXTURE*) GM70_ADDRESS_ARRAY_TEXTURES;
      m_d3dInfo =                        GM70_ADDRESS_STORAGE_D3D;
      m_scriptData =                     GM70_ADDRESS_STORAGE_SCRIPTS;
      m_soundData =                      GM70_ADDRESS_SOUND_STORAGE;

      m_scriptSwapTable =  (char*)       GM70_ADDRESS_ARRAY_SWAP_BYTES;
      m_surfaceArraySize = (int*)        GM70_ADDRESS_ARRAYSIZE_SURFACES;

      m_mainHwnd =  *(HWND*) (*GM70_ADDRESS_TRUNNER_INSTANCE + 0x30);
 
      if ( *GM70_ADDRESS_TDEBUG_INSTANCE )
        m_debugHwnd = *(HWND*) (*GM70_ADDRESS_TDEBUG_INSTANCE + 0x180);

      m_hScrHwnd =    *(HWND*) (*GM70_ADDRESS_TSCORE_INSTANCE + 0xB8);

      m_currentRoomPtr =   (void**)           GM70_ADDRESS_CURRENT_ROOM_PTR;
      m_globalVarListPtr = (PGMVARIABLELIST*) GM70_ADDRESS_GLOBAL_VARIABLE_LIST_PTR;

    } else if ( m_gmVersion == GM_VERSION_61 ) {

      m_functionData =                   GM61_ADDRESS_ARRAY_GMFUNCTIONS;
      m_spriteData =                     GM61_ADDRESS_STORAGE_SPRITES;
      m_backgroundData =                 GM61_ADDRESS_STORAGE_BACKGROUNDS;
      m_surfaces =         (PGMSURFACE*) GM61_ADDRESS_ARRAY_SURFACES;
      m_textures =         (PGMTEXTURE*) GM61_ADDRESS_ARRAY_TEXTURES;
      m_d3dInfo =                        GM61_ADDRESS_STORAGE_D3D;
      m_scriptData =                     GM61_ADDRESS_STORAGE_SCRIPTS;
      m_soundData =                      GM61_ADDRESS_SOUND_STORAGE;

      m_surfaceArraySize = (int*)        GM61_ADDRESS_ARRAYSIZE_SURFACES;

      m_mainHwnd  = *((HWND*) (*GM61_ADDRESS_TRUNNER_INSTANCE + 0x30));
      m_debugHwnd = *((HWND*) (*GM61_ADDRESS_TDEBUG_INSTANCE + 0x180));
      m_hScrHwnd = NULL; // Ptr to the handle is not valid until the highscore
                         // was showed at least once, so function
                         // GetHighscoreWindowHandle is not supported in GM6.1

      m_currentRoomPtr =   (void**)           GM61_ADDRESS_CURRENT_ROOM_PTR;
      m_globalVarListPtr = (PGMVARIABLELIST*) GM61_ADDRESS_GLOBAL_VARIABLE_LIST_PTR;

    }
  }

  void CGMAPI::RetrieveFunctionPointers() {
    for ( int i = 0; i < GM_FUNCTION_COUNT; i++ )
      m_gmFunctions[i] = GetGMFunctionAddress( GM_FUNCTION_NAMES[i] );
  }

  void* CGMAPI::GetGMFunctionAddress( const char* aFunctionName ) {
    const int NAME_MAX = sizeof( m_functionData->functions->name );

    int strLength = strlen( aFunctionName );

    if ( strLength <= NAME_MAX ) {
      for ( DWORD i = 0; i < m_functionData->nFunctions; i++ ) {
        if ( strLength != m_functionData->functions[i].nameLength )
          continue;

        if ( strcmp( aFunctionName, m_functionData->functions[i].name ) == 0 )
          return m_functionData->functions[i].address;
      }
    }

    return NULL;
  }

  void CGMAPI::EnumInstances( INSTANCEENUMPROC aInstanceEnumProc, void* aParam ) {
    BYTE* roomPtr = (BYTE*) GetCurrentRoomPtr();
    int instanceArraySize = *((DWORD*) (roomPtr + 0x68));
    GMINSTANCE** instanceArray = *((GMINSTANCE***) (roomPtr + 0x6C));

    if ( !aInstanceEnumProc || !instanceArray )
      return;

    for ( int i = 0; i < instanceArraySize; i++ ) {
      if ( instanceArray[i] )
        if ( !aInstanceEnumProc( instanceArray[i], aParam ) )
          break;
    }
  }

  void CGMAPI::With( int aId, bool aCheckInheritance, bool aIncludeDeactivated, WITHPROC aProc, void* aParam ) {
    BYTE* roomPtr = (BYTE*) GetCurrentRoomPtr();
    int instanceArraySize = *((DWORD*) (roomPtr + 0x68));
    GMINSTANCE** instanceArray = *((PGMINSTANCE**) (roomPtr + 0x6C));

    if ( !aProc || !instanceArray || aId <= noone || aId == other )
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
      if ( aId == self ) {
        aProc( aParam );
        return;
      } else if ( aId == all ) {
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
    int id = core::GMFindSymbolID( delphiString.c_str() );

    if ( id < 10000 || id >= 100000 + m_scriptData->symbolCount )
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

  /********************************************
   * Exceptions
   *******************************************/

  void EGMAPISpriteNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
              "%s:\n%s\n\n%s:\nSprite ID: %d",
              STR_GMAPI_ERROR, EXC_SPRITENOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );

    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIInvalidSubimage::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];
    const char* spriteName = STR_NO_ACCESS;

    if ( CGMAPI::Ptr() )
      if ( CGMAPI::Ptr()->Sprites.Exists( m_resourceId ) )
        spriteName = CGMAPI::Ptr()->Sprites[m_resourceId].GetName();

    sprintf_s( buffer, sizeof( buffer ),
               "%s:\n%s\n\n%s:\nSprite: %s (ID: %d)\nSubimage: %d",
               STR_GMAPI_ERROR, EXC_INVALIDSUBIMAGE, STR_GMAPI_DEBUG,
               spriteName, m_resourceId, m_subimage );
    
    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIBackgroundNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
              "%s:\n%s\n\n%s:\nBackground ID: %d",
              STR_GMAPI_ERROR, EXC_BACKGROUNDNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );
    
    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPIScriptNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
              "%s:\n%s\n\n%s:\nScript ID: %d",
              STR_GMAPI_ERROR, EXC_SCRIPTNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );
    
    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPISoundNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
              "%s:\n%s\n\n%s:\nSound ID: %d",
              STR_GMAPI_ERROR, EXC_SOUNDNOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );
    
    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  void EGMAPISurfaceNotExist::ShowError() const {
    HWND hwnd = ( CGMAPI::Ptr() ? CGMAPI::Ptr()->GetMainWindowHandle() : NULL );
    char buffer[0x200];

    sprintf_s( buffer, sizeof( buffer ),
              "%s:\n%s\n\n%s:\nSurface ID: %d",
              STR_GMAPI_ERROR, EXC_SURFACENOTEXISTS, STR_GMAPI_DEBUG, m_resourceId );
    
    MessageBoxA( hwnd, buffer, 0, MB_SYSTEMMODAL | MB_ICONERROR );
  }

  /********************************************
   * Operator overloading
   ********************************************/

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

  /********************************************
   * CGMVariable class implementation
   ********************************************/

  CGMVariable::CGMVariable( __in const GMVALUE& aValue ): m_real( 0.0 ),
                                                          m_ppStr( NULL ),
                                                          m_disposeStr( true ) {
    m_stringType = ( aValue.type == VT_STRING );
    *this = aValue;
  }

  void CGMVariable::StringSet( __in const char* aValue ) {
    if ( !m_ppStr ) 
      m_ppStr = GMAllocateString();

    GMSetString( aValue, m_ppStr );
  }

  void CGMVariable::StringClear() {
    if ( m_ppStr )
      GMClearString( m_ppStr );
  }

  void CGMVariable::StringDeallocate() {
    if ( m_ppStr ) {
      GMDeallocateString( m_ppStr );
      m_ppStr = NULL;
    }
  }

  CGMVariable& CGMVariable::operator=( const GMVALUE& aValue ) {
    if ( aValue.type ) {
      Set( aValue.string );
    } else
      Set( aValue.real );

    return *this;
  }

  /********************************************
   * GMVALUE structure operator overloading
   ********************************************/

  GMVALUE& GMVALUE::operator=( const double aValue ) {
    ZeroMemory( this, sizeof( GMVALUE ) );
    real = aValue;

    return *this;
  }

  GMVALUE& GMVALUE::operator=( char* aValue ) {
    ZeroMemory( this, sizeof( GMVALUE ) );
    type = VT_STRING;

    string = aValue;

    return *this;
  }

  GMVALUE& GMVALUE::operator=( const CGMVariable& aValue ) {
    ZeroMemory( this, sizeof( GMVALUE ) );

    if ( aValue.IsString() )
      string = (char*) aValue.c_str();
    else
      real = aValue.real();

    type = (GMValueType) aValue.IsString();
    return *this;
  }

  GMVARIABLE& GMVARIABLE::operator=( const double aValue ) {
    type = VT_REAL;
    real = aValue;

    return *this;
  }

  GMVARIABLE& GMVARIABLE::operator=( char* aValue ) {
    type = VT_STRING;
    string = aValue;

    return *this;
  }

  GMVARIABLE& GMVARIABLE::operator=( const CGMVariable& aValue ) {
    if ( aValue.IsString() )
      string = (char*) aValue.c_str();
    else
      real = aValue.real();

    type = (GMValueType) aValue.IsString();
    return *this;
  }

  /********************************************
   * ISprites interface implementation
   ********************************************/

  bool ISprites::Exists( const int aSpriteId ) {
    if ( aSpriteId >= GetArraySize() || aSpriteId < 0 ||
         !CGMAPI::SpriteData()->sprites )
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

  /********************************************
   * ISpriteSubimage interface implementation
   ********************************************/

  void ISpriteSubimage::ReleaseBitmap() {
    BYTE* pBmp = GetBitmap();

    if ( pBmp ) {
      core::GMDeallocateBitmap( pBmp );
      ISprite::SpritePtr()->bitmaps[m_subimage]->bitmapData = NULL;
    }
  }

  /********************************************
   * IBackgrounds interface implementation
   ********************************************/

  bool IBackgrounds::Exists( const int aBackgroundId ) {
    if ( aBackgroundId >= GetArraySize() || aBackgroundId < 0 ||
         !CGMAPI::BackgroundData()->backgrounds )
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

  /********************************************
   * IBackground interface implementation
   ********************************************/

  void IBackground::ReleaseBitmap() {
    BYTE* pBmp = GetBitmap();

    if ( pBmp ) {
      core::GMDeallocateBitmap( pBmp );
      m_background->bitmap->bitmapData = NULL;
    }
  }

  /********************************************
   * ISurfaces interface implementation
   ********************************************/

  int ISurfaces::GetCount() {
    if ( !CGMAPI::GetSurfaceArray() )
      return 0;

    int count = 0;

    for ( int i = 0; i < GetArraySize(); i++ )
      if ( CGMAPI::GetSurfaceArray()[i].exists )
        ++count;

    return count;
  }

  /********************************************
   * IScripts interface implementation
   ********************************************/

  int IScripts::GetCount() {
    return CGMAPI::ResourceGetCount( (void**) CGMAPI::ScriptData()->scripts, GetArraySize() );
  }

  int IScripts::GetID( const char* aScriptName ) {
    return CGMAPI::ResourceFindID( aScriptName, CGMAPI::ScriptData()->names, GetArraySize() );
  }

  /********************************************
   * IScript interface implementation
   ********************************************/

  char* IScript::GetScript( char* aBuffer ) {
    unsigned long scrLength = GetScriptLength();

    memcpy( aBuffer,
            CGMAPI::ScriptData()->scripts[m_scriptId]->debugInfo->code,
            scrLength );

    if ( CGMAPI::Ptr()->GetGMVersion() == GM_VERSION_70 )
      for ( unsigned long i = 0; i < scrLength; i++ )
        aBuffer[i] = CGMAPI::ScriptSwapTable()[ aBuffer[i] ];

    return aBuffer;
  }

  /********************************************
   * ISounds interface implementation
   ********************************************/

  int ISounds::GetCount() {
    return CGMAPI::ResourceGetCount( (void**) CGMAPI::SoundData()->sounds, GetArraySize() );
  }

  int ISounds::GetID( const char* aSoundName ) {
    return CGMAPI::ResourceFindID( aSoundName, CGMAPI::SoundData()->names, GetArraySize() );
  }

}
