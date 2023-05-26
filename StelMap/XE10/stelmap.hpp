// CodeGear C++Builder
// Copyright (c) 1995, 2015 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'stelmap.pas' rev: 30.00 (Windows)

#ifndef StelmapHPP
#define StelmapHPP

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
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <System.Math.hpp>
#include <Winapi.WinSock.hpp>
#include <Winapi.WinSvc.hpp>
#include <Winapi.WinInet.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <System.Types.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Stelmap
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TDESCrypt;
struct TTile;
struct twmmousewheel;
struct TLATLON;
class DELPHICLASS TBMPObject;
class DELPHICLASS TShapeObject;
class DELPHICLASS TLayer;
class DELPHICLASS TLoadThread;
class DELPHICLASS TStelMap;
class DELPHICLASS TRefreshThread;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TObjectType : unsigned char { stLine, stEllipse, stShape };

class PASCALIMPLEMENTATION TDESCrypt : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::UnicodeString FInput;
	System::UnicodeString FOutput;
	System::UnicodeString FSalt;
	void __fastcall AutoInitialize(void);
	void __fastcall AutoDestroy(void);
	
protected:
	virtual void __fastcall Loaded(void);
	void __fastcall setInput(System::UnicodeString _s);
	void __fastcall setSalt(System::UnicodeString _s);
	
public:
	__fastcall virtual TDESCrypt(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TDESCrypt(void);
	bool __fastcall Execute(void);
	
__published:
	__property System::UnicodeString Input = {read=FInput, write=setInput};
	__property System::UnicodeString Output = {read=FOutput};
	__property System::UnicodeString Salt = {read=FSalt, write=setSalt};
};


typedef System::SmallString<15> st15;

typedef System::SmallString<10> st10;

typedef System::Word *pword;

typedef unsigned *pCardinal;

typedef int *pLongint;

typedef System::StaticArray<int, 2> TAry;

typedef System::StaticArray<int, 8192> Tusb;

typedef Tusb *pUsb;

struct DECLSPEC_DRECORD TTile
{
public:
	unsigned xtile;
	unsigned ytile;
	unsigned zoom;
	int x;
	int y;
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD twmmousewheel
{
public:
	unsigned msg;
	short keys;
	short wheeldelta;
	
public:
	union
	{
		struct
		{
			short xpos;
			short ypos;
		};

	};
};
#pragma pack(pop)


enum DECLSPEC_DENUM TStyleMap : unsigned char { OpenStreetMap, MapQuest };

struct DECLSPEC_DRECORD TLATLON
{
public:
	double LAT;
	double LON;
};


typedef System::DynamicArray<TLATLON> TArrayLatLon;

class PASCALIMPLEMENTATION TBMPObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int offset_x;
	int offset_y;
	TStelMap* Map;
	
public:
	Vcl::Graphics::TBitmap* BitMap;
	TLATLON LatLon;
	System::UnicodeString Hint;
	bool ShowHint;
	bool Visible;
	__fastcall TBMPObject(TStelMap* M);
	__fastcall virtual ~TBMPObject(void);
	double __fastcall GPSWidth(void);
	double __fastcall GPSHeight(void);
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TShapeObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TStelMap* Map;
	
public:
	TObjectType Shape;
	int Radius;
	TArrayLatLon Points;
	short width;
	System::Uitypes::TColor color;
	Vcl::Graphics::TPenStyle PenStyle;
	bool Transparent;
	Vcl::Graphics::TBrushStyle BrushStyle;
	bool Visible;
	__fastcall TShapeObject(TStelMap* M);
	__fastcall virtual ~TShapeObject(void);
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TLayer : public Vcl::Extctrls::TImage
{
	typedef Vcl::Extctrls::TImage inherited;
	
private:
	bool fVisible;
	HIDESBASE void __fastcall SetVisible(bool value);
	
public:
	TStelMap* Map;
	System::Classes::TList* BitMapList;
	System::Classes::TList* ShapeList;
	short LayerIndex;
	__fastcall virtual TLayer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TLayer(void);
	void __fastcall ClearLayer(void);
	TBMPObject* __fastcall AddBitmap(double LAT, double LON, System::UnicodeString Hint, bool ShowHint, int offset_x = 0x0, int offset_y = 0x0);
	TShapeObject* __fastcall AddShape(TArrayLatLon Points, short width, System::Uitypes::TColor color, Vcl::Graphics::TPenStyle PenStyle, TObjectType Shape = (TObjectType)(0x0), int Radius = 0x0, Vcl::Graphics::TBrushStyle BrushStyle = (Vcl::Graphics::TBrushStyle)(0x0), bool Transparent = false);
	
__published:
	__property bool Visible = {read=fVisible, write=SetVisible, default=1};
};


class PASCALIMPLEMENTATION TLoadThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
protected:
	void *hSession;
	bool Active;
	System::UnicodeString filename;
	TLayer* Layer;
	int x;
	int y;
	int xtile;
	int ytile;
	System::Byte zoom;
	bool *fLicense;
	TStelMap* Map;
	Vcl::Imaging::Pngimage::TPngImage* fEmptyMap;
	Vcl::Imaging::Pngimage::TPngImage* fLoadMap;
	virtual void __fastcall Execute(void);
public:
	/* TThread.Create */ inline __fastcall TLoadThread(void)/* overload */ : System::Classes::TThread() { }
	/* TThread.Create */ inline __fastcall TLoadThread(bool CreateSuspended)/* overload */ : System::Classes::TThread(CreateSuspended) { }
	/* TThread.Destroy */ inline __fastcall virtual ~TLoadThread(void) { }
	
};


