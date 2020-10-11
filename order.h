#include<mysql.h>
#include<iostream>

using namespace std;

class Order
{
	public:
		string item;
		double quantity;
		void input(MYSQL *);
};
