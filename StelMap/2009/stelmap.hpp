// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Stelmap.pas' rev: 20.00

#ifndef StelmapHPP
#define StelmapHPP

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
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <Winsock.hpp>	// Pascal unit
#include <Winsvc.hpp>	// Pascal unit
#include <Wininet.hpp>	// Pascal unit
#include <Pngimage.hpp>	// Pascal unit
#include <Jpeg.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stelmap
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TObjectType { stLine, stEllipse, stShape };
#pragma option pop

class DELPHICLASS TDESCrypt;
class PASCALIMPLEMENTATION TDESCrypt : public Classes::TComponent
{
	typedef Classes::TComponent inherited;
	
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
	__fastcall virtual TDESCrypt(Classes::TComponent* AOwner);
	__fastcall virtual ~TDESCrypt(void);
	bool __fastcall Execute(void);
	
__published:
	__property System::UnicodeString Input = {read=FInput, write=setInput};
	__property System::UnicodeString Output = {read=FOutput};
	__property System::UnicodeString Salt = {read=FSalt, write=setSalt};
};


typedef SmallString<15>  st15;

typedef SmallString<10>  st10;

typedef System::Word *pword;

typedef unsigned *pCardinal;

typedef int *pLongint;

typedef StaticArray<int, 2> TAry;

typedef StaticArray<int, 8192> Tusb;

typedef Tusb *pUsb;

struct TTile
{
	
public:
	unsigned xtile;
	unsigned ytile;
	unsigned zoom;
	int x;
	int y;
};


#pragma pack(push,1)
struct twmmousewheel
{
	
public:
	unsigned msg;
	short keys;
	short wheeldelta;
	union
	{
		struct 
		{
			Types::TSmallPoint pos;
			int result;
			
		};
		struct 
		{
			short xpos;
			short ypos;
			
		};
		
	};
};
#pragma pack(pop)


#pragma option push -b-
enum TStyleMap { OpenStreetMap };
#pragma option pop

struct TLATLON
{
	
public:
	double LAT;
	double LON;
};


typedef DynamicArray<TLATLON> TArrayLatLon;

class DELPHICLASS TBMPObject;
class DELPHICLASS TStelMap;
class PASCALIMPLEMENTATION TBMPObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int offset_x;
	int offset_y;
	TStelMap* Map;
	
public:
	Graphics::TBitmap* BitMap;
	TLATLON LatLon;
	System::UnicodeString Hint;
	bool ShowHint;
	bool Visible;
	__fastcall TBMPObject(TStelMap* M);
	__fastcall virtual ~TBMPObject(void);
	double __fastcall GPSWidth(void);
	double __fastcall GPSHeight(void);
};


class DELPHICLASS TShapeObject;
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
	Graphics::TColor color;
	Graphics::TPenStyle PenStyle;
	bool Transparent;
	Graphics::TBrushStyle BrushStyle;
	bool Visible;
	__fastcall TShapeObject(TStelMap* M);
	__fastcall virtual ~TShapeObject(void);
};


class DELPHICLASS TLayer;
class PASCALIMPLEMENTATION TLayer : public Extctrls::TImage
{
	typedef Extctrls::TImage inherited;
	
private:
	bool fVisible;
	HIDESBASE void __fastcall SetVisible(bool value);
	
public:
	TStelMap* Map;
	Classes::TList* BitMapList;
	Classes::TList* ShapeList;
	short LayerIndex;
	__fastcall virtual TLayer(Classes::TComponent* AOwner);
	__fastcall virtual ~TLayer(void);
	void __fastcall ClearLayer(void);
	TBMPObject* __fastcall AddBitmap(double LAT, double LON, System::UnicodeString Hint, bool ShowHint, int offset_x = 0x0, int offset_y = 0x0);
	TShapeObject* __fastcall AddShape(TArrayLatLon Points, short width, Graphics::TColor color, Graphics::TPenStyle PenStyle, TObjectType Shape = (TObjectType)(0x0), int Radius = 0x0, Graphics::TBrushStyle BrushStyle = (Graphics::TBrushStyle)(0x0), bool Transparent = false);
	
__published:
	__property bool Visible = {read=fVisible, write=SetVisible, default=1};
};


