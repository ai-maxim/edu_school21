From alpine:3.12

EXPOSE 80 443

COPY wp-config.php telegraf.conf setup.sh ./

# Install PHP
RUN apk update && apk add --no-cache php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session

# Download Wordpress
ADD https://wordpress.org/latest.tar.gz .

# Install Wordpress
RUN tar -xvf latest.tar.gz && mv wordpress /www && \
	mv wp-config.php /www/ && \
	rm -f latest.tar.gz

# Install telegraf
RUN apk add --no-cache --repository http://dl-cdn.alpinelinux.org/alpine/edge/testing/ telegraf && \
	mkdir -p /etc/telegraf && \
	mv telegraf.conf /etc/telegraf/

CMD ./setup.sh

# docker build -t nginx .
# docker run -it --rm -p 80:80 -p 443:443 nginx
# cd /etc/nginx/sites-available# cat default
