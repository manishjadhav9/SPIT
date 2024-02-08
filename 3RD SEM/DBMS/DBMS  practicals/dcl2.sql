use exp3;
insert into office (id, name) values (1, 'Manish');
select * from office;

show grants for 'Manish'@'localhost';
update office set name='Nishant' where id=1;