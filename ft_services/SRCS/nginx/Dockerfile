From alpine:3.12

EXPOSE 80 443

LABEL maintainer="ft_services - qdong@student.21-school.ru"
RUN apk update && apk add nginx && adduser -D -g 'www' www && mkdir /www && chown -R www:www /var/lib/nginx && chown -R www:www /www

COPY nginx.conf /etc/nginx/nginx.conf
COPY index.html /www

# docker build -t nginx .
# docker run -it --rm -p 80:80 -p 443:443 nginx
# cd /etc/nginx/sites-available# cat default