typedef void __fastcall (__closure *TCustomDrawEvent)(TLayer* Layer);

typedef void __fastcall (__closure *TBeginLoadEvent)(int count);

typedef void __fastcall (__closure *TEndLoadEvent)(void);

typedef void __fastcall (__closure *TLoadEvent)(int index);

typedef void __fastcall (__closure *TMapMouseMoveEvent)(double LAT, double LON, int x, int y);

typedef void __fastcall (__closure *TMapMouseWheelEvent)(System::TObject* Sender, System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos, bool &Handled);

typedef void __fastcall (__closure *TMapMouseClickEvent)(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, double LAT, double LON, int x, int y);

typedef void __fastcall (__closure *TDownloadEvent)(System::Byte zoom, int index, int count);

class PASCALIMPLEMENTATION TStelMap : public Vcl::Extctrls::TImage
{
	typedef Vcl::Extctrls::TImage inherited;
	
	
private:
	typedef System::DynamicArray<TTile> _TStelMap__1;
	
	typedef System::DynamicArray<TTile> _TStelMap__2;
	
	
private:
	int fTopX;
	int fTopY;
	int fCenterX;
	int fCenterY;
	int fBottomX;
	int fBottomY;
	_TStelMap__1 TileMatrix;
	_TStelMap__2 LoadMatrix;
	bool fStopDownload;
	bool *fLicense;
	System::UnicodeString fCachePath;
	System::UnicodeString fCrypt;
	Vcl::Imaging::Pngimage::TPngImage* fEmptyMap;
	Vcl::Imaging::Pngimage::TPngImage* fLoadMap;
	Vcl::Imaging::Pngimage::TPngImage* fSlider;
	Vcl::Imaging::Pngimage::TPngImage* fPlus;
	Vcl::Imaging::Pngimage::TPngImage* fMinus;
	Vcl::Imaging::Pngimage::TPngImage* fNorth;
	Vcl::Imaging::Pngimage::TPngImage* fSouth;
	Vcl::Imaging::Pngimage::TPngImage* fWest;
	Vcl::Imaging::Pngimage::TPngImage* fEast;
	int HeightBuf;
	int WidthBuf;
	Vcl::Graphics::TPicture* fTempMap;
	bool fWorkOffline;
	TLayer* fMapLayer;
	bool fShowSet;
	TStyleMap fStyleMap;
	double TopLAT;
	double TopLON;
	double BottomLAT;
	double BottomLON;
	int StartX;
	int StartY;
	int OffsetX;
	int OffsetY;
	TCustomDrawEvent fCustomDrawEvent;
	TBeginLoadEvent fBeginLoadEvent;
	TEndLoadEvent fEndLoadEvent;
	TLoadEvent fLoadEvent;
	TDownloadEvent fDownloadEvent;
	TMapMouseClickEvent fMapMouseClickEvent;
	TMapMouseMoveEvent fMapMouseMoveEvent;
	TMapMouseWheelEvent fMapMouseWheelEvent;
	System::UnicodeString fproxyserver;
	System::UnicodeString fproxyuser;
	System::UnicodeString fproxypassword;
	bool fproxyuse;
	bool fproxyauth;
	short fproxyport;
	System::UnicodeString fcode;
	System::UnicodeString fkey;
	TRefreshThread* RefreshThread;
	void __fastcall SetBufSize(void);
	void __fastcall ShiftOffset(void);
	int __fastcall TileInMatrix(const TTile &T);
	void __fastcall MyMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int x, int y);
	void __fastcall MyMouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int x, int y);
	void __fastcall MyMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int x, int y);
	void __fastcall DrawSet(void);
	void __fastcall SetShowSet(bool value);
	void __fastcall SetCachePath(System::UnicodeString value);
	void __fastcall SetKey(System::UnicodeString value);
	void __fastcall SetCode(System::UnicodeString value);
	void __fastcall SetStyleMap(TStyleMap value);
	void __fastcall Close(void);
	void __fastcall DrawBMPObject(int index, TLayer* Layer);
	void __fastcall DrawShapeObject(int index, TLayer* Layer);
	HIDESBASE MESSAGE void __fastcall WMMouseWheel(twmmousewheel &Msg);
	
public:
	NativeUInt hDraw;
	System::Classes::TList* ListLayers;
	int zoom;
	double LAT;
	double LON;
	System::UnicodeString SiteOSM;
	System::UnicodeString PathOSM;
	System::StaticArray<TLoadThread*, 5> LoadThread;
	void __fastcall LoadMap(double LatMap = 0.000000E+00, double LonMap = 0.000000E+00, bool DoCenter = false);
	TLayer* __fastcall AddLayer(void);
	void __fastcall DelLayer(int index);
	void __fastcall ZoomInPos(double LAT, double LON, System::Byte Z = (System::Byte)(0x1));
	void __fastcall ZoomOutPos(double LAT, double LON, System::Byte Z = (System::Byte)(0x1));
	void __fastcall ZoomIn(void);
	void __fastcall ZoomOut(void);
	void __fastcall ShiftUp(void);
	void __fastcall ShiftDown(void);
	void __fastcall ShiftLeft(void);
	void __fastcall ShiftRight(void);
	void __fastcall ReDraw(void);
	void __fastcall Prepare(void);
	void __fastcall MapResize(void);
	void __fastcall DownloadTiles(System::Byte dZoom, double LatMin, double LonMin, double LatMax, double LonMax, int Timeout);
	void __fastcall StopDownload(void);
	TLayer* __fastcall Layers(int index);
	TLATLON __fastcall GetMapCenter(void);
	__fastcall virtual TStelMap(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TStelMap(void);
	
__published:
	__property Align = {default=0};
	__property bool Offline = {read=fWorkOffline, write=fWorkOffline, default=0};
	__property bool ShowSet = {read=fShowSet, write=SetShowSet, default=1};
	__property System::UnicodeString CachePath = {read=fCachePath, write=SetCachePath};
	__property TStyleMap TypeMap = {read=fStyleMap, write=SetStyleMap, nodefault};
	__property TCustomDrawEvent OnCustomDraw = {read=fCustomDrawEvent, write=fCustomDrawEvent};
	__property TBeginLoadEvent OnBeginMapLoad = {read=fBeginLoadEvent, write=fBeginLoadEvent};
	__property TEndLoadEvent OnEndMapLoad = {read=fEndLoadEvent, write=fEndLoadEvent};
	__property TLoadEvent OnMapLoad = {read=fLoadEvent, write=fLoadEvent};
	__property TDownloadEvent OnMapDownload = {read=fDownloadEvent, write=fDownloadEvent};
	__property TMapMouseClickEvent OnMapMouseClick = {read=fMapMouseClickEvent, write=fMapMouseClickEvent};
	__property TMapMouseMoveEvent onMapMouseMove = {read=fMapMouseMoveEvent, write=fMapMouseMoveEvent};
	__property TMapMouseWheelEvent onMouseWheel = {read=fMapMouseWheelEvent, write=fMapMouseWheelEvent};
	__property System::UnicodeString proxyserver = {read=fproxyserver, write=fproxyserver};
	__property System::UnicodeString proxyuser = {read=fproxyuser, write=fproxyuser};
	__property System::UnicodeString proxypassword = {read=fproxypassword, write=fproxypassword};
	__property bool proxyuse = {read=fproxyuse, write=fproxyuse, default=0};
	__property bool proxyauth = {read=fproxyauth, write=fproxyauth, default=0};
	__property short proxyport = {read=fproxyport, write=fproxyport, default=8080};
	__property System::UnicodeString Code = {read=fcode, write=SetCode};
	__property System::UnicodeString Key = {read=fkey, write=SetKey};
	__property double MinLAT = {read=TopLAT};
	__property double MinLON = {read=TopLON};
	__property double MaxLAT = {read=BottomLAT};
	__property double MaxLON = {read=BottomLON};
};


