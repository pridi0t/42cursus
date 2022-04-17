#!/bin/bash

FILE="/var/www/html"

if [ ! -e $FILE/index.php ]; then
	mv /tmp/wordpress $FILE
fi

exec /usr/sbin/php-fpm7.3 -F -R
