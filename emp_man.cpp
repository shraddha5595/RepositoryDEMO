
#include<iostream>
#include<cstring>
using namespace std;
class employee{
	int empid;
	char name[50];
	int bsal;
	public:
		void accept(int,char*,int);
		void display();
		int salary();
};
void employee::accept(int i,char *n,int s)
{
     empid=i;
     strcpy(name,n);
     bsal=s;
}
void employee :: display()
{
	cout<<"EmpID "<<empid<<"\t"<<"Name - "<<name<<"\t"<<"Salary - "<<bsal<<endl;
}
int employee :: salary()
{
	return bsal;
}
class manager: public employee{
	float petrol;
	float food;
	float other;
	float gross;
	employee e;
	public:
		void calgross();
		void display();
		
};
void manager :: calgross()
{

	int i,s;
	char n[30];
	cout<<"Enter EmpID - "<<endl;
	cin>>i;
	cout<<"Enter emp name - "<<endl;
	cin>>n;
	cout<<"Enter salary"<<endl;
	cin>>s;
	e.accept(i,n,s);
	petrol=e.salary()*6/100;
	food=e.salary()*10/100;
	other=e.salary()*4/100;
	gross=petrol+food+other+e.salary();
}
void manager :: display()
{
	e.display();
	cout<<"Food - "<<food<<endl;
	cout<<"petrol - "<<petrol<<endl;
	cout<<"other - "<<other<<endl;
	cout<<"Gross Salary - "<<gross<<endl;
	
}
class marketing : public employee{
	int gross,km;
	float pf,netsal;
	employee e;
	public:
		void calgross();
		void display();
};
void marketing :: calgross()
{
	int i,s;
	char n[30];
	cout<<"Enter EmpID - "<<endl;
	cin>>i;
	cout<<"Enter emp name - "<<endl;
	cin>>n;
	cout<<"Enter salary"<<endl;
	cin>>s;
	e.accept(i,n,s);
	cout<<"Enter Kilometer "<<endl;
	cin>>km;
	gross=(km*6)+2000+e.salary();
	pf=e.salary()*12.5/100;
	netsal=gross-pf;
}
void marketing :: display()
{
	e.display();
	cout<<"km - "<<km<<endl;
	cout<<"pf - "<<pf<<endl;
	cout<<"gross Salary - "<<gross<<endl;
	cout<<"Net Salary - "<<netsal<<endl;	
}
int main()
{
	int ch;
	while(1)
	{
		cout<<"1. Add manager"<<endl;
		cout<<"2.Add marketing"<<endl;
		cout<<"3.exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				manager m;
				m.calgross();
				m.display();
				break;
			case 2:
			    marketing m1;
			    m1.calgross();
			    m1.display();
				break;
			case 3:
				 exit(0);
		}
	}
	
}

