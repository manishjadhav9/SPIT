create database elderlycare;
use elderlycare;
create table ngo(id int primary key, name varchar(20), address varchar(20));
insert into ngo(id, name, address) values (1, "swadesh", "Mahad"), 
(2, "manish", "Andheri"), (3, "atharv", "bhoisar"), (4, "vishesh", "thane"), (5, "nipun", "jogeshwari"),
(6, "nishant", "kalyan"), (7, "krunal", "roha"), (8, "om", "panvel"), (9, "shubham", "karjat"),
(10, "samyak", "khopoli");
select * from ngo;

create table companion(id int primary key, name varchar(20), address varchar(20));
insert into companion(id, name, address) values (16, "swadesh", "Mahad"), 
(2, "manish", "Andheri"), (3, "atharv", "bhoisar"), (4, "vishesh", "thane"), (5, "nipun", "jogeshwari"),
(6, "nishant", "kalyan"), (7, "krunal", "roha"), (88, "om", "panvel"), (9, "shubham", "karjat"),
(100, "samyak", "khopoli");
select * from companion;

/*Equi Join*/
select ngo.id, ngo.name, companion.id, companion.address
from ngo, companion
where ngo.id=companion.id;

create table companions(id int primary key, name varchar(20), address varchar(20));
insert into companions(id, name, address) values (16, "swadesh", "Mahad"), 
(2, "manish", "Andheri"), (3, "atharv", "bhoisar"), (4, "vishesh", "thane");
/*Non Equi Join*/
select ngo.id, ngo.name, companions.id, companions.address
from ngo, companions
where ngo.id<companions.id;

/*Self Join*/
select ngo.name as name1, companion.name as name2, ngo.address
from ngo,companion
where ngo.id<>companion.id
and ngo.address = companion.address
order by ngo.address;

/*Cross Join*/
create table ngo2(id int primary key, name varchar(20), address varchar(20));
insert into ngo2(id, name, address) values (1, "swadesh", "Mahad"), 
(2, "manish", "Andheri");

create table companions2(id int primary key, name varchar(20), address varchar(20));
insert into companions2(id, name, address) values (16, "swadesh", "Mahad"), 
(2, "manish", "Andheri");
select ngo2.name, companions2.address
from ngo2
cross join companions2;

/*Left Outer Join*/
select ngo.name, companion.id
from ngo
left outer join companion
on
ngo.id=companion.id
order by ngo.name;

/*Right Outer Join*/
select ngo.name, companion.id
from ngo
right outer join companion
on
ngo.id=companion.id
order by ngo.id;

/*full outer join*/
select ngo.name, companion.id
from ngo
left outer join companion
on
ngo.id=companion.id
union
select ngo.name, companion.id
from ngo
right outer join companion
on
ngo.id=companion.id;