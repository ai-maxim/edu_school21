From alpine:3.12

EXPOSE 80 443

RUN apt-get update && apt-get upgrade -y && apt-get -y install wget vim nginx openssl \
	rm -rf ./etc/nginx/sites-enabled/default \
	apt-get install php7.3 php7.3-fpm php7.3-mysql php7.3-common php7.3-xml php7.3-xmlrpc \
	php7.3-curl php7.3-gd php7.3-imagick php7.3-cli php7.3-dev php7.3-imap php7.3-json -y \
	apt-get install mariadb-server -y \
    wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz \
    tar -xzvf phpMyAdmin-5.0.2-all-languages.tar.gz && rm -rf phpMyAdmin-5.0.2-all-languages.tar.gz \
    mv phpMyAdmin-5.0.2-all-languages phpmyadmin \
	wget https://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz && rm -rf latest.tar.gz \
	openssl req -x509 -nodes -newkey rsa:2048 -days 365 -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt -subj "/C=US/ST=California/L=LosAngeles/O=mycompany/OU=443/CN=nginx" \
	chown -R www-data:www-data /var/www/* \
	chmod -R 755 /var/www/html/*

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
