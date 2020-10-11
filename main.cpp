#include<iostream>
#include<mysql.h>
#include"connect.h"
#include"customer.h"
#include"order.h"
#include"display.h"
#include"bill.h"

using namespace std;

int main()
{
	MYSQL *conn;
	conn=connection();
	cout<<"Welcome to our Shop, Sir/Madam\n\n";
	Customer cus;
	cus.insert(conn);
	cin.ignore();
	cout<<"\n\n";
	display(conn);
	cout<<"\n\n";
	char ch1='Y';
	while(ch1=='Y')
	{
		Order ord;
		ord.input(conn);
		cout<<"Do you want to buy another item(Y/N)?\n";
		cin>>ch1;
		cin.ignore();
	}
	double total=bill(conn);
	cout<<"Total amount payable : "<<total<<endl;
	cout<<"Please enter the amount for payment\n";
	double payment;
	cin>>payment;
	if(payment>total)
		cout<<"\nYour change : "<<payment-total<<endl;
	cout<<"\n\nPayment successful!!!";
	cout<<"\n";
	cout<<"\nDo you want to give any feedback, Sir/Madam(Y/N)?\n";
	char ch;
	cin>>ch;
	cin.ignore();
	if(ch=='Y')
	{
		cout<<"Enter your feedback, Sir/Madam\n";
		string feedback;
		getline(cin,feedback);
	}
	cout<<"Thank you Sir/Madam. Please visit our shop again\n";
	return 0;
}
