# This is a System Administration subject.
You will discover Docker and you will set up your first web server.

## Introduction
This topic is intended to introduce you to system administration.
It will make you aware of the importance of using scripts to automate your tasks.
For that, you will discover the "docker" technology and use it to install a complete web server.
This server will run multiples services: Wordpress, phpMyAdmin, and a SQL database.

## How to use:
```
docker build -t ft_server .
docker run -it -p 443:443 -p 80:80 ft_server
```
or:
```
docker build -t ft_server . && docker run -it -p 443:443 -p 80:80 --rm ft_server && docker rmi ft_server
```
and check your localhost