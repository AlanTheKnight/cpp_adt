program qq;

const N = 10;

var
    A, B: array[1..N] of integer;
    i, size: integer;

begin
    write('Enter 10 numbers: ');
    for i := 1 to N do read(A[i]);

    size := 1;
    for i := 1 to N do begin
        if ((A[i] > 0) and (A[i] mod 2 = 0)) then begin
            B[size] := A[i];
            size += 1;
        end;
    end;

    if size <> 1 then begin
        for i := 1 to (size-1) do write(B[i], ' ');
        writeLn()
    end else
        writeLn('No numbers matching the query found!');

end.