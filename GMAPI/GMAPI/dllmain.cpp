/*#include <windows.h>
#include "gmapi.h"
#include <cmath>
#include <string>
#include <sstream>
//#include "GmapiCore.h"

#include <gdiplus.h>

#pragma warning( disable: 4127 )

using namespace gm;
CGMAPI* GMAPI;

BOOL APIENTRY DllMain( HMODULE hModule, DWORD reason, LPVOID lpReserved ) {
  hModule;reason;lpReserved;

  if ( reason == DLL_PROCESS_ATTACH ) {
    unsigned long result;
    GMAPI = CGMAPI::Create( &result );

    if ( result == GMAPI_INITIALIZATION_FAILED ) {
      MessageBox( 0, "Cannot initialize GMAPI", 0, 0 );
      return FALSE;
    }
  } else if ( reason == DLL_PROCESS_DETACH ) {
    CGMAPI::Destroy();
  }
  
	return 1;
}


short bmpWidth, bmpHeight;
HDC memHdc;
HBITMAP memBmp;
Gdiplus::Bitmap* bmp;
bool inverted = false;

ULONG_PTR gpToken;
HWND previewHwnd;

LRESULT CALLBACK PreviewProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam ) {
  switch ( msg ) {
    case WM_CREATE: {
      HDC hdc = GetDC( hwnd );

      memHdc = CreateCompatibleDC( hdc );
      memBmp = CreateCompatibleBitmap( hdc, 
                                       GetSystemMetrics( SM_CXSCREEN ),
                                       GetSystemMetrics( SM_CYSCREEN ) );

      SelectObject( memHdc, memBmp );
      ReleaseDC( hwnd, hdc );
      break;
    }

    case WM_PAINT: {
      Gdiplus::Graphics canvas( memHdc );

      Gdiplus::HatchBrush hb( Gdiplus::HatchStyleDivot,
                              (Gdiplus::ARGB) Gdiplus::Color::Gray,
                              (Gdiplus::ARGB) Gdiplus::Color::LightGray );

      canvas.FillRectangle( &hb, Gdiplus::Rect( 0, 0, bmpWidth, bmpHeight ) );
      canvas.DrawImage( bmp, 0, 0, bmpWidth, bmpHeight );

      PAINTSTRUCT ps;
      BitBlt( BeginPaint( hwnd, &ps ), 0, 0, bmpWidth, bmpHeight, memHdc, 0, 0, SRCCOPY );
      EndPaint( hwnd, &ps );
      break;
    }

    case WM_SIZE:
      bmpWidth = LOWORD( lParam );
      bmpHeight = HIWORD( lParam );

      InvalidateRect( hwnd, false, false );
      break;

    default: return DefWindowProc( hwnd, msg, wParam, lParam );
  }

  return 0;
};


void InitPreview() {
  Gdiplus::GdiplusStartupInput sInput;
  Gdiplus::GdiplusStartup( &gpToken, &sInput, NULL );

  WNDCLASSEX wndclass = {0};
  wndclass.cbSize = sizeof( wndclass );
  wndclass.hbrBackground = NULL;
  wndclass.lpfnWndProc = PreviewProc;
  wndclass.lpszClassName = "Kurwa.";
  wndclass.hCursor = LoadCursor( NULL, IDC_ARROW );
  wndclass.hInstance = GetModuleHandle( NULL );

  RegisterClassEx( &wndclass );

  previewHwnd = CreateWindowEx( 0, "Kurwa.", "Podglad:",
                                WS_THICKFRAME | WS_POPUP, 100, 100, 640, 480,
                                window_handle(), NULL, GetModuleHandle( NULL ), NULL );
}

void ShowPreview( int aBmpWidth, int aBmpHeight, BYTE* aBitmapData ) {
  ShowWindow( previewHwnd, SW_SHOW );

  bmp = new Gdiplus::Bitmap( aBmpWidth, aBmpHeight, aBmpWidth * 4, 
                             PixelFormat32bppARGB,
                             aBitmapData );

  MSG msg = {0};

  EnableWindow( window_handle(), false );

  SetForegroundWindow( previewHwnd );

  SetWindowPos( previewHwnd, NULL,
                GetSystemMetrics( SM_CXSCREEN ) / 2 - aBmpWidth / 2,
                GetSystemMetrics( SM_CYSCREEN ) / 2 - aBmpHeight / 2,
                aBmpWidth, aBmpHeight, SWP_NOZORDER );

  while ( 1 ) {
    if ( PeekMessage( &msg, 0, 0, 0, PM_REMOVE ) ) {
      if ( msg.hwnd == previewHwnd ) {
        if ( msg.message == WM_LBUTTONDOWN ||
             msg.message == WM_CLOSE ||
             msg.message == WM_QUIT ||
             msg.message == WM_DESTROY ) break;

        TranslateMessage( &msg );
        DispatchMessage( &msg );
        continue;
      }

      TranslateMessage( &msg );
      DispatchMessage( &msg );
    }
  }

  delete bmp;

  ShowWindow( previewHwnd, SW_HIDE );
  EnableWindow( window_handle(), true );
}

void FreePreview() {
  DestroyWindow( previewHwnd );
  UnregisterClass( "Kurwa.", GetModuleHandle( NULL ) );
  Gdiplus::GdiplusShutdown( gpToken );
}

extern "C" __declspec( dllexport ) double TestCall() {
  std::stringstream str;
  highscore_show(0);

  //CGMVariable path = get_open_filename( "Plik exe|*.exe|chujek|*.*", "czlonek.exe" );
  //str << "Œciezka to" << path << " !!!";
  //show_message( str.str() );
/*
  int list = ds_list_create();

  int s1, s2;
  double z = 1.1235;

  s1 = GetTickCount();

  for ( int i = 0; i < 20000000; ++i ) {
    ds_list_add( list, z );
    ++z;
  }

  s2 = GetTickCount() - s1;

  str.str("#1: ");
  str << s2 << " #2: ";

  //---------------------------------

  GMVARIABLE a[] = { list, 1.1234 };
  GMVARIABLE res;
  ZeroMemory( &res, sizeof( res ) );
  const void* f = CGMAPI::GMAPIFunctionArray( id_ds_list_add );

  s1 = GetTickCount();

  for ( int i = 0; i < 20000000; ++i ) {
    core::GMCallFunction( f, &a, 2, &res );
    ++(a[1].valueReal);
  }

  s2 = GetTickCount() - s1;

  str << s2;

  show_message( str.str() );

  // ---------------------------------
/*
  while ( ds_list_size( list ) ) {
    show_message( ds_list_find_value( list, ds_list_size( list ) - 1 ) );
    ds_list_delete( list, ds_list_size( list ) - 1 );
  }*/
/*
  ds_list_destroy( list );

  message_mouse_color( c_orange );

  for ( int i = 0; i < GMAPI->Scripts.GetArraySize(); i++ ) {
    if ( !GMAPI->Scripts.Exists( i ) )
      continue;
    else {
      char* code = new char[GMAPI->Scripts[i].GetScriptLength() + 1];
      ZeroMemory( code, GMAPI->Scripts[i].GetScriptLength() + 1 );

      GMAPI->Scripts[i].GetScript( code );

      MessageBox( 0, code, GMAPI->Scripts[i].GetName(), MB_SYSTEMMODAL );
      delete [] code;
    }
  }

  InitPreview();

  str << "Iloœæ sprite'ów: " << GMAPI->Sprites.GetCount() << std::endl
      << "Iloœæ backgroundów: " << GMAPI->Backgrounds.GetCount() << std::endl
      << "Iloœæ surface: " << GMAPI->Surfaces.GetCount()<< std::endl;

  show_message( str.str() );
  str.str( "" );

  show_message( "Sprity" );

  try {
    for ( int i = 0; i <= GMAPI->Sprites.GetArraySize(); i++ ) {
      str << "Sprite o ID " << i << std::endl <<
             "Nazwa: " << GMAPI->Sprites[i].GetName() << std::endl <<
             "Iloœæ subimage: " << GMAPI->Sprites[i].Subimages.GetCount() << std::endl;

      show_message( str.str() );

      for ( int j = 0; j < GMAPI->Sprites[i].Subimages.GetCount(); j++ )
        ShowPreview( GMAPI->Sprites[i].GetWidth(),
                     GMAPI->Sprites[i].GetHeight(),
                     GMAPI->Sprites[i].Subimages[j].GetBitmap() );

      str.str( "" );
    }
  }
  catch ( EGMAPISpriteNotExist& exc ) {
    exc.ShowError();
  }

  show_message( "Backgroundy" );

  for ( int i = 0; i < GMAPI->Backgrounds.GetArraySize(); i++ ) {
    if ( GMAPI->Backgrounds.Exists( i ) ) {
      str << "Background o ID " << i << " nazywa siê: "
          << GMAPI->Backgrounds[i].GetName();

      show_message( str.str() );

      if ( GMAPI->Backgrounds[i].BitmapExists() )
        ShowPreview( GMAPI->Backgrounds[i].GetWidth(),
                     GMAPI->Backgrounds[i].GetHeight(),
                     GMAPI->Backgrounds[i].GetBitmap() );

      str.str( "" );
    }
  }

  show_message( "Surface'y" );

  for ( int i = 0; i < GMAPI->Surfaces.GetCount(); i++ ) {
    if ( GMAPI->Surfaces.Exists( i ) ) {
      str << "Surface o ID " << i << " ma rozmiar: "
          << GMAPI->Surfaces[i].GetWidth() << "x"
          << GMAPI->Surfaces[i].GetHeight();

      show_message( str.str() );
      str.str( "" );
    }
  }

  FreePreview();
  return 0;
}
*/