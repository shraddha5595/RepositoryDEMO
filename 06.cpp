/*6. Implement doubly linked list and implement following functions
Insert by pos
Insert by value
Del by pos
Delete by value
Display
Display in reverse
Sort by value
Sort by Links*/

#include<iostream>

using namespace std;

struct node
{
    int data;
	node *next,*prev;
};
class DoublyLL
{
	node *head,*tail;
	
	public:
		DoublyLL();
		void addatbeg(int);
		void addatpos(int,int);
        void display();
    	void removefrompos(int);
    	void reverse();
		
};

DoublyLL::DoublyLL()
{
	head=tail=NULL;
}

void DoublyLL::addatbeg(int data)
{
	node *newnode=new node;
	newnode->prev=NULL;
	newnode->data=data;
	newnode->next=NULL;
	
	if(head==NULL   && tail==NULL)
	{
		head=tail=newnode;
	}
	else
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}
}



void DoublyLL::addatpos(int data,int pos)
{
	node *newnode=new node;
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	
	
	if(head==NULL && tail ==NULL)
	{
		head=tail=newnode;
	}
	else
	{
	
     	node *trav=head;
		while(pos>2)
		{
			trav=trav->next;
			pos--;
		}
		trav->next->prev=newnode;
		newnode->prev=trav;
		newnode->next=trav->next;
		 trav->next=newnode;
		
	}
}

void DoublyLL::display()
{
	node *trav=head;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
		
	}
	cout<<endl;
	
}

void DoublyLL::removefrompos(int pos)
{
	node *trav=head;
	node *follow =head;
	while(pos>1)
	{
		follow=trav;
		 trav=trav->next;
		 pos--;
	}
	follow->next=trav->next;
	trav->next->prev=follow;
	delete trav;
	
}
void DoublyLL::reverse()
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
	int ch,data,pos,n;
	DoublyLL d;
	cout<<"\n 1.insert\n 2.addatbegin\n 3.delete\n 4.display\n 5.reverse\n 6.Exit"<<endl;
	
		
	while(true)
	{
		cout<<"enter the choice:"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"enter the number"<<endl;
			cin>>data;
			d.addatbeg(data);
			break;
		case 2:
			cout<<"enter the number"<<endl;
			cin>>data;
			cout<<"Enter position:"<<endl;
			cin>>pos;
			d.addatpos(data,pos);
			break;
		case 3:
			cout<<"enter the position"<<endl;
			cin>>pos;
			d.removefrompos(pos);
			
			break;
		case 4:
			d.display();
			break;
		case 5:
			d.reverse();
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}