class PASCALIMPLEMENTATION TRefreshThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
protected:
	TStelMap* Map;
	virtual void __fastcall Execute(void);
public:
	/* TThread.Create */ inline __fastcall TRefreshThread(void)/* overload */ : System::Classes::TThread() { }
	/* TThread.Create */ inline __fastcall TRefreshThread(bool CreateSuspended)/* overload */ : System::Classes::TThread(CreateSuspended) { }
	/* TThread.Destroy */ inline __fastcall virtual ~TRefreshThread(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 LENGTH_SCALE = System::Int8(0x32);
static const System::Int8 MAXLOAD = System::Int8(0x5);
extern DELPHI_PACKAGE System::StaticArray<System::StaticArray<System::StaticArray<int, 2>, 256>, 4> eperm32tab;
extern DELPHI_PACKAGE System::StaticArray<int, 56> pc1;
extern DELPHI_PACKAGE System::StaticArray<int, 16> rots;
extern DELPHI_PACKAGE System::StaticArray<int, 48> pc2;
extern DELPHI_PACKAGE System::StaticArray<int, 48> esel;
extern DELPHI_PACKAGE System::StaticArray<int, 64> e_inverse;
extern DELPHI_PACKAGE System::StaticArray<int, 32> perm32;
extern DELPHI_PACKAGE System::StaticArray<System::StaticArray<System::StaticArray<int, 16>, 4>, 8> sbox;
extern DELPHI_PACKAGE System::StaticArray<int, 64> initial_perm;
extern DELPHI_PACKAGE System::StaticArray<int, 64> final_perm;
extern DELPHI_PACKAGE System::StaticArray<System::StaticArray<int, 2>, 16> ufc_keytab;
extern DELPHI_PACKAGE Tusb ufc_sb0;
extern DELPHI_PACKAGE Tusb ufc_sb1;
extern DELPHI_PACKAGE Tusb ufc_sb2;
extern DELPHI_PACKAGE Tusb ufc_sb3;
extern DELPHI_PACKAGE System::StaticArray<pUsb, 4> sb;
extern DELPHI_PACKAGE System::StaticArray<System::StaticArray<System::StaticArray<int, 128>, 2>, 8> do_pc1;
extern DELPHI_PACKAGE System::StaticArray<System::StaticArray<int, 128>, 8> do_pc2;
extern DELPHI_PACKAGE System::StaticArray<System::StaticArray<System::StaticArray<int, 2>, 64>, 16> efp;
extern DELPHI_PACKAGE System::StaticArray<System::Byte, 8> bytemask;
extern DELPHI_PACKAGE System::StaticArray<int, 32> longmask;
extern DELPHI_PACKAGE int initialized;
extern DELPHI_PACKAGE int direction;
extern DELPHI_PACKAGE int current_saltbits;
extern DELPHI_PACKAGE System::StaticArray<System::WideChar, 3> current_salt;
extern DELPHI_PACKAGE void __fastcall Register(void);
}	/* namespace Stelmap */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_STELMAP)
using namespace Stelmap;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StelmapHPP