class DELPHICLASS TLoadThread;
class PASCALIMPLEMENTATION TLoadThread : public Classes::TThread
{
	typedef Classes::TThread inherited;
	
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
	Pngimage::TPngImage* fEmptyMap;
	Pngimage::TPngImage* fLoadMap;
	virtual void __fastcall Execute(void);
public:
	/* TThread.Create */ inline __fastcall TLoadThread(bool CreateSuspended) : Classes::TThread(CreateSuspended) { }
	/* TThread.Destroy */ inline __fastcall virtual ~TLoadThread(void) { }
	
};


typedef void __fastcall (__closure *TCustomDrawEvent)(TLayer* Layer);

typedef void __fastcall (__closure *TBeginLoadEvent)(int count);

typedef void __fastcall (__closure *TEndLoadEvent)(void);

typedef void __fastcall (__closure *TLoadEvent)(int index);

typedef void __fastcall (__closure *TMapMouseMoveEvent)(double LAT, double LON, int x, int y);

typedef void __fastcall (__closure *TMapMouseClickEvent)(Controls::TMouseButton Button, Classes::TShiftState Shift, double LAT, double LON, int x, int y);

typedef void __fastcall (__closure *TDownloadEvent)(System::Byte zoom, int index, int count);

class PASCALIMPLEMENTATION TStelMap : public Extctrls::TImage
{
	typedef Extctrls::TImage inherited;
	
private:
	typedef DynamicArray<TTile> _TStelMap__1;
	
	typedef DynamicArray<TTile> _TStelMap__2;
	
	
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
	Pngimage::TPngImage* fEmptyMap;
	Pngimage::TPngImage* fLoadMap;
	Pngimage::TPngImage* fSlider;
	Pngimage::TPngImage* fPlus;
	Pngimage::TPngImage* fMinus;
	Pngimage::TPngImage* fNorth;
	Pngimage::TPngImage* fSouth;
	Pngimage::TPngImage* fWest;
	Pngimage::TPngImage* fEast;
	int HeightBuf;
	int WidthBuf;
	Graphics::TPicture* fTempMap;
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
	System::UnicodeString fproxyserver;
	System::UnicodeString fproxyuser;
	System::UnicodeString fproxypassword;
	bool fproxyuse;
	bool fproxyauth;
	short fproxyport;
	System::UnicodeString fcode;
	System::UnicodeString fkey;
	void __fastcall SetBufSize(void);
	void __fastcall ShiftOffset(void);
	int __fastcall TileInMatrix(const TTile &T);
	void __fastcall MyMouseDown(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int x, int y);
	void __fastcall MyMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int x, int y);
	void __fastcall MyMouseMove(System::TObject* Sender, Classes::TShiftState Shift, int x, int y);
	void __fastcall DrawSet(void);
	void __fastcall SetShowSet(bool value);
	void __fastcall SetCachePath(System::UnicodeString value);
	void __fastcall SetKey(System::UnicodeString value);
	void __fastcall SetCode(System::UnicodeString value);
	void __fastcall Close(void);
	void __fastcall DrawBMPObject(int index, TLayer* Layer);
	void __fastcall DrawShapeObject(int index, TLayer* Layer);
	
public:
	unsigned hDraw;
	Classes::TList* ListLayers;
	int zoom;
	double LAT;
	double LON;
	System::UnicodeString SiteOSM;
	System::UnicodeString PathOSM;
	StaticArray<TLoadThread*, 5> LoadThread;
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
	TLATLON __fastcall GetMapCenter();
	__fastcall virtual TStelMap(Classes::TComponent* AOwner);
	__fastcall virtual ~TStelMap(void);
	
