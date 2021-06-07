
keygen:
	openssl req -x509 -nodes -newkey rsa:2048 -days 365 -keyout ./openssl/localhost.key -out ./openssl/localhost.crt -subj "/C=RU/ST=test/L=test/O=test/CN=test"
up:
	docker-compose -f srcs/docker-compose.yml up
down:
	docker-compose -f srcs/docker-compose.yml down
re:
	docker-compose -f srcs/docker-compose.yml up --build
ps:
	docker-compose -f srcs/docker-compose.yml ps
clean:
	docker container prune -f
	docker volume rm $(docker volume ls -q) -f
	docker system prune -f
	docker rmi $(docker images -a) -f
