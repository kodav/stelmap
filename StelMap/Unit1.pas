unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics,
  Controls, Forms, Dialogs, ExtCtrls, stelmap;

type
  TForm1 = class(TForm)
    StelMap1: TStelMap;
    procedure FormResize(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.FormResize(Sender: TObject);
begin
  StelMap1.MapResize;
  StelMap1.Prepare;
  StelMap1.LoadMap(0, 0, TRUE);
  StelMap1.ReDraw;
end;

end.
