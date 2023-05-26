// CodeGear C++Builder
// Copyright (c) 1995, 2015 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'tileosm.pas' rev: 30.00 (Windows)

#ifndef TileosmHPP
#define TileosmHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Math.hpp>
#include <Winapi.WinSock.hpp>
#include <Winapi.WinSvc.hpp>
#include <Winapi.WinInet.hpp>

//-- user supplied -----------------------------------------------------------

namespace Tileosm
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const System::Word tileSize = System::Word(0x100);
static const int earthRadius = int(0x615299);
static const System::Extended earthCircum = 4.007502E+07;
static const System::Extended earthHalfCirc = 2.003751E+07;
static const System::Extended initialResolution = 1.565430E+05;
static const System::Extended originShift = 2.003751E+07;
extern DELPHI_PACKAGE double __fastcall x2lon(double x, System::Byte zoom);
extern DELPHI_PACKAGE double __fastcall y2lat(double y, System::Byte zoom);
extern DELPHI_PACKAGE double __fastcall MetersPerPixel(int zoom);
extern DELPHI_PACKAGE double __fastcall Resolution(System::Byte zoom);
extern DELPHI_PACKAGE void __fastcall PixelsToTile(int px, int py, int &tx, int &ty);
extern DELPHI_PACKAGE bool __fastcall CheckTile(int zoom, int xtile, int ytile);
extern DELPHI_PACKAGE bool __fastcall GetInetFile(void * hSession, const System::UnicodeString fileURL, const System::UnicodeString FileName, System::UnicodeString proxyserver, System::UnicodeString proxyuser, System::UnicodeString proxypassword, short proxyport, bool proxyuse, bool proxyauth);
extern DELPHI_PACKAGE __int64 __fastcall GetCountTile(System::Byte zoom);
extern DELPHI_PACKAGE void __fastcall LatLonToTile(double lat, double lon, System::Byte zoom, int &tx, int &ty);
extern DELPHI_PACKAGE void __fastcall LatLonToTile2(double lat, double lon, System::Byte zoom, double &tx, double &ty);
extern DELPHI_PACKAGE void __fastcall LatLonToPixel2(double lat, double lon, System::Byte zoom, int &px, int &py);
extern DELPHI_PACKAGE void __fastcall LatLonToPixel(double lat, double lon, System::Byte zoom, int &px, int &py);
extern DELPHI_PACKAGE void __fastcall PixelToLatLon(int px, int py, System::Byte zoom, double &lat, double &lon);
}	/* namespace Tileosm */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_TILEOSM)
using namespace Tileosm;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TileosmHPP
