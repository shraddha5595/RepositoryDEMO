/*2. Write a Program in CPP to implement singly linked list and implement the following functions on the linked list
**insert by pos
insert by value
**delete by pos
delete by value
**display the list
**display the list in reverse order*/

#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
class linkedlist
{
	node *head;
	public:
		 linkedlist();
		 void addatbegin(int);
		 void addatpos(int,int);		 
		 void removefrompos(int);
		 void display();
		 void reverse();
		 
};

linkedlist::linkedlist()
{
	head=NULL;
}
void linkedlist::display()
{
	node *trav=head;
	while(trav !=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
		
	}
	cout<<endl;
	
}
void linkedlist::addatbegin(int data)
{
	node *newnode=new node;
	newnode->data=data;
	newnode->next=head;
	head=newnode;
}
void linkedlist ::addatpos(int data,int pos)
{
	node *newnode=new node;
	newnode->data=data;
	newnode->next=NULL;
	
	node *trav=head;
	while(pos>2)
	{
		trav=trav->next;
		pos--;
	}
	newnode->next=trav->next;
	trav->next=newnode;
}
void linkedlist::removefrompos(int pos)
{
	node *trav=head;
	node *follow=trav;
	while(pos>1)
	{
		follow=trav;
		trav=trav->next;
		pos--;
	}
	follow->next=trav->next;
	delete trav;
}
void linkedlist::reverse()
{
	node *prevnode=head;
	head=head->next;
	node *currnode=head;
	
	prevnode->next=NULL;
	while(head!=NULL)
	{
		head=head->next;
		currnode->next=prevnode;
		prevnode=currnode;
		currnode=head;
	}
	head=prevnode;
	display();
}

int main()
{
	int choice,data,pos;
	linkedlist l;
	cout<<"------Menu-------"<<endl;
    cout<<"1.ADD AT BEGIN"<<endl;
	cout<<"2.ADD AT POSITION"<<endl;
	cout<<"3.REMOVE FROM POSITION"<<endl;
	cout<<"4.DISPLAY"<<endl;
	cout<<"5.REVERSE"<<endl;
	cout<<"6.EXIT"<<endl;
	
	while(true)
	{
		cout<<"Enter Your choice:"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter the data:"<<endl;
			         cin>>data;
			         l.addatbegin(data);
			         break;
			case 2:
				cout<<"Enter the DATA:"<<endl;
				cin>>data;
				cout<<"Enter the Position:"<<endl;
				cin>>pos;
				l.addatpos(data,pos);
				break;
			case 3:
				cout<<"Enter the Position:"<<endl;
				cin>>pos;
				l.removefrompos(pos);
				break;
			case 4:
				l.display();
				break;
			case 5:
			    l.reverse();
			    break;
			case 6:
				exit(0);
				
				  
		}
	}
	return 0;
}
