From alpine:3.12

EXPOSE 80 443

# Install lighttpd, PHP and MySql
# For installing the additional packages first activate community packages:
LABEL maintainer="ft_services - qdong@student.21-school.ru"
RUN		apk update && 

COPY	./srcs/default ./etc/nginx/sites-enabled
ADD		./srcs/database.sql /tmp/
WORKDIR	/var/www/html
COPY	./srcs/config.inc.php /var/www/html/phpmyadmin
COPY	./srcs/wp-config.php /var/www/html/wordpress
COPY	./srcs/init.sh ./
CMD		bash init.sh

# docker build -t nginx .
# docker run -it --rm -p 80:80 -p 443:443 nginx
# cd /etc/nginx/sites-available# cat default
