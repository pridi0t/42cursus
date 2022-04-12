FROM debian:buster

RUN apt update && \
	apt install -y nginx

ENTRYPOINT ["nginx", "-g", "daemon off;"]
