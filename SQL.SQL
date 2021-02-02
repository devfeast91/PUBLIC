create table s
( sno number(5),
sname varchar2(10),
m1 number(3,2),
m2 number(3,2),
m3 number(3,2),
total number (10,2),
percentage number(2,2),
grade varchar2(2)
);

insert into s (sno,sname,m1,m2,m3)
values(2,'B',6,6,6);


declare
v_sno s.sno%type;
v_sname s.sname%type;
v_m1 s.m1%type;
v_m2 s.m2%type;
v_m3 s.m3%type;
v_total s.total%type;
v_percentage s.percentage%type;
v_grade s.grade%type;

cursor curs
is select sno,sname,m1,m2,m3 from s;

begin

open curs;

loop
fetch curs into v_sno,v_sname,v_m1,v_m2,v_m3;

v_total := v_m1 + v_m2 + v_m3;

v_percentage := v_total/30;

if v_percentage > 80 then
    v_grade := 'A';
elsif v_percentage > 70 then
    v_grade := 'B';
elsif v_percentage > 50 then
    v_grade := 'C';
else
    v_grade := 'D';
end if;

update s set total = v_total,percentage = v_percentage,grade = v_grade
where sno = v_sno;

exit when curs%NOTFOUND;
end loop;
end;

select * from s;

CREATE OR REPLACE TRIGGER trg_tue
BEFORE INSERT OR UPDATE OR DELETE ON s
FOR EACH ROW
BEGIN
    IF TO_CHAR(SYSDATE, 'D') = '3' THEN
        RAISE_APPLICATION_ERROR(-20000, 'Cannot insert record on TUESDAY'); 
    END IF;
END;

AFTER TRIGGER WE ARE NOT ABLE TO DML *-*
