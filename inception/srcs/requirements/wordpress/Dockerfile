FROM debian:buster

RUN apt-get update
RUN apt-get install -y php php-fpm php-mysql php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip

RUN apt-get install wget
RUN wget https://wordpress.org/latest.tar.gz -P /tmp
RUN tar -zxvf /tmp/latest.tar.gz -C /tmp/
RUN mkdir -p /run/php
#RUN mv /tmp/wordpress /var/www/html

COPY ./conf/runtime_conf_copy.sh /
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
COPY ./conf/wp-config.php /tmp/wordpress/
#COPY ./conf/wp-config.php /var/www/html/wordpress/

RUN chown -R www-data:www-data /tmp/wordpress/
RUN chmod -R 755 /tmp/wordpress/
#RUN chown -R www-data:www-data /var/www/html/wordpress/
#RUN chmod -R 755 /var/www/html/wordpress/

ENTRYPOINT ["sh", "/runtime_conf_copy.sh"]
