# stelmap
Component to view a map of the project OpenStreetMap for Delphi and Builder C without using browser or scripts

![screen1](https://github.com/kodav/stelmap/assets/46531343/8f5ac519-411c-4fc4-8211-3c5a46e7a553)
![screen2](https://github.com/kodav/stelmap/assets/46531343/7bbb8b0e-bf2c-449a-b5db-d05f4c0d17bb)
![screen3](https://github.com/kodav/stelmap/assets/46531343/25a97362-9b6b-4bb6-a740-a867357b5416)


 - View maps offline
 - Support for proxy servers for work online
 - Added to the map an unlimited number of layers, shapes and images
 - Multi-threaded loading tile map speeds up the process to download and view maps
 - Fast rendering
 - Saving the tiles in the cache
 - Support of developers adding new features
```{pascal} {
Class TStelMap:
Offline: Boolean - online / offline download tiles. When offline = TRUE tiles are loaded from the directory CachePath
ShowSet: Boolean - mapping "tools" navigation: zoom, scroll
CachePath: string - path to the directory containing the downloaded tiles
TypeMap: TStyleMap - source type - OpenStreetMap
SiteOSM: string - Address of the server map. You can specify the local address of your server.

procedure LoadMap(LatMap: Double = 0; LonMap: Double = 0) - Loading map by LAT, LON
function AddLayer(): TLayer - Adding new layer on the map
procedure DelLayer(index: integer) - Delete layer from map
procedure ZoomIn() - Zoom in the map
procedure ZoomOut() - Zoom out the map
procedure ZoomInPos(LAT, LON: Double) - Zoom in the map at LAT,LON position
procedure ZoomOutPos(LAT, LON: Double) - Zoom out the map at LAT,LON position

Set of procedures for movement of map:
ShiftUp, ShiftDown, ShiftLeft, ShiftRight

procedure ReDraw() - Redraw the map
procedure Prepare() - Prepare map canvas
procedure MapResize() - Resize map canvas

constructor Create(AOwner: TComponent); override;
destructor Destroy(); override;

OnCustomDraw - the event for custom draw object on the map
OnBeginMapLoad - event at the beginning of the map is loaded
OnEndMapLoad - event at the end of the map is loaded
OnMapLoad - event for loading of the map
OnMapMouseClick - event mouse click on the map
OnMapMouseMove - event mouse move on the map

Properties to support downloading tiles through a proxy server:
proxyserver, proxyuser, proxypassword: String - the name of the proxy server, user, password
proxyuse, proxyauth: Boolean - flag using a proxy and authentication on proxy server
proxyport: smallint - port of the proxy server
License Properties:
Code: string - the license code received when purchasing
Key: string - the license key received when purchasing

Class TLayer:
LayerIndex: smallint - number of layers, starting with 0;
BitMapList: TList - list of images on the map;
ShapeList: TList - list of shapes on the map;
procedure ClearLayer - cleaning the layer;
function AddBitmap(LAT, LON: Double; Hint: string; ShowHint: Boolean; offset_x: integer = 0; offset_y: integer = 0): TBMPObject - add new image on the map
function AddShape(Points: TArrayLatLon; width: smallint; color: TColor; PenStyle: TPenStyle): TShapeObject - add new shape on the map
Visible: Boolean - controls the visibility of the layer

Class TBMPObject
BitMap: TBitMap - bitmap of your image
LatLon: TLATLON - LAT, LON coordinates of your image
Hint: string - hint above your images
ShowHint: Boolean
Visible: Boolean
constructor Create(M: TStelMap)
destructor Destroy(); override
function GPSWidth: Double - return width in geocoorinates of your images
function GPSHeight: Double - return height in geocoorinates of your images

Class TShapeObject
Points: TArrayLatLon - array of point for shape
width: smallint - width lines of shape
color: TColor - color of shape
PenStyle: TPenStyle - pen style of shape
Visible: Boolean
constructor Create(M: TStelMap)
destructor Destroy(); override
