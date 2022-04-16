FROM debian:buster

RUN apt-get update
RUN apt-get install -y php php-fpm php-mysql php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip

RUN apt-get install wget
RUN wget https://wordpress.org/latest.tar.gz -P /tmp
RUN tar -zxvf /tmp/latest.tar.gz -C /tmp/
RUN mkdir -p /var/www/html
RUN mv /tmp/wordpress /var/www/html

RUN chown -R www-data:www-data /var/www/html/wordpress/
RUN chmod -R 755 /var/www/html/wordpress/

RUN cp ./conf/wp-config.php /var/www/html/wordpress/
