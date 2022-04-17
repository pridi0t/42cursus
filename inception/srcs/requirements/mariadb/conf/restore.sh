sed "s/MD_DBNAME/${MD_DBNAME}/g" /mariadb_settings.sql > /tmp1
sed "s/MD_ID/${MD_ID}/g" /tmp1 > /tmp2
sed "s/MD_PW/${MD_PW}/g" /tmp2 > /converted_mariadb_settings.sql
rm /tmp1 /tmp2

sleep 9s

if [ -e /db/db_backup.sql ]; then
	mysql < /db/db_backup.sql
else
	mysql < /converted_mariadb_settings.sql
fi

echo "ALTER USER 'root'@'localhost' IDENTIFIED BY 'root';" | mysql
echo "success" > /success
