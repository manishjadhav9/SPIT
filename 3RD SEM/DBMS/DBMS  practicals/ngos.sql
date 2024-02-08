create database elderlycare;
use elderlycare;
create table ngo(
	id int primary key, location varchar(20), noof_workers int, care_fund varchar(100), contribution varchar(100)
);
insert into ngo(id, location, noof_workers, care_fund, contribution) values (1, 'Mahad', '20', 100000, 'Healthcare'),
(2,  'Mumbai', '15', 1000000, 'Justice'),
(3, 'Pune', '30', 50000, 'Provide Meal'),
(4,  'Delhi', '10', 100000, 'Non-Maleficence'),
(5,  'Andheri', '10', 150000, 'Healthcare'),
(6,  'Thane', '8', 200000, 'Provide Meal'),
(7,  'Mumbai', '30', 380000, 'Healthcare'),
(8, 'Ayodhya', '40', 128000, 'Justice'),
(9,  'Pune', '20', 500000, 'Healthcare'),
(10, 'Gurugram', '30', 1000000, 'Provide Meal');
select * from ngo;

alter table ngos rename to ngos;
describe ngos;

alter table ngos modify contribution varchar(20);
describe ngos;
alter table ngos change column noof_workers no_of_workers int(11);
describe ngos;

alter table ngos add contact varchar(255);
describe ngos;

insert into ngos(id, location, no_of_workers, care_fund, contribution) values (11, 'Kalyan', '4', 40000, 'Provide Meal');
select * from ngos;

delete from ngos where id=11;
select * from ngos;
