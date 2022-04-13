FROM debian:buster

RUN apt update && \
    apt install -y mariadb-server

COPY ./conf/mariadb_settings.sql /
#ENTRYPOINT 

