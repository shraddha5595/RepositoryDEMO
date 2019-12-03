/*
36.	Create a class Account with -
		Instance variable - balance
		Class functions - deposite/withdraw
	User withdrawal limit on one transaction is Rs.15000/-
	Throw and Handle Exceptions -
		1. OverLimit - when user tries to withdraw more than Rs. 15000/- in a transaction
		2. InsufficientBalance - When user withdrawal amount is more than existing balance
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Account
{
	int acno;
	char *name;
	int balance;
	
	public:
			Account();
			Account(int,char*,int);
			void deposit(int);
			void widthdraw(int);
			void showblance();
};

Account::Account()
{
	acno=001;
	name=new char[4];
	strcpy(name,"ABC");
	balance=1000;
	
}
Account::Account(int ac,char* n,int b)
{
	
}
void Account::deposit(int b)
{
	balance=balance + b;
	//cout<<" "<<endl;
}
void Account::widthdraw(int b)
{
	char c;
	if(balance <= b)
	{
		throw b;
	}
	else if(b>15000)
	{
		//coutt<<""withdrawal limit on one transaction is Rs.15000/-
		throw c;
	}
	else
	{
		balance=balance - b;
	}
	
	
}
void Account::showblance()
{
	cout<<"The Avalibale Balace is --> "<<balance<<endl;
	
}


int main()
{
	Account a1;
	
	a1.showblance();
	int z=0,c,x;
	while(1)
	{
	
		cout<<"chosse The Option \n1.Deposit Money\n2.Widthdrwa Money\n3.Show Balancae\n0.--Exit--"<<endl;
		cin>>z;
		if(z==1)
		{
			cout<<"Enter Mony For Deposit"<<endl;
			cin>>c;
			
		
				a1.deposit(c);
				a1.showblance();
			
		}
		else if(z==2)
		{
			cout<<"Enter Mony For Widthdraw"<<endl;
			cin>>x;
			
			try
			{
				a1.widthdraw(x);
				a1.showblance();
			}
			catch(int y)
			{
				cout<<"The Avilable balce is Less Than Entered Amount "<<endl;

			}
			catch(char z)
			{
				cout<<"withdrawal limit on one transaction is Rs.15000/- "<<endl;

			}
		}
			
		
		else if(z==3)
		{
			a1.showblance();
		}
		else if(z==0)
		{
			return 0;
		}
		else{
			cout<<"Enter The correct Option"<<endl;
		}
}
	return 0;
}
