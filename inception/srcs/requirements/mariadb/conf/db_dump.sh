#!/bin/bash

mysqldump -uroot -proot --all-databases > /db/db_backup.sql
echo "flush privileges;" >> /db/db_backup.sql
