From alpine:3.12

EXPOSE 80 443

# Install lighttpd, PHP and MySql
# For installing the additional packages first activate community packages:
LABEL maintainer="ft_services - qdong@student.21-school.ru"
RUN		apk update && apk add lighttpd php7.3-common php7.3-session php7.3-iconv php7.3-json php7.3-gd php7.3-curl php7.3-xml php7.3-mysqli php7.3-imap php7.3-cgi \
		fcgi php7.3-pdo php7.3-pdo_mysql php7.3-soap php7.3-xmlrpc php7.3-posix php7.3-mcrypt php7.3-gettext php7.3-ldap php7.3-ctype php7.3-dom \
		mkdir -p /usr/share/webapps/ && cd /usr/share/webapps && wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz \
		tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz \ rm phpMyAdmin-5.0.2-all-languages.tar.gz \
		mv phpMyAdmin-5.0.2-all-languages phpmyadmin && chmod -R 777 /usr/share/webapps/ \
		ln -s /usr/share/webapps/phpmyadmin/ /var/www/localhost/htdocs/phpmyadmin

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
