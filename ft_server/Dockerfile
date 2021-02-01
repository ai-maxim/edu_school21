From debian:buster
WORKDIR /var/www/html

RUN apt-get update && apt-get upgrade -y
#RUN aptitude install build-essential zip git

#nginx
RUN apt-get -y install wget
RUN apt-get -y install nginx
RUN touch /etc/nginx/sites-available/wordpress.conf
RUN apt-get install mariadb-server mariadb-client -y
RUN service nginx restart

#Install php7.3
RUN apt-get install php7.3 php7.3-fpm php7.3-mysql php7.3-common php7.3-xml php7.3-xmlrpc php7.3-curl php7.3-gd \
                    php7.3-imagick php7.3-cli php7.3-dev php7.3-imap php7.3-mbstring php7.3-opcache php7.3-json -y
RUN systemctl restart php7.3-fpm

#pphpMyAdmin
RUN     wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN     tar xzvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN     mv phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin
RUN     rm -rf phpMyAdmin-5.0.2-all-languages.tar.gz
COPY    ./srcs/config.inc.php /var/www/html/phpmyadmin

#Install WordPress
RUN wget https://wordpress.org/latest.tar.gz wp.tar.gz
RUN xzvf wp.tar.gz
RUN cp wordpress
RUN cp -a /tmp/wordpress/. /var/www/localhost
RUN chown -R www-data:www-data /var/www/localhost
COPY ./srcs/wp-config.php /var/www/html/wordpress

#Secure site with SSL
COPY  /etc/nginx/ssl/domain.key;

# docker build -t nginx .
# docker run -it --rm -p 80:80 nginx
# cd /etc/nginx/sites-available# cat default
