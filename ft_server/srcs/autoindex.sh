#!/bin/bash

read -p 'Write on/off: ' AUTOINDEX

if test $AUTOINDEX = 'on'
	then
	sed -i "s/autoindex off;/autoindex on;/g" /etc/nginx/sites-available/default
	echo "Autoindex enable"
	service nginx restart
elif test $AUTOINDEX = 'off'
	then
	sed -i "s/autoindex on;/autoindex off;/g" /etc/nginx/sites-available/default
	echo "Autoindex diable"
	service nginx restart
else
	echo "Error. You have only two available options 'on' and 'off', try again."
fi
