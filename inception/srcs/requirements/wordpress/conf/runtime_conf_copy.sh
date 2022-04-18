#!/bin/bash

nohup /runtime_wp_conf.sh &

exec /usr/sbin/php-fpm7.3 -F -R
