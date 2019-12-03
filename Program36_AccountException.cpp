/* Create a class Account with -
		Instance variable - balance
		Class functions - deposite/withdraw
	User withdrawal limit on one transaction is Rs.15000/-
	Throw and Handle Exceptions -
		1. OverLimit - when user tries to withdraw more than Rs. 15000/- in a transaction
		2. InsufficientBalance - When user withdrawal amount is more than existing balance
*/

#include<iostream>
#include<cstring>


using namespace std;
class Account
{
	int balance;
	const int limit=15000;
	public:
		Account();
		Account (int);
		void deposite(int);
		void withdraw(int);
		void showBalance();
};

Account::Account()
{
	balance=20;
}

Account::Account(int bal )
{
	balance=bal;
}

void Account::deposite(int amt)
{
	balance=balance+amt;
}


void Account::withdraw(int amt)
{
		if(amt<=limit && amt<balance)
		{
			balance=balance-amt;
		}
		else
		{
			throw amt;
		}
}
void Account::showBalance()
{
	cout<<"Available Balance "<<balance<<endl;
}

int main()
{
	int bal;
	Account a1;
	Account a2(50000);
	a2.deposite(20000);
	a2.showBalance();
	a2.withdraw(5000);
	a2.showBalance();
	
	cout<<"Enter amount to withdraw: "<<endl;
	cin>>bal;
	
	try
	{
		a2.withdraw(bal);
	}
	catch(int e)
	{
		cout<<"Enter correct balance"<<endl;
	}
	
	a2.showBalance();
	
    return 0;
}
