#!/bin/bash

if [ $AUTOINDEX == 1 ]; then
	cp /tmp/auto /etc/nginx/sites-enabled/default
else
	cp /tmp/no_auto /etc/nginx/sites-enabled/default
fi

service nginx start
service php7.3-fpm start
service mysql start
tail -f /dev/null