__published:
	__property Align = {default=0};
	__property bool Offline = {read=fWorkOffline, write=fWorkOffline, default=0};
	__property bool ShowSet = {read=fShowSet, write=SetShowSet, default=1};
	__property System::UnicodeString CachePath = {read=fCachePath, write=SetCachePath};
	__property TStyleMap TypeMap = {read=fStyleMap, write=fStyleMap, default=0};
	__property TCustomDrawEvent OnCustomDraw = {read=fCustomDrawEvent, write=fCustomDrawEvent};
	__property TBeginLoadEvent OnBeginMapLoad = {read=fBeginLoadEvent, write=fBeginLoadEvent};
	__property TEndLoadEvent OnEndMapLoad = {read=fEndLoadEvent, write=fEndLoadEvent};
	__property TLoadEvent OnMapLoad = {read=fLoadEvent, write=fLoadEvent};
	__property TDownloadEvent OnMapDownload = {read=fDownloadEvent, write=fDownloadEvent};
	__property TMapMouseClickEvent OnMapMouseClick = {read=fMapMouseClickEvent, write=fMapMouseClickEvent};
	__property TMapMouseMoveEvent onMapMouseMove = {read=fMapMouseMoveEvent, write=fMapMouseMoveEvent};
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


class DELPHICLASS TRefreshThread;
class PASCALIMPLEMENTATION TRefreshThread : public Classes::TThread
{
	typedef Classes::TThread inherited;
	
protected:
	TStelMap* Map;
	virtual void __fastcall Execute(void);
public:
	/* TThread.Create */ inline __fastcall TRefreshThread(bool CreateSuspended) : Classes::TThread(CreateSuspended) { }
	/* TThread.Destroy */ inline __fastcall virtual ~TRefreshThread(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt LENGTH_SCALE = 0x32;
static const ShortInt MAXLOAD = 0x5;
#define Salt L"&Lk*7Jkhn(0"
#define LicText L"Copyright © Stelife. All Rights Reserved."
extern PACKAGE TRefreshThread* RefreshThread;
extern PACKAGE StaticArray<StaticArray<StaticArray<int, 2>, 256>, 4> eperm32tab;
extern PACKAGE StaticArray<int, 56> pc1;
extern PACKAGE StaticArray<int, 16> rots;
extern PACKAGE StaticArray<int, 48> pc2;
extern PACKAGE StaticArray<int, 48> esel;
extern PACKAGE StaticArray<int, 64> e_inverse;
extern PACKAGE StaticArray<int, 32> perm32;
extern PACKAGE StaticArray<StaticArray<StaticArray<int, 16>, 4>, 8> sbox;
extern PACKAGE StaticArray<int, 64> initial_perm;
extern PACKAGE StaticArray<int, 64> final_perm;
extern PACKAGE StaticArray<StaticArray<int, 2>, 16> ufc_keytab;
extern PACKAGE Tusb ufc_sb0;
extern PACKAGE Tusb ufc_sb1;
extern PACKAGE Tusb ufc_sb2;
extern PACKAGE Tusb ufc_sb3;
extern PACKAGE StaticArray<pUsb, 4> sb;
extern PACKAGE StaticArray<StaticArray<StaticArray<int, 128>, 2>, 8> do_pc1;
extern PACKAGE StaticArray<StaticArray<int, 128>, 8> do_pc2;
extern PACKAGE StaticArray<StaticArray<StaticArray<int, 2>, 64>, 16> efp;
extern PACKAGE StaticArray<System::Byte, 8> bytemask;
extern PACKAGE StaticArray<int, 32> longmask;
extern PACKAGE int initialized;
extern PACKAGE int direction;
extern PACKAGE int current_saltbits;
extern PACKAGE StaticArray<System::WideChar, 3> current_salt;
extern PACKAGE void __fastcall Register(void);

}	/* namespace Stelmap */
using namespace Stelmap;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StelmapHPP
