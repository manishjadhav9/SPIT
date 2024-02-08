create user 'Manish'@'localhost' identified by '2809';
show grants for 'Manish'@'localhost';
create database exp3;
use exp3;
create  table office(id int primary key, name varchar(20));
grant select on *.* to 'Manish'@'localhost';
show grants for 'Manish'@'localhost';

grant insert on *.* to 'Manish'@'localhost';
show grants for 'Manish'@'localhost';

grant update on *.* to 'Manish'@'localhost';
show grants for 'Manish'@'localhost';

grant all on *.* to 'Manish'@'localhost';
show grants for 'Manish'@'localhost';

revoke update on *.* from 'Manish'@'localhost';
show grants for 'Manish'@'localhost';

create role 'accountant';

grant select on office to accountant;
show grants for accountant;

create user 'Nishant'@'localhost' identified by '2810';
create role 'financer';
grant 'financer' to 'Nishant'@'localhost';
show grants for 'Nishant'@'localhost';