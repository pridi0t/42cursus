FROM debian:buster

RUN apt-get update
RUN apt-get -y install php php-fpm php-mysql php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip

COPY ./conf/latest.tar.gz /
RUN tar -xvf /latest.tar.gz -C /

RUN apt-get -y install wget mariadb-client
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php

COPY ./conf/runtime_conf_copy.sh /
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

ENTRYPOINT ["sh", "/runtime_conf_copy.sh"]
