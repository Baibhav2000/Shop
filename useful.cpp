#include<iostream>
#include<mysql.h>
#include"useful.h"

using namespace std;

MYSQL_ROW row;
MYSQL_RES *res_set;

int CountRows(MYSQL *conn,const char *c)
{
	mysql_query(conn,c);
	res_set=mysql_store_result(conn);
	int rows=0;
	while((row=mysql_fetch_row(res_set))!=NULL)
	{
		rows++;
	}
	return rows;
}

int Find(MYSQL *conn,string s)
{
	mysql_query(conn,s.c_str());
	res_set=mysql_store_result(conn);
	row=mysql_fetch_row(res_set);
	if(row!=NULL)
		return 1;
	else
		return 0;
}
