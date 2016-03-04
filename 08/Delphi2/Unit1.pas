unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Unit2, Unit3, StdCtrls;

type
  TForm1 = class(TForm)
    mmo1: TMemo;
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

type
  TUser = record
    login : string;
    password : string;
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}


procedure TForm1.FormCreate(Sender: TObject);
var
  u1 : TUser;
  u2 : Unit2.TUser;
  u3 : Unit3.TUser;
begin
  u1.login := 'login1 u2';

 // Move(u1, u2, SizeOf(u1));
  u2 := Unit2.TUser(u1);

  mmo1.Lines.Add(u2.login);

  f(Unit2.TUser(u2));
end;

end.
 