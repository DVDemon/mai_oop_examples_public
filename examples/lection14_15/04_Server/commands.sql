use stud; 
show tables;
CREATE TABLE IF NOT EXISTS `Author` (`id` INT NOT NULL AUTO_INCREMENT,`first_name` VARCHAR(256) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,`last_name` VARCHAR(256) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,`email` VARCHAR(256) CHARACTER SET utf8 COLLATE utf8_unicode_ci NULL,`title` VARCHAR(1024) CHARACTER SET utf8 COLLATE utf8_unicode_ci NULL,PRIMARY KEY (`id`),KEY `fn` (`first_name`),KEY `ln` (`last_name`));
describe Author;
select * from Author where id<10;
select id,first_name,last_name from Author where id>=10 and id<20;
explain select * from Author where id=10;
explain select * from Author where first_name='Rhianna';
explain select * from Author where title='Cashaier';
explain select * from Author where id>10 and id<20;
explain select * from Author where first_name='Elle%';
insert into Author (first_name,last_name,email,title) values ('Иван','Иванов','ivanov@yandex.ru','господин');
SELECT LAST_INSERT_ID();
select * from Author where id=LAST_INSERT_ID();
delete from Author where id= 100001;
show index from Author;
drop index email_hash on Author;
create index email_hash USING HASH  on Author(email);
explain select * from Author where email='Chad_Cavanagh1998@nickia.com';
drop index fn_ln on Author;
create index fn_ln using btree on Author(first_name,last_name);
drop index ln_fn on Author;
create index ln_fn using btree on Author(last_name,first_name);
explain format=json select * from Author where first_name='Elle%' and last_name='A%';