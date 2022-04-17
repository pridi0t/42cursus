#!/bin/bash

if [ ! -e /success ]; then
	nohup /restore.sh &
fi

exec /usr/bin/mysqld_safe
