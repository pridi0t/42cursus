CREATE DATABASE ${MD_DBNAME};
CREATE USER '${MD_ID}'@'%' IDENTIFIED BY '${MD_PW}';
GRANT ALL PRIVILEGES ON wordpress_db.* TO '${MD_ID}'@'%';
flush privileges;
