sleep 5s

if [ -e /db/db_backup.sql ]; then
	mysql < /db/db_backup.sql
fi

echo "ALTER USER 'root'@'localhost' IDENTIFIED BY 'root';" | mysql
echo "success" > /success
