create database db3;
use db3;

create table EMP(id int primary key,lname varchar(20),fname varchar(20),title varchar(20),deptno int,salary int);
insert into EMP
values
(1,"Savani","Vishesh","Manager",2,2000),(2,"Jadhav","Manish","Employee",4,1000),
(3,"Satere","Nishant","Manager",4,5000),(4,"Shinde","Krunal","Employee",1,3000),
(5,"Satere","Jay","Manager",3,6000),(6,"Sankhe","Atharv","Employee",3,4000),
(7,"Sawant","Rohan","Manager",1,4000),(8,"Sawant","Nipun","Employee",2,2000),
(9,"Sharma","Abhishek","Manager",3,9000),(10,"Shinde","Nikhil","Employee",3,5000);

select * from EMP;
select annual_salary from EMP;
SET SQL_SAFE_UPDATES=0;
update EMP set salary = salary + 250 where title="Manager";
alter table EMP add annual_income int;
SET SQL_SAFE_UPDATES=0;
set annual_income= (salary)*12;
select annual_salary from emp;
