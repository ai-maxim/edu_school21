#Install Debian buster
From debian:buster

#Update Software Packages
RUN apt-get update && apt-get upgrade -y
RUN apt-get -y install wget
RUN apt-get install mariadb-server mariadb-client -y


#Install Nginx Web server
RUN apt-get -y install nginx


#Install php7.3
RUN apt-get install php7.3 php7.3-fpm php7.3-mysql php7.3-common php7.3-xml php7.3-xmlrpc php7.3-curl php7.3-gd \ 
                    php7.3-imagick php7.3-cli php7.3-dev php7.3-imap php7.3-mbstring php7.3-opcache php7.3-json -y
RUN systemctl restart php7.3-fpm


#Install WordPress
RUN https://wordpress.org/latest.tar.gz wp.tar.gz
RUN xzvf wp.tar.gz
RUN cp wp/wp-config-sample.php /wp/wp-config.php
RUN cp -a /tmp/wordpress/. /var/www/your_domain
RUN chown -R www-data:www-data /var/www/your_domain


#Install phpMyAdmin is dockerhub
#RUN apt-get install phpmyadmin
RUN docker pull phpmyadmin/phpmyadmin


#Secure site with SSL



# docker build -t nginx .
# docker run -it --rm -p 80:80 nginx


#Install database mySQL
# RUN mysql_secure_installation
# RUN mariadb
# RUN CREATE DATABASE ft_server;
# RUN GRANT ALL ON example_database.* TO 'student_school21'@'localhost' IDENTIFIED BY 'password' WITH GRANT OPTION;
# RUN FLUSH PRIVILEGES;
# RUN SHOW DATABASES;