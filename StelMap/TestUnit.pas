unit TestUnit;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, stelmap, StdCtrls;

const
  // moscow
  FirstLAT = 55.75578;
  FirstLON = 37.615149;
  // munchen
//  FirstLAT = 48.11218612;
//  FirstLON = 11.52603368;

type
  TForm2 = class(TForm)
    Panel1: TPanel;
    Offline: TCheckBox;
    ShowSet: TCheckBox;
    LabelLoadMap: TLabel;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    StelMap1: TStelMap;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Button8: TButton;
    procedure FormResize(Sender: TObject);
    procedure OfflineClick(Sender: TObject);
    procedure ShowSetClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure StelMap1BeginMapLoad(count: Integer);
    procedure StelMap1EndMapLoad;
		procedure Button1Click(Sender: TObject);
		procedure Button2Click(Sender: TObject);
		procedure Button4Click(Sender: TObject);
		procedure Button5Click(Sender: TObject);
		procedure Button3Click(Sender: TObject);
		procedure Button6Click(Sender: TObject);
		procedure Button7Click(Sender: TObject);
		procedure StelMap1MapDownload(zoom: Byte; index, count: Integer);
		procedure Button8Click(Sender: TObject);
procedure StelMap1MouseWheel(Sender: TObject; Shift: TShiftState;
			WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean);
		procedure StelMap1MapMouseMove(LAT, LON: Double; x, y: Integer);
	private
		{ Private declarations }
	public
		{ Public declarations }
	end;

var
	Form2: TForm2;
	Points : TArrayLatLon;
	GlobalLAT, GlobalLON : Double;

implementation

{$R *.dfm}

uses Unit1;

procedure TForm2.Button1Click(Sender: TObject);
var
	Car : TBMPObject;
begin
	StelMap1.AddLayer;
	Car := StelMap1.Layers(0).AddBitmap(FirstLAT,FirstLON, 'Car', True, 0, 0);

	Car.BitMap.LoadFromFile('car.bmp');
	Car.BitMap.Transparent := TRUE;
	StelMap1.ReDraw;
	if (StelMap1.Layers(0).BitMapList.Count > 0) and (StelMap1.Layers(0).ShapeList.Count > 0) then begin
		Button4.Enabled := TRUE;
		Button2.Enabled := TRUE;
		Button5.Enabled := TRUE;
	end;
	Button1.Enabled := FALSE;
end;

procedure TForm2.Button2Click(Sender: TObject);
begin
	SetLength(Points, 5);
	Points[0].LAT := FirstLAT-1; Points[0].LON := FirstLON;
	Points[1].LAT := FirstLAT;   Points[1].LON := FirstLON-1;
	Points[2].LAT := FirstLAT;   Points[2].LON := FirstLON+1;
	Points[3].LAT := FirstLAT+1; Points[3].LON := FirstLON;
	Points[4].LAT := FirstLAT-1; Points[4].LON := FirstLON;
	StelMap1.Layers(0).AddShape(Points, 2, clRed, psSolid);
	StelMap1.ReDraw;
	if (StelMap1.Layers(0).BitMapList.Count > 0) and (StelMap1.Layers(0).ShapeList.Count > 0) then
		Button4.Enabled := TRUE;
	Button2.Enabled := FALSE;
end;

procedure TForm2.Button3Click(Sender: TObject);
begin
	StelMap1.Layers(0).Free;
	StelMap1.ListLayers.Delete(0);
	StelMap1.ReDraw;
	Button4.Enabled := FALSE;
	Button1.Enabled := TRUE;
	Button2.Enabled := FALSE;
	Button5.Enabled := FALSE;
end;

procedure TForm2.Button4Click(Sender: TObject);
var
  Car : TBMPObject;
  i : Byte;
begin
  Car := StelMap1.Layers(0).BitMapList[0];
  for I := 0 to Length(Points) - 1 do begin
    Car.LatLon.LAT := Points[I].LAT;
    Car.LatLon.LON := Points[I].LON;
    Sleep(1000);
		Application.ProcessMessages;
    StelMap1.ReDraw;
  end;
end;

procedure TForm2.Button5Click(Sender: TObject);
begin
  SetLength(Points, 5);
  Points[0].LAT := FirstLAT-1; Points[0].LON := FirstLON;
  Points[1].LAT := FirstLAT;   Points[1].LON := FirstLON-1;
  Points[2].LAT := FirstLAT;   Points[2].LON := FirstLON+1;
  Points[3].LAT := FirstLAT+1; Points[3].LON := FirstLON;
  Points[4].LAT := FirstLAT-1; Points[4].LON := FirstLON;
  StelMap1.Layers(0).AddShape(Points, 2, clRed, psSolid, stShape, 0, bsSolid, true);
  StelMap1.ReDraw;
  if (StelMap1.Layers(0).BitMapList.Count > 0) and (StelMap1.Layers(0).ShapeList.Count > 0) then
    Button4.Enabled := TRUE;
  Button2.Enabled := FALSE;
end;

procedure TForm2.Button6Click(Sender: TObject);
begin
  Form1.Show;
end;

procedure TForm2.Button7Click(Sender: TObject);
begin
  LabelLoadMap.Visible := true;
  StelMap1.DownloadTiles(13, FirstLAT-2, FirstLON-2, FirstLAT+2, FirstLON+2, 10);
  LabelLoadMap.Visible := false;
end;

procedure TForm2.Button8Click(Sender: TObject);
begin
  StelMap1.StopDownload;
end;

procedure TForm2.FormCreate(Sender: TObject);
begin
	StelMap1.LAT := FirstLAT;
  StelMap1.LON := FirstLON;
  StelMap1.Zoom := 0;
end;

procedure TForm2.FormResize(Sender: TObject);
begin
  StelMap1.MapResize;
  StelMap1.Prepare;
  StelMap1.LoadMap(0, 0, TRUE);
  StelMap1.ReDraw;
end;

procedure TForm2.OfflineClick(Sender: TObject);
begin
  StelMap1.Offline := Offline.Checked;
end;

procedure TForm2.ShowSetClick(Sender: TObject);
begin
  StelMap1.ShowSet := ShowSet.Checked;
end;

procedure TForm2.StelMap1BeginMapLoad(count: Integer);
begin
  LabelLoadMap.Visible := True;
  LabelLoadMap.Refresh;
end;

procedure TForm2.StelMap1EndMapLoad;
begin
  LabelLoadMap.Visible := False;
	LabelLoadMap.Refresh;
end;

procedure TForm2.StelMap1MapDownload(zoom: Byte; index, count: Integer);
begin
  LabelLoadMap.Caption := Format('Loaded %d from %d', [index, count]);
  Application.ProcessMessages;
end;

procedure TForm2.StelMap1MapMouseMove(LAT, LON: Double; x, y: Integer);
begin
	 GlobalLAT := LAT;
	 GlobalLON := LON;
end;

procedure TForm2.StelMap1MouseWheel(Sender: TObject; Shift: TShiftState;
	WheelDelta: Integer; MousePos: TPoint; var Handled: Boolean);
begin
	if Wheeldelta < 0

		then StelMap1.ZoominPos(GlobalLAT, GlobalLON)
		 else StelMap1.ZoomOutPos(GlobalLAT, GlobalLON);

//		 Handled := TRUE;
//	if ssShift in Shift then
		Handled := false;
end;

end.
