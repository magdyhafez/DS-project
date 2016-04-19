#ifndef STACK_LINKEDLIST_H_INCLUDED
#define STACK_LINKEDLIST_H_INCLUDED
#include<iostream>
#include<string>
#include "Node.h"
#include "Account.h"
using namespace std;
class linkedlist{
    private:
        Node* head;
		Node* tail;// to make O(1) for function of add @ end
		int capacity;	
        public:
        linkedlist();
        void add_atFront(Account*);
		void add_atEnd(Account*);
        //Account GetlistTop();
        Account RemoveAndGet_front();
       // void printall();
		//int RemoveAndGet_frontID();
        bool islistEmpty();
		int GetCapacity();
        void clearlist();
		Account RemoveAndGet_end();
		Account GetData(int i);
		void SetData(int i,Account value);
		void sortlist();
		int BinarySearch();
		bool LinearSearch(int);
	// Add at end then remove front (linkedlist as:Queue)
	// Add at front then remove front (linkedlist as:stack)
};

    linkedlist::linkedlist(){
        head = NULL;
	tail = NULL;
	capacity = 0;
    }
    
    int linkedlist::GetCapacity(){
		return capacity;
    }
    void linkedlist::add_atFront(Account* value){
		Node* temp = new Node(value->getID(),value->getBalance(),value->getName());
        temp->next = head;
        head = temp;
		capacity++;
    }
    void linkedlist::add_atEnd(Account* value){
		if(islistEmpty())
    		    {
			    add_atFront(value);// bug if no item fixed
			    tail = head;
		    }
    	        else{
           		tail->next = new Node(value->getID(),value->getBalance(),value->getName());
				tail = tail->next; 
				capacity++;
	           }
    }
	/*Account linkedlist::GetlistTop(){
        if (!islistEmpty())
        return head->data;
    }*/
	//int RemoveAndGet_frontID()
	//{
	//	Node* temp;
 //       if(!islistEmpty())
 //       {
	//	/*int value = head->data.getID();
	//	temp = head;
	//	head = head->next;
	//	delete temp;
	//	capacity--;*/
	//	return value;
 //       }
	//}
	Account linkedlist::RemoveAndGet_front(){
       Node* temp;
        if(!islistEmpty())
        {
		Account value;
		value.setBalance(head->data.getBalance());
		value.setName(head->data.getName());
		value.setID(head->data.getID());
		temp = head;
		head = head->next;
		delete temp;
		capacity--;
		return value;
        }
    }
    Account linkedlist::RemoveAndGet_end()
	{
	    Account value;
       	    if(head->next == NULL)
             return RemoveAndGet_front();// bug if no item fixed
    	    else{
            	    Node* temp;
					Node* nodeToRemove;
            		for(temp = head; temp->next->next != NULL; temp = temp->next);
                		nodeToRemove = temp->next ;
					temp->next = NULL;
					value.setBalance(nodeToRemove->data.getBalance());
					value.setName(nodeToRemove->data.getName());
					value.setID(nodeToRemove->data.getID());
					delete nodeToRemove;
					capacity--;
        	}
	     return value;
	}
    /*void linkedlist::printall()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout<< temp -> data << endl;
            temp = temp -> next;
        }
    }*/

    bool linkedlist::islistEmpty()
    {
        return (head == NULL)?true:false;
    }
      void linkedlist::clearlist(){
        while(!islistEmpty())
            RemoveAndGet_front();
    }
	  Account linkedlist::GetData(int i)
	  {
		  Account value;
		  if (this->GetCapacity() < i) return;
		  Node* temp = head;
		  for (int j = 0; j < i; j++)
		  {
			  temp = temp->next;
		  }
			value.setBalance(temp->data.getBalance());
			value.setName(temp->data.getName());
			value.setID(temp->data.getID());
		  return value;
	  }
	  void linkedlist::SetData(int i,Account value)
	  {
		  if (this->GetCapacity() < i) return;
		  Node* temp = head;
		  for (int j = 0; j < i; j++)
		  {
			  temp = temp->next;
		  }
		  temp->data.setBalance(value.getBalance());
		  temp->data.setName(value.getName());
		  temp->data.setID(value.getID());
	  }
	void linkedlist::sortlist()
	{
		Node* stop = NULL;
		int temp_ID = 0; 
		float temp_balance;
		string temp_name;
		if(islistEmpty());
		else if(head->next == NULL);
		else
		{
			while(stop != head->next)
			{
				Node* max = head;
				Node* temp = head->next;
				while (1)
				{
					if (temp->data.getID() > max->data.getID() )
						max = temp;
					if (temp->next == stop)
					{
							stop = temp;
							break;
					}
						temp = temp->next;
				}
				temp_name = max->data.getName();
				temp_ID = max->data.getID();
				temp_balance = max->data.getBalance();
				max->data.setBalance(temp->data.getBalance());
				max->data.setID(temp->data.getID());
				max->data.setName(temp->data.getName());
				temp->data.setBalance(temp_balance);
				temp->data.setID(temp_ID);
				temp->data.setName(temp_name);
			   }
		}
    }
	bool linkedlist::LinearSearch(int value)
	{
		Node* temp = head;
		while(temp != NULL)
		{
			if(temp->data.getID() == value)
				return true;
			temp = temp->next;
		}
		return false;
	}

#endif // STACK_LINKEDLIST_H_INCLUDED
