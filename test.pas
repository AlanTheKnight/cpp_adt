program qq;

var a: integer;

function isEven(a: integer): Boolean;
begin
    if a mod 2 = 0 then
        Exit(true);
    Exit(false);
end;

begin
    read(a);
    writeLn(isEven(a));    
end.
