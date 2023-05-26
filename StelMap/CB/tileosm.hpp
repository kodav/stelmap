// CodeGear C++Builder
// Copyright (c) 1995, 2011 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'tileosm.pas' rev: 23.00 (Win32)

#ifndef TileosmHPP
#define TileosmHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Winapi.WinSock.hpp>	// Pascal unit
#include <Winapi.WinSvc.hpp>	// Pascal unit
#include <Winapi.WinInet.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Tileosm
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const System::Word tileSize = System::Word(0x100);
static const int earthRadius = int(0x615299);
static const System::Extended earthCircum = 4.007502E+07;
static const System::Extended earthHalfCirc = 2.003751E+07;
static const System::Extended initialResolution = 1.565430E+05;
static const System::Extended originShift = 2.003751E+07;
extern PACKAGE double __fastcall x2lon(double x, System::Byte zoom);
extern PACKAGE double __fastcall y2lat(double y, System::Byte zoom);
extern PACKAGE double __fastcall MetersPerPixel(int zoom);
extern PACKAGE double __fastcall Resolution(System::Byte zoom);
extern PACKAGE void __fastcall PixelsToTile(int px, int py, int &tx, int &ty);
extern PACKAGE bool __fastcall CheckTile(int zoom, int xtile, int ytile);
extern PACKAGE bool __fastcall GetInetFile(void * hSession, const System::UnicodeString fileURL, const System::UnicodeString FileName, System::UnicodeString proxyserver, System::UnicodeString proxyuser, System::UnicodeString proxypassword, short proxyport, bool proxyuse, bool proxyauth);
extern PACKAGE __int64 __fastcall GetCountTile(System::Byte zoom);
extern PACKAGE void __fastcall LatLonToTile(double lat, double lon, System::Byte zoom, int &tx, int &ty);
extern PACKAGE void __fastcall LatLonToTile2(double lat, double lon, System::Byte zoom, double &tx, double &ty);
extern PACKAGE void __fastcall LatLonToPixel2(double lat, double lon, System::Byte zoom, int &px, int &py);
extern PACKAGE void __fastcall LatLonToPixel(double lat, double lon, System::Byte zoom, int &px, int &py);
extern PACKAGE void __fastcall PixelToLatLon(int px, int py, System::Byte zoom, double &lat, double &lon);

}	/* namespace Tileosm */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_TILEOSM)
using namespace Tileosm;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TileosmHPP
