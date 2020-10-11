#include<iostream>
#include<mysql.h>
#include"order.h"
#include"useful.h"
#include<string>

using namespace std;

void Order::input(MYSQL *conn)
{
	MYSQL_ROW row;
	MYSQL_RES *res_set;
	int cus_index=CountRows(conn,"SELECT * FROM Customer_List;");
	int order_index=CountRows(conn,"SELECT * FROM Customer_Order;")+1;
	cout<<"Enter the item you want to buy\n";
	getline(cin,item);
	double stock,remain,per,price;
	string s="SELECT * FROM Item WHERE UPPER(Item_Name)=UPPER('"+item+"');";
	int r=Find(conn,s);
	if(r==0)
	{
		cout<<"Item is not available here\n";
		quantity=0;
	}
	else
	{
		cout<<"Enter the quantity of the item you want to buy\n";
		cin>>quantity;
		cin.ignore();
		mysql_query(conn,s.c_str());
		res_set=mysql_store_result(conn);
		row=mysql_fetch_row(res_set);
		string sample=row[2];
		stock=atof(sample.c_str());
		string unit;
		if(row[3]==NULL)
			unit="NULL";
		else
			unit=row[3];
		string item_ID=row[0];
		string p=row[5];
		per=atof(p.c_str());
		string search1="SELECT * from Item where UPPER(Item_Name)=UPPER('"+item+"') and Quantity>="+to_string(quantity)+";";
		string search2="SELECT * from Item WHERE UPPER(Item_Name)=UPPER('"+item+"') and Quantity=0;";
		string search3="Select * from Item WHERE UPPER(Item_Name)=UPPER('"+item+"') and quantity<"+to_string(quantity)+";";
		if(Find(conn,search2)==1)
		{
			cout<<"Item is out of stock\n";
			quantity=0;
			remain=stock-quantity;
		}
		else if(Find(conn,search1)==1)
		{
			remain=stock-quantity;
		}
		else if(Find(conn,search3)==1)
		{
			cout<<"There are "<<stock<<" such items available. Do you still want to buy(Y/N)?\n";
			char choice;
			cin>>choice;
			if(choice=='Y')
			{
				quantity=stock;
				remain=stock-quantity;
			}
			else
			{
				quantity=0;
				remain=stock-quantity;
			}
		}
		if(quantity!=0)
		{
			price=quantity*per;
			string add;
			if(unit=="NULL")
				add="INSERT INTO Customer_Order VALUES("+to_string(order_index)+","+to_string(cus_index)+","+item_ID+","+to_string(quantity)+",NULL,"+to_string(price)+");";
			else
				add="INSERT INTO Customer_Order VALUES("+to_string(order_index)+","+to_string(cus_index)+","+item_ID+","+to_string(quantity)+",'"+unit+"',"+to_string(price)+");";
			mysql_query(conn,add.c_str());
			string update="UPDATE Item SET Quantity="+to_string(remain)+" WHERE UPPER(Item_Name)=UPPER('"+item+"');";
			mysql_query(conn,update.c_str());
		}
	}
}
