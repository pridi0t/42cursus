CREATE DATABASE wordpress_db;
GRANT ALL ON wordpress_db.* TO 'mariadb_user'@'localhost' IDENTIFIED BY 'password';
set password for 'root'@'localhost' = password('root');
flush privileges;
