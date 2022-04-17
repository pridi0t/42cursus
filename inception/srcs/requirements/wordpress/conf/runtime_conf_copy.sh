#!/bin/bash

FILE="/var/www/html/wordpress"

if [ ! -e $FILE/index.php ]; then
	cp -r /wordpress/* $FILE
	cd /var/www/html/wordpress
	sleep 14s;
	wp config create --dbname="${MD_DBNAME}" --dbuser="${MD_ID}" --dbpass="${MD_PW}" --dbhost="${MD_HOST}" --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root
	wp core install --url="https://hyojang.42.fr" --title="inception" --admin_user="${WP_ADMIN_ID}" --admin_password="${WP_ADMIN_PW}" --admin_email="hyojang@test.com" --skip-email --allow-root
	wp user create "guest" "guest@test.com" --role=author --user_pass="guest" --allow-root
fi

exec /usr/sbin/php-fpm7.3 -F -R
