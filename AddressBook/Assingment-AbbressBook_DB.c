                                                    Assignment- AddressBook Service DB  



#UC1- Ability to create AddressBook Service DB.

create database address_book_service;       # create database.
show databases;                          # to see all avilable data bases.
use Employee_Pay_Roll;			 # to use Employee_Pay_Roll DB.
select database();
                       # to check which data base was selected or working with.


***************************************************************************
#UC2-Ability to create a AddressBook  Table with first name ,last name,city,state,address,zipcode,mail id.

 create table addressbook
     (
     first_name varchar(30),
     last_name varchar(30),
     address varchar(30),
     city varchar(30),
     state varchar(30_),
     zip int,
     phone_number int,
     email_id varchar(50)
     );

mysql> desc  addressbook;
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| first_name   | varchar(30) | YES  |     | NULL    |       |
| last_name    | varchar(30) | YES  |     | NULL    |       |
| address      | varchar(30) | YES  |     | NULL    |       |
| city         | varchar(30) | YES  |     | NULL    |       |
| state        | varchar(30) | YES  |     | NULL    |       |
| zip          | int         | YES  |     | NULL    |       |
| phone_number | int         | YES  |     | NULL    |       |
| email_id     | varchar(50) | YES  |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+
8 rows in set (0.03 sec)

***************************************************************************

#UC3- Ability to insert new contacts to AddressBook.

insert into  addressbook values('Kartik','Kavimandan','Jather peth','Akola','Maharashtra',444001,7768059099,'kartik123@gmail.com'),
insert into  addressbook values('Rushi','Tayde','Shivagi nagar','Amravati','Maharashtra',444002,77777777,'rushi123@gmail.com');
insert into  addressbook values('Akki','Raut','joyti nagar','Vadgao','Maharashtra',444003,88888888,'akki123@gmail.com');
insert into  addressbook values('Lalit','Das','Embrald pla','Mumbai','Maharashtra',444004,9999999,'lalit123@gmail.com');
insert into  addressbook values('Adi','Tekade','Narayan peth','Nagpur','Maharashtra',444005,6666666,'adi123@gmail.com');


mysql> select * from  addressbook;
+------------+------------+---------------+----------+-------------+--------+--------------+---------------------+
| first_name | last_name  | address       | city     | state       | zip    | phone_number | email_id            |
+------------+------------+---------------+----------+-------------+--------+--------------+---------------------+
| Kartik     | Kavimandan | Jather peth   | Akola    | Maharashtra | 444001 |     77680599 | kartik123@gmail.com |
| Rushi      | Tayde      | Shivagi nagar | Amravati | Maharashtra | 444002 |     77777777 | rushi123@gmail.com  |
| Akki       | Raut       | joyti nagar   | Vadgao   | Maharashtra | 444003 |     88888888 | akki123@gmail.com   |
| Lalit      | Das        | Embrald pla   | Mumbai   | Maharashtra | 444004 |      9999999 | lalit123@gmail.com  |
| Adi        | Tekade     | Narayan peth  | Nagpur   | Maharashtra | 444005 |      6666666 | adi123@gmail.com    |
+------------+------------+---------------+----------+-------------+--------+--------------+---------------------+
5 rows in set (0.00 sec)

***************************************************************************

#UC4- Ability to edit existing contact person using their name.
--------------------------------------------------------------


mysql> update addressbook set phone_number=776805909 where first_name='Rushi';

mysql>select * from  addressbook;

***************************************************************************

#UC5- Ability to delete a person using the person's name.

mysql> delete from addressbook where first_name='Kartik';
Query OK, 1 row affected (0.02 sec)

mysql> select * from  addressbook;
+------------+-----------+---------------+----------+-------------+--------+--------------+--------------------+
| first_name | last_name | address       | city     | state       | zip    | phone_number | email_id           |
+------------+-----------+---------------+----------+-------------+--------+--------------+--------------------+
| Rushi      | Tayde     | Shivagi nagar | Amravati | Maharashtra | 444002 |     77777777 | rushi123@gmail.com |
| Akki       | Raut      | joyti nagar   | Vadgao   | Maharashtra | 444003 |     88888888 | akki123@gmail.com  |
| Lalit      | Das       | Embrald pla   | Mumbai   | Maharashtra | 444004 |      9999999 | lalit123@gmail.com |
| Adi        | Tekade    | Narayan peth  | Nagpur   | Maharashtra | 444005 |      6666666 | adi123@gmail.com   |
+------------+-----------+---------------+----------+-------------+--------+--------------+--------------------+
4 rows in set (0.00 sec)

