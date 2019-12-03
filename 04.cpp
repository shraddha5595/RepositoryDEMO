#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
class concat
{
	node *head;
	
	public:
		concat();
		void addatbegin(int);
		void display();
		static void concatination(concat, concat);
		
};

concat::concat()
{
	head=NULL;
}
void concat::addatbegin(int data)
{
	node *newnode=new node;
	
	newnode->data=data;
	newnode->next=NULL;
	
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
	//	head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}
}

void concat::display()
{
	
	node *trav=head;
	while(trav !=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
		
	}
	cout<<endl;
}

void concat::concatination(concat a, concat b)
{
	node *travb = b.head;
	node *trava = a.head;

	while(trava!=NULL || travb!=NULL)
	{
	
		cout<<trava->data<<" ";
		if(trava->next == NULL)
		{
			trava->next = travb;
		}
		trava=trava->next;
	}
	
	while(trava->next != NULL)
	{
		cout<<trava->data;
		trava = trava->next;
	}
	//con.display();
}

int main()
{
	concat c1,c2;
	c1.addatbegin(12);
	c1.addatbegin(33);
	c1.addatbegin(45);
	
	c1.display();
	
	c2.addatbegin(90);
	c2.addatbegin(80);
	c2.addatbegin(70);
	
	c2.display();
	
	
	concat::concatination(c1, c2);
	
	
	c1.display();
}
