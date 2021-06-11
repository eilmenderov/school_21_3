#!/bin/bash
echo "ft_server starting"

service mysql start
# create database for WordPress
echo "CREATE DATABASE WordPress;"| mysql -u root
echo "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'Aje3spq77q!l';"| mysql -u root
echo "GRANT ALL PRIVILEGES ON WordPress.* TO 'admin'@'localhost' IDENTIFIED BY 'Aje3spq77q!l';"| mysql -u root
echo "FLUSH PRIVILEGES;"| mysql -u root

service nginx start
service php7.3-fpm start

bash
