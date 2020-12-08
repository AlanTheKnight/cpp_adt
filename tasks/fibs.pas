program qq;

const
    N = 20;
var
    i: integer;
    A: array[1..N] of integer;

begin
    A[1] := 1;
    A[2] := 1;
    for i := 3 to N do begin
        A[i] := A[i-1] + A[i-2];
    end;

    for i := 1 to N do write(A[i], ' ');
    writeLn();
end.
