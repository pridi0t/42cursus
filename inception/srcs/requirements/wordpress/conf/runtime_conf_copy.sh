#!/bin/bash

FILE="/var/www/html/wordpress"

nohup /runtime_wp_conf.sh &

exec /usr/sbin/php-fpm7.3 -F -R
