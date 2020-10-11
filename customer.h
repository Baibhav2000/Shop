#include<iostream>
#include<mysql.h>

using namespace std;

class Customer
{
	public:
		string fname,midname,lname,ph_no;
		void insert(MYSQL *);
};
