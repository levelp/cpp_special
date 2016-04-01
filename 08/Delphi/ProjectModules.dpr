program ProjectModules;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Unit1 in 'Unit1.pas',
  Unit2 in 'Unit2.pas';

type
  TUser = record
    login : string;
    password : string;
  end;

var user : TUser;
  u1 : Unit1.TUser;
  u2 : Unit2.TUser;
begin
  user.login := 'login1';
  user.password := 'password1';
  u1.login := user.login + ' u1';
  u2.login := user.login + ' u2';
  writeln(u1.login);
  writeln(u2.login);


  Readln;
end.
