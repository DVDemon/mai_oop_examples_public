import pandas as pd
from sqlalchemy import create_engine
engine = create_engine("mysql+pymysql://stud:stud@127.0.0.1:3360/archdb", echo = True)


# with engine.connect() as con:
#     con.execute('''CREATE TABLE IF NOT EXISTS `User` (`id` INT NOT NULL AUTO_INCREMENT,
#     `first_name` VARCHAR(256) NOT NULL,
#     `last_name` VARCHAR(256) NOT NULL,
#     `login` VARCHAR(256)  NULL,
#     `password` VARCHAR(256)  NULL,
#     `email` VARCHAR(256) NULL,
#     `title` VARCHAR(1024) NULL,
#     PRIMARY KEY (`id`))''')

df = pd.read_json("ExportJson.json")
df.to_sql("User", con=engine, if_exists = 'replace', index=False)

with engine.connect() as con:
    con.execute("ALTER TABLE `User` ADD  `id` INT PRIMARY KEY  AUTO_INCREMENT")
    con.execute("ALTER TABLE `User` CHANGE first_name first_name VARCHAR(256)")
    con.execute("ALTER TABLE `User` CHANGE last_name last_name VARCHAR(256)")
    con.execute("ALTER TABLE `User` CHANGE email email VARCHAR(256)")
    con.execute("ALTER TABLE `User` CHANGE title title VARCHAR(256)")
    con.execute("ALTER TABLE `User` CHANGE login login VARCHAR(256)")
    con.execute("ALTER TABLE `User` CHANGE password password VARCHAR(256)")
