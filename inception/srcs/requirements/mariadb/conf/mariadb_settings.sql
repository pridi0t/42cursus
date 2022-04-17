CREATE DATABASE wordpress_db;
CREATE USER 'wordpress_user'@'%' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON wordpress_db.* TO 'wordpress_user'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY 'root';
flush privileges;
