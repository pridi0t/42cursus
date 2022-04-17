#!/bin/bash

FILE="/var/www/html/wordpress"

if [ ! -e $FILE/index.php ]; then
	cd /var/www/html/wordpress
	wp core download --allow-root
	wp config create --dbname="wordpress_db" --dbuser="wordpress_user" --dbpass="password" --dbhost="192.168.1.3" --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root
	wp core install --url="localhost" --title="inception" --admin_user="hyojang" --admin_password="hyojang" --admin_email="hyojang@test.com" --skip-email --allow-root
	wp user create "guest" "guest@test.com" --role=author --user_pass="guest" --allow-root
fi

exec /usr/sbin/php-fpm7.3 -F -R
