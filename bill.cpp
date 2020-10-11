#include<iostream>
#include<mysql.h>
#include<string>
#include"bill.h"
#include"useful.h"

using namespace std;

double bill(MYSQL *conn)
{
	int index=CountRows(conn,"SELECT * from Customer_List;");
	MYSQL_ROW row;
	MYSQL_RES *res_set;
	string query="SELECT SUM(Item_Total_Price) FROM Customer_Order where Customer_ID="+to_string(index)+";";
	mysql_query(conn,query.c_str());
	res_set=mysql_store_result(conn);
	row=mysql_fetch_row(res_set);
	string s=row[0];
	double bill=atof(s.c_str());
	return bill;
}
