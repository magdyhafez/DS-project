#include<iostream>
//#include"linkedlist.h"
#include<string>
using namespace std;
class Account{
float balance;
string name;
int ID;
public:
	Account();
	/*Account& operator= (const Account& param)
	{
		name = param.name;
		ID = param.ID;
		balance = param.balance;
	}*/
	//void Depose(float);
	//void Withdraw(float);
	//void Tranfer(int,float);
	//void CreateAccount(int,float);
	//void DeleteAccount(int);
	//float Enquiry();
    void setName(string);
	void setID(int);
	void setBalance(float);
	string getName();
	int getID();
	float getBalance();
};
Account::Account()
{
	balance = 0;
		/*ID = value->ID;
		balance = value->balance;
		name = value->name;*/
}
void Account::setName(string n)
{
	name = n;
}

void Account::setID(int id)
{
	ID = id;
}
void Account::setBalance(float b)
{
	balance = b;
}
string Account::getName()
{
	return name;
}

int Account::getID()
{
	return ID;
}

float Account::getBalance()
{
	return balance;
}
