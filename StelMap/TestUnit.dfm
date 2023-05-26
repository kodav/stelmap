object Form2: TForm2
  Left = 207
  Top = 163
  Caption = 'StelMAP test'
  ClientHeight = 425
  ClientWidth = 820
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object StelMap1: TStelMap
    Left = 0
    Top = 0
    Width = 820
    Height = 378
    Align = alClient
    Picture.Data = {07544269746D617000000000}
    CachePath = '.\Cache\'
    TypeMap = OpenStreetMap
    OnBeginMapLoad = StelMap1BeginMapLoad
    OnEndMapLoad = StelMap1EndMapLoad
    OnMapDownload = StelMap1MapDownload
    onMapMouseMove = StelMap1MapMouseMove
    onMouseWheel = StelMap1MouseWheel
    proxyport = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 378
    Width = 820
    Height = 47
    Align = alBottom
    TabOrder = 0
    object LabelLoadMap: TLabel
      Left = 16
      Top = 29
      Width = 81
      Height = 13
      Caption = 'Loading map...'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Offline: TCheckBox
      Left = 16
      Top = 6
      Width = 57
      Height = 17
      Caption = 'Offline'
      TabOrder = 0
      OnClick = OfflineClick
    end
    object ShowSet: TCheckBox
      Left = 87
      Top = 6
      Width = 68
      Height = 17
      Caption = 'Show set'
      Checked = True
      State = cbChecked
      TabOrder = 1
      OnClick = ShowSetClick
    end
    object Button1: TButton
      Left = 328
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Add Car'
      TabOrder = 2
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 408
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Add Path'
      Enabled = False
      TabOrder = 3
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 654
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Clear all'
      TabOrder = 4
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 573
      Top = 6
      Width = 75
      Height = 25
      Caption = 'GO'
      Enabled = False
      TabOrder = 5
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 488
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Add Shape'
      Enabled = False
      TabOrder = 6
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 736
      Top = 6
      Width = 75
      Height = 25
      Caption = 'New window'
      TabOrder = 7
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 167
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Download'
      TabOrder = 8
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 247
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Stop download'
      TabOrder = 9
      OnClick = Button8Click
    end
  end
end
