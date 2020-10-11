#include<iostream>
#include<mysql.h>
#include"display.h"

void display(MYSQL *conn)
{
	MYSQL_ROW row;
	MYSQL_RES *res_set;
	cout<<"Item_ID"<<" "<<"Item_Name"<<" "<<"Quantity"<<" "<<"Unit"<<" "<<"Category"<<" "<<"Item_Price"<<endl;
	mysql_query(conn,"SELECT * FROM Item;");
	res_set=mysql_store_result(conn);
	while((row=mysql_fetch_row(res_set))!=NULL)
	{
		int i;
		for(i=0;i<6;i++)
		{
			if(row[i]==NULL)
				cout<<"NULL"<<"\t";
			else
				cout<<row[i]<<"\t";
		}
		cout<<"\n";
	}
}
