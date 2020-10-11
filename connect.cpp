#include<iostream>
#include<mysql.h>
#include"connect.h"

using namespace std;

MYSQL *connection()
{
	MYSQL *conn;
	conn=mysql_init(NULL);
	conn=mysql_real_connect(conn,"127.0.0.1","root","root","Shop",0,NULL,0);
	return conn;
}
