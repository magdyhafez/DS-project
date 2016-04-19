#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include"linkedlist.h"
#include"Account.h"
using namespace std;
int main()
{
	Account b  ;
	b.setName("Magdy");
	b.setID(1);
	b.setBalance(10);
	cout<<"Balance:  "<<b.getBalance()<<"  ID:  "<<b.getID()<<"  Name: "<<b.getName()<<endl;
	//linkedlist lacc ;
	//lacc.add_atEnd(&b); 
	//lacc.clearlist();
	system("PAUSE");
	return 0;
}