FROM debian:buster

RUN apt-get update
RUN apt-get install -y mariadb-server

COPY ./conf/mariadb_settings.sql /
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

COPY ./conf/db_dump.sh /
COPY ./conf/restore.sh /
COPY ./conf/runtime_conf.sh /

ENTRYPOINT ["sh", "/runtime_conf.sh"]
