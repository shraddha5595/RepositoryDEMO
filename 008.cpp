/* Write a program for implementing Circular Linked List*/

#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
class CircularLL
{
	Node *head, *rear;
	public:
		CircularLL();
	    void Addatbegin(int);
		void Addatend(int);
	    void Addatpos(int, int);
	    void deletefromend();
	    void deletefrombegin();
	    void deletefrompos(int);
		void Display();
};
CircularLL::CircularLL()
{
	head=rear=NULL;
}

void CircularLL::Addatbegin(int data)
{
	Node *newnode = new Node;
	newnode->data=data;
	newnode->next=NULL;
	
	if(rear==NULL)
	{
		head=newnode;
		rear=newnode;
		newnode->next=rear;
	}
	else
	{
		rear->next=newnode;
		newnode->next=head;
		head=newnode;
	}
}

void CircularLL::Addatend(int data)
{
	Node *newnode = new Node;
	newnode->data=data;
	newnode->next=NULL;
	
	if(rear==NULL)
	{
		head=newnode;
		rear=newnode;
		newnode->next=rear;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
		rear->next=head;
	}
}

void CircularLL::Addatpos(int data, int pos)
{
	Node *newnode=new Node;
	newnode->data=data;
	newnode->next=NULL;
	Node *trav=head;
	if(rear==NULL)
	{
		head=newnode;
		rear=newnode;
		newnode->next=rear;
	}
	
	int i=0;
	while(i<pos-2)
	{
		trav=trav->next;
		i++;
	}
	newnode->next=trav->next;
	trav->next=newnode;
}

void CircularLL::deletefromend()
{
	Node *trav=head;
	while(trav->next!=rear)
	{
		trav=trav->next;
	}
	trav->next=rear->next;
	delete rear;
	rear=trav;
	
}

void CircularLL::deletefrombegin()
{
     Node *trav=head;
	 rear->next=trav->next;
	 delete trav;	
}

void CircularLL::deletefrompos(int pos)
{
	Node *trav=head;
	Node *follow=head;
	
	int i=0;
	while(i<pos-1)
	{
		follow=trav;
		trav=trav->next;
		i++;
	}
	follow->next=trav->next;
	delete trav;
	
}
void CircularLL::Display()
{
	Node *trav=rear->next;
	Node *t = head;
	while(trav!=rear)
	{
		cout<<trav->data<<"  ";
		trav=trav->next;
	}
	cout<<trav->data;
	cout<<endl;
}
int main()
{
	CircularLL cq;
	int ch,data,pos;
	cout<<"-----------CIRCULAR LINKED LIST------------"<<endl;
		cout<<"\n1.Add at begin\n2.Add at end\n3.Add at position\n4.Delete from begin\n5.Delete from end\n6.Delete from position\n7.Display\n8.Exit"<<endl;
	while(true)
	{
		cout<<"Enter choice:"<<endl;
			cin>>ch;
		switch(ch)
		{
			
			case 1:
				cout<<"Enter Data:"<<endl;
				cin>>data;
				cq.Addatbegin(data);
				break;
			case 2:
				cout<<"Enter Data:"<<endl;
				cin>>data;
				cq.Addatend(data);
				break;
			case 3:
				cout<<"Enter Data:"<<endl;
				cin>>data;
				cout<<"Enter position"<<endl;
				cin>>pos;
				cq.Addatpos(data,pos);
				break;
			case 4:
				cq.deletefrombegin();
				break;
			case 5:
				cq.deletefromend();
				break;
			case 6:
				cout<<"Enter position:"<<endl;
				cin>>pos;
				cq.deletefrompos(pos);
				break;
			case 7:
				cq.Display();
				break;
			case 8:
				exit(0);
		}
	}
	return 0;
}


























