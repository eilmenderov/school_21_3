FROM debian:buster

RUN apt-get update && apt-get install -y \
	nginx \
	mariadb-server \
	php-fpm php php-cgi php-mysqli php-pear php-mbstring php-gettext php-common php-phpseclib php-mysql \
	wget \
	&& rm -rf /var/lib/apt/lists/*

COPY ./srcs/nginx.conf /etc/nginx/sites-available/default
RUN rm /var/www/html/index.nginx-debian.html
RUN	openssl req -x509 -nodes -days 365 \
	-subj "/C=RU/ST=Russia/L=Kazan/O=21 School/OU=Universe/CN=vleida" \
	-newkey rsa:2048 -keyout /etc/ssl/nginx-self.key -out /etc/ssl/nginx-self.crt;

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-english.tar.gz
RUN tar -xf phpMyAdmin-5.1.0-english.tar.gz && rm -rf phpMyAdmin-5.1.0-english.tar.gz
RUN mv phpMyAdmin-5.1.0-english/ /var/www/html/phpmyadmin
COPY ./srcs/config.inc.php /var/www/html/phpmyadmin
RUN ln -s /usr/share/phpmyadmin /var/www/html/phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
RUN mv wordpress /var/www/html/
COPY ./srcs/wp-config.php /var/www/html/wordpress

RUN chown -R www-data:www-data /var/www/html/*

COPY ./srcs/*.sh ./

ENTRYPOINT sh start.sh

EXPOSE 80 443
