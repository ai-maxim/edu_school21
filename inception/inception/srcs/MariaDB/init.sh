#!bin/bash
# Configure a wordpress database
service mysql start
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "CREATE USER 'mix'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'mix'@'%' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
mysql -u root wordpress < /var/www/damp_db.sql
# echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';FLUSH PRIVILEGES;"| mysql -u root --skip-password 
#echo "SET PASSWORD FOR 'root'@'localhost'= PASSWORD('$MYSQL_ROOT_PASSWORD');FLUSH PRIVILEGES;"| mysql -u root --skip-password
mysqladmin -u root password $MYSQL_ROOT_PASSWORD
service mysql stop
