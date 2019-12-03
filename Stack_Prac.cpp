#include<iostream>

using namespace std;

class stack
{
	int arr[100];
	int size,top;
	
	public:
		
		stack();
		stack(int);
		void push(int);
		int pop();
		bool isfull();
		bool isempty();
};

stack::stack()
{
	size=5;
	top=-1;
}
stack::stack(int s)
{
	size=s;
	top=-1;
}

void stack::push(int data)
{
	if(!isfull())
	{
		arr[++top]=data;
		
	}
	else
	cout<<"Overflow:"<<endl;
}
int stack::pop()
{
	if(!isempty())
	{
		return arr[top--];
	}
	else
	{
	    cout<<"Underflow.."<<endl;
	    return -1;
	}
}

bool stack::isfull()
{
	return top==size-1;
}

bool stack::isempty()
{
	
	return top==-1;
}

int main()
{
	stack s;
	int n,ch,data;
	cout<<"how many elementss do you want to enter:";
	cin>>n;
	
	cout<<"1.Push elements into the stack\n2.Pop elements from the stack\n3.exit"<<endl;
	cout<<"Enter your choice:"<<endl;
	cin>>ch;
	while(1)
	{
		
		switch(ch)
		{
			case 1:
			      cout<<"Enter data:"<<endl;
			      cin>>data;
				  s.push(data);
			      break;
			case 2:
				   s.pop();
				   break;
			case 3:
				exit(0);
				   
			      
		}
	}
//	s.push(12);
//	s.push(52);
//	s.push(84);
//	s.push(23);
//	cout<<s.pop()<<endl;
//	cout<<s.pop()<<endl;
//	cout<<s.pop()<<endl;
//	cout<<s.pop()<<endl;
	
	return 0;
}
