var a:array['A'..'Z'] of char;
    l,le,i:longint;
    s1,s2,s3:string;
    ch,ch2:char;

begin
assign(input,'spy.in');
reset(input);
assign(output,'spy.out');
rewrite(output);

readln(s1);           //pas
readln(s2);
l:=length(s1);
readln(s3);
le:=length(s3);

fillchar(a,sizeof(a),' ');

for i:=1 to l do
 begin
 if a[s1[i]]=' ' then a[s1[i]]:=s2[i]
 else if (s2[i]<>a[s1[i]]) then
  begin
  writeln('Failed');
  close(input);
  close(output);
  halt;
  end;
 end;

FOR ch:='A' to 'Z' do
 if a[ch]=' ' then
 begin
 writeln('Failed');
 close(input);
 close(output);
 halt;
 end;

FOR ch:='A' to 'Z' do
 for ch2:='A' to 'Z' do
  if (ch<>ch2) and (a[ch]=a[ch2]) then
  begin
  writeln('Failed');
  close(input);
  close(output);
  halt;
  end;

for i:=1 to le do
// begin
 if a[s3[i]]<>' ' then write(a[s3[i]]);
// else begin writeln('Failed'); halt; end;
// end;

writeln;
close(input);
close(output);
end.
