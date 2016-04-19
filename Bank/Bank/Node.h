#ifndef Node_H_INCLUDED
#define Node_H_INCLUDED
#include<iostream>
#include<string>
#include "Account.h"
using namespace std;
class Node{
    private:
        Node* next;
        Account data;
    public:
		Node(int,float,string);
		void setdata(int,float,string);
        void setptr_node(Node*);

friend class linkedlist;
};
    Node::Node(int id,float b,string n){
		setdata(id,b,n);
        next = NULL;
    }
    void Node::setdata(int id,float b,string n){
		data.setBalance(b);
		data.setID(id);
		data.setName(n);
		//data = value;
    }
    void Node::setptr_node(Node* ptr_node){
        next = ptr_node;
    }

#endif // Node_H_INCLUDED
