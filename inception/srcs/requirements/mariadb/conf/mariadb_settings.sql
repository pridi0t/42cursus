CREATE DATABASE wordpress_db;
GRANT ALL ON wordpress_db.* TO 'wordpress_user'@'%' IDENTIFIED BY 'password';
ALTER USER 'root'@'localhost' IDENTIFIED BY 'root';
flush privileges;
