select sleep(2);
select * from tst where lname like '%e%' order by fname;
insert into tst values ("Jane","Doe"),("Daisy","Duck"),("Marie","Curie");
update tst set fname="Farmer", lname="McDonald" where lname="%Doe" and fname="John";
create table tmp as select * from t1;
create temporary table tmp as select * from t1;
select @@server_id;
select @OLD_SQL_NOTES;
SET autocommit=1;
SET autocommit=0;
BEGIN;
ROLLBACK;
COMMIT;
use X;
select last_insert_id();
select @@last_insert_id;
select @@identity;
select if(@@hostname='box02','prod_mariadb02','n');
select next value for seq1;
select nextval(seq1);
select seq1.nextval;
SELECT GET_LOCK('lock1',10);
SELECT IS_FREE_LOCK('lock1');
SELECT IS_USED_LOCK('lock1');
SELECT RELEASE_LOCK('lock1');
deallocate prepare select_stmt;
SELECT a FROM tbl FOR UPDATE;
