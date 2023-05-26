// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Tileosm.pas' rev: 20.00

#ifndef TileosmHPP
#define TileosmHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <Winsock.hpp>	// Pascal unit
#include <Winsvc.hpp>	// Pascal unit
#include <Wininet.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Tileosm
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const Word tileSize = 0x100;
static const int earthRadius = 0x615299;
static const Extended earthCircum = 4.007502E+07;
static const Extended earthHalfCirc = 2.003751E+07;
static const Extended initialResolution = 1.565430E+05;
static const Extended originShift = 2.003751E+07;
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
using namespace Tileosm;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TileosmHPP
