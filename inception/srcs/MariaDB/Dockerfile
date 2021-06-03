FROM debian:buster

EXPOSE 3306

RUN apt-get update
RUN apt-get install mariadb-server mariadb-client -y

COPY init.sh	/var/www/
RUN chmod +x /var/www/init.sh
RUN /var/www/init.sh
ENTRYPOINT ["/usr/bin/mysqld_safe"]

