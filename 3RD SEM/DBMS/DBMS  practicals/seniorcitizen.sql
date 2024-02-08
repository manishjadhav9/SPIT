use elderlycare;
create table seniorcitizen(
	sid int primary key not null, name varchar(100), dob varchar(12), age int, gender varchar(5),  address varchar(20), martial_status varchar(10), time_slots varchar(25),
    health_issue varchar(100), intrests varchar(100)
);
insert into seniorcitizen(sid, name, dob, age, gender, address, martial_status, time_slots, health_issue, intrests) values (1, 'Krunal', '1954-18-05', 69, 'M', 'Kolad', 'Single',
'12pm to 6pm', 'Lower Back Injury', 'Back Massage'),
(2, 'Om', '1956-20-09', 67, 'M', 'Panvel', 'Married', '5pm to 9pm', 'Knee Pain', 'Legs Massage'),
(3, 'Saee', '1950-03-02', 73, 'F', 'Panvel', 'Married', '6pm to 10pm', 'Migrane', 'Head Massage'),
(4, 'Vishakha', '1960-29-07', 63, 'F', 'Mahad', 'Single', '2pm to 10pm', 'Vasculities', 'Legs Massage'),
(5, 'Apurva', '1950-13-02', 73, 'F', 'Mahad', 'Single', '8pm to 11pm', 'Hypertension Headache', 'Full Body Massage'),
(6, 'Vishesh', '1948-03-12', 75, 'M', 'Thane', 'Married', '3pm to 8pm', 'Chest Pain', 'Full Body Massage'),
(7, 'Shrijal', '1957-03-02', 66, 'F', 'Thane', 'Single', '6pm to 8pm', 'Varicose', 'Full Body Massage'),
(8, 'Sejal', '1954-24-08', 69, 'F', 'Matunga', 'Married', '6pm to 9pm', 'Sinus', 'Head Massage'),
(9, 'Jay', '1945-27-03', 78, 'M', 'Kalyan', 'Single', '4pm to 8pm', 'Joints Pain', 'Legs Massage'),
(10, 'Harshal', '1965-03-02', 58, 'M', 'Mahad', 'Married', '6pm to 10pm', 'Upper Back Injury', 'Back Massage');
select * from seniorcitizen;

alter table seniorcitizen rename to seniorcitizens;
describe seniorcitizens;

alter table seniorcitizens modify gender char(3);
describe seniorcitizens;

alter table seniorcitizens change column address location varchar(20);
describe seniorcitizens;

alter table seniorcitizens add contact varchar(25);
describe seniorcitizens;

insert into seniorcitizens(sid, name, dob, age, gender, location, martial_status, time_slots, health_issue, intrests, contact) values (11, 'Swayam,', '1954-19-05', 69, 'M', 'Thane', 'Single',
'12pm to 6pm', 'Lower Back Injury', 'Back Massage', '123456789');
select * from seniorcitizens;

delete from seniorcitizens where sid=11;
select * from seniorcitizens;

select * from seniorcitizens where intrests='Full Body Massage';
select * from seniorcitizens where age between 70 and 80;

update seniorcitizens set location='Vrindavan', health_issue='Hypertension Headache' where sid=9;
select * from seniorcitizens;

select count(gender) from seniorcitizens;
select max(age) from seniorcitizens;
select min(age) from seniorcitizens;
