FROM debian:buster

RUN apt-get update
RUN apt-get install -y mariadb-server

COPY ./conf/mariadb_settings.sql /
RUN /etc/init.d/mysql start && mysql < /mariadb_settings.sql
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

ENTRYPOINT ["/usr/bin/mysqld_safe"]
