program qq;

const
    N = 20;
var
    i: integer;
    A: array[1..N] of longint;

begin
    A[N] := 1;
    for i := (N-1) downto 1 do begin
        A[i] := A[i+1] * 2;
    end;
    for i := 1 to N do write(A[i], ' ');
    writeLn();
end.
