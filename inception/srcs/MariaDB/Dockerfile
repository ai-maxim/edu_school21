FROM debian:buster

EXPOSE 3306

ARG MYSQL_PASSWORD=${MYSQL_PASSWORD}
ARG MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}

RUN apt-get update
RUN apt-get install mariadb-server mariadb-client -y

COPY init.sh	/var/www/
COPY damp_db.sql /var/www/

RUN chmod +x /var/www/init.sh
RUN /var/www/init.sh

ENTRYPOINT ["/usr/bin/mysqld_safe", "--bind-address=0.0.0.0"]

