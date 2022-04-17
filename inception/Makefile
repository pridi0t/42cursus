all: start

settings:
	echo "127.0.0.1 hyojang.42.fr" >> /etc/hosts
	mkdir -p /home/hyojang/data/db
	mkdir -p /home/hyojang/data/wordpress

start:
	docker-compose -f srcs/docker-compose.yml up -d

stop:
	docker exec mariadb /db_dump.sh
	docker-compose -f srcs/docker-compose.yml down

clean:
	docker-compose -f srcs/docker-compose.yml down --rm all -v
	rm -rf /home/hyojang/data/wordpress/*
	rm -rf /home/hyojang/data/db/*

.PHONY: settings start stop clean