***************************************************************************

#UC6- Ability to Retrieve Person belonging to a City or State from the Address Book.



mysql> select * from addressbook where city='Nagpur';
+------------+-----------+--------------+--------+-------------+--------+--------------+------------------+
| first_name | last_name | address      | city   | state       | zip    | phone_number | email_id         |
+------------+-----------+--------------+--------+-------------+--------+--------------+------------------+
| Adi        | Tekade    | Narayan peth | Nagpur | Maharashtra | 444005 |      6666666 | adi123@gmail.com |
+------------+-----------+--------------+--------+-------------+--------+--------------+------------------+
1 row in set (0.00 sec)

***************************************************************************

#UC7-Ability to understand the size of address book by City and State  from addressbook' at line 1.

mysql> select count(city),count(state) from addressbook;
+-------------+--------------+
| count(city) | count(state) |
+-------------+--------------+
|           4 |            4 |
+-------------+--------------+
1 row in set (0.00 sec)

***************************************************************************

#UC8- Ability to retrieve entries sorted alphabetically by Person’s name for a given city.

mysql> select first_name from addressbook order by city ASC;
+------------+
| first_name |
+------------+
| Rushi      |
| Lalit      |
| Adi        |
| Akki       |
+------------+
4 rows in set (0.00 sec)

mysql> select first_name from addressbook where state = 'Maharashtra' order by first_name;
+------------+
| first_name |
+------------+
| Adi        |
| Akki       |
| Lalit      |
| Rushi      |
+------------+
4 rows in set (0.00 sec)
***************************************************************************


#UC9-Ability to identify each Address Book with name and Type.


 alter table addressbook add type varchar(150) after last_name

mysql> update addressbook set type ='Family' where first_name ='Rushi';

mysql> update addressbook set type ='Friend' where first_name ='Akki';

mysql> update addressbook set type ='Clerk' where first_name ='family';


mysql> select * from addressbook;
+------------+-----------+--------+---------------+----------+-------------+--------+--------------+--------------------+
| first_name | last_name | type   | address       | city     | state       | zip    | phone_number | email_id           |
+------------+-----------+--------+---------------+----------+-------------+--------+--------------+--------------------+
| Rushi      | Tayde     | Family | Shivagi nagar | Amravati | Maharashtra | 444002 |    776805909 | rushi123@gmail.com |
| Akki       | Raut      | Friend | joyti nagar   | Vadgao   | Maharashtra | 444003 |     88888888 | akki123@gmail.com  |
| Lalit      | Das       | NULL   | Embrald pla   | Mumbai   | Maharashtra | 444004 |      9999999 | lalit123@gmail.com |
| Adi        | Tekade    | NULL   | Narayan peth  | Nagpur   | Maharashtra | 444005 |      6666666 | adi123@gmail.com   |
+------------+-----------+--------+---------------+----------+-------------+--------+--------------+--------------------+
4 rows in set (0.00 sec)


mysql> select * from addressbook where type = 'Family';
+------------+-----------+--------+---------------+----------+-------------+--------+--------------+--------------------+
| first_name | last_name | type   | address       | city     | state       | zip    | phone_number | email_id           |
+------------+-----------+--------+---------------+----------+-------------+--------+--------------+--------------------+
| Rushi      | Tayde     | Family | Shivagi nagar | Amravati | Maharashtra | 444002 |    776805909 | rushi123@gmail.com |
+------------+-----------+--------+---------------+----------+-------------+--------+--------------+--------------------+
1 row in set (0.00 sec)



***************************************************************************

UC10- Ability to get number of contact persons i.e. count by type.

mysql> select type,count(*) from addressbook group by type;
+--------+----------+
| type   | count(*) |
+--------+----------+
| Family |        1 |
| Friend |        1 |
| NULL   |        2 |
+--------+----------+
3 rows in set (0.00 sec)

***************************************************************************

#UC-11-Ability to add person to both Friend and Family.


***************************************************************************

#UC-12- Draw ER diagram.

create table address_books
 
(

address_book_id int not null auto_increment primary key,

address_book_name varchar(30) not null
);

desc address_books;

mysql> insert into address_books (address_book_name)
    -> values("Oberoi's_Book"),
    -> ("Mickal's_Book");




create table contacts

(

contact_id int not null auto_increment primary key,

first_name varchar(30) not null,

last_name varchar(30),

address varchar(50),

city varchar(20),

state varchar(20),

zip_code int,

phone_number varchar(30),

email varchar(30)

);

desc contacts;



mysql> insert into contacts(first_name,last_name,address,city,state,zip_code,phone_number,email)
    -> values('Rushi','Tayde','Laxmi Nagar','Amravati','MH','444002','8888888888','rushi123@gmail.com');


mysql> insert into contacts(first_name,last_name,address,city,state,zip_code,phone_number,email)
    -> values('Akshay','Raut','Viman Nagar','Pune','PU','444004','6666666666','akshay123@gmail.com');

mysql> insert into contacts(first_name,last_name,address,city,state,zip_code,phone_number,email)
    -> values ('Kartik','Kavimandan','MG Nagar','Akola','MH',444001,'9999999999','kartik123@gmail.com'),
        ('Adi', 'Roy', 'NN Nagar', 'Nagpur', 'KA', '444003', '7777777777', 'adi123@gmail.com');


mysql> select * from contacts;
+------------+------------+------------+-------------+----------+-------+----------+--------------+---------------------+
| contact_id | first_name | last_name  | address     | city     | state | zip_code | phone_number | email               |
+------------+------------+------------+-------------+----------+-------+----------+--------------+---------------------+
|          1 | Kartik     | Kavimandan | MG Nagar    | Akola    | MH    |   444001 | 9999999999   | kartik123@gmail.com |
|          2 | Adi        | Roy        | NN Nagar    | Nagpur   | KA    |   444003 | 7777777777   | adi123@gmail.com    |
|          3 | Rushi      | Tayde      | Laxmi Nagar | Amravati | MH    |   444002 | 8888888888   | rushi123@gmail.com  |
|          4 | Akshay     | Raut       | Viman Nagar | Pune     | PU    |   444004 | 6666666666   | akshay123@gmail.com |
+------------+------------+------------+-------------+----------+-------+----------+--------------+---------------------+
4 rows in set (0.00 sec)




create table contact_category

(

contact_category_id int not null auto_increment primary key,

contact_category_name varchar(20)

);

desc contact_category;



mysql> insert into contact_category(contact_category_name)
    -> values
    -> ('Friend'),
    -> ('Family'),
    ->('Neighbours');

mysql> select * from contact_category;
+---------------------+-----------------------+
| contact_category_id | contact_category_name |
+---------------------+-----------------------+
|                   1 | Friend                |
|                   2 | Family                |
|                   3 | Neighbours            |
+---------------------+-----------------------+



create table address_book_contacts_category
(

contact_id int not null,
address_book_id int not null,

contact_category_id int not null,

foreign key (contact_id) references contacts(contact_id),

foreign key (address_book_id) references address_books(address_book_id),

foreign key (contact_category_id) references contact_category(contact_category_id)
);

desc address_book_contact_category;


mysql> insert into address_book_contacts_category(contact_id,address_book_id,contact_category_id)
    -> values(1,1,1),
    -> (2,1,1),
    -> (3,1,1),
    -> (2,1,2),
    -> (2,2,3),
    -> (2,2,2),
    -> (3,2,3);
mysql> select * from address_book_contacts_category;
+------------+-----------------+---------------------+
| contact_id | address_book_id | contact_category_id |
+------------+-----------------+---------------------+
|          1 |               1 |                   1 |
|          2 |               1 |                   1 |
|          3 |               1 |                   1 |
|          2 |               1 |                   2 |
|          2 |               2 |                   3 |
|          2 |               2 |                   2 |
|          3 |               2 |                   3 |
+------------+-----------------+---------------------+
7 rows in set (0.00 sec)