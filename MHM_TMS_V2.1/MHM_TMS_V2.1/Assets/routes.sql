create database TMS;

create table route(
available int,
start varchar(50),
destination varchar(50)
)

insert route(available, start, destination) values(1, 'Lahore', 'Karachi');
insert route(available, start, destination) values(1, 'Lahore', 'Murree');
insert route(available, start, destination) values(1, 'Karachi', 'Lahore');
insert route(available, start, destination) values(0, 'Karachi', 'Murree');
insert route(available, start, destination) values(1, 'Murree', 'Lahore');
insert route(available, start, destination) values(0, 'Murree', 'Karachi');

select * from route;