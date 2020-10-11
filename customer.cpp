#include<iostream>
#include<mysql.h>
#include"useful.h"
#include"customer.h"
#include<string>

using namespace std;

void Customer::insert(MYSQL *conn)
{
	int index=CountRows(conn,"SELECT * FROM Customer_List;")+1;
	cout<<"Enter your first name\n";
	cin>>fname;
	cout<<"Do you have a middle name(Y/N)?\n";
	char ch;
	cin>>ch;
	if(ch=='Y')
	{
		cout<<"Enter your middle name\n";
		cin>>midname;
	}
	else
		midname="NULL";
	cout<<"Enter customer's last name\n";
	cin>>lname;
	cout<<"Enter customer's phone number\n";
	cin>>ph_no;
	string add;
	if(midname!="NULL")
		add="INSERT INTO Customer_List values("+to_string(index)+",'"+fname+"','"+midname+"','"+lname+"',"+ph_no+");";
	else
		add="INSERT INTO Customer_List VALUES("+to_string(index)+",'"+fname+"',NULL,'"+lname+"',"+ph_no+");";
	mysql_query(conn, add.c_str());
}
