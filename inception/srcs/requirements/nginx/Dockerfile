FROM debian:buster

RUN apt-get update
RUN apt-get install -y nginx

COPY ./conf/wordpress.conf /etc/nginx/sites-available/
RUN rm /etc/nginx/sites-available/default
RUN rm /etc/nginx/sites-enabled/default
RUN ln -s /etc/nginx/sites-available/wordpress.conf /etc/nginx/sites-enabled/

ENTRYPOINT ["nginx", "-g", "daemon off;"]
