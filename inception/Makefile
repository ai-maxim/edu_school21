keygen:
	mkdir -p /home/mix/data/wp
	mkdir -p /home/mix/data/db
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
	@docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volume ls -q);\
	docker network rm $$(docker network ls -q)
