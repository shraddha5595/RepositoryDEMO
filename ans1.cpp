#include<iostream>
#include<string.h>
using namespace std;
class employee
{
	int id;
	char *name;
	protected:
	int salary;
	public:
		employee()
		{
			id=1;
			name=new char[100];
			strcpy(name,"sam");
			salary=10000;
		}
		employee(int id1,char* name1,int salary1)
		{
			id=id1;
			name=new char[100];
			strcpy(name,name1);
			salary=salary1;
		}
		
		void display()
		{
			cout<<"id="<<id<<endl;
			cout<<"name="<<name<<endl;
			cout<<"salary="<<salary;
		}
		
};
class manager:public employee
{ 
int petrol;
int food;
int other;

public:
 employee e1;
    manager()
	{
		petrol=6;
		food=10;
		other=4;
	 } 
 manager (int a,int b,int c,int id1,char* name1,int salary1):employee(id1,name1,salary1)
	{
		
		petrol=a;
		food=b;
		other=c; 
	}
	
	void display()
	{   
	    e1.display();   
		int allowance=(100*salary)/(petrol+food+other);
		int gross=salary+allowance;
		int pf=(12.5/100)*(salary);
		int netsalary=gross-pf;
		cout<<"pf="<<pf<<endl;
		cout<<"gross="<<gross<<endl;
		cout<<"netsalary="<<netsalary<<endl;
	}
};

class marketexecution:public employee
{
	int dist;
	int tour;
	int tele;
	public:
		marketexecution()
{
	dist=1;
	tour=6;
	tele=2000;
		}	
			marketexecution(int x,int y,int z,int id1,char* name1,int salary1):employee(id1,name1,salary1)
          {
	dist=1;
	tour=6;
	tele=2000;
		}			
		
		void display()
		{
			cout<<"dist="<<dist<<"  km"<<endl;
			cout<<"tour="<<tour<<"  km/me"<<endl;
			cout<<"telephone="<<tele<<endl;
		}
};

int main()
{
	marketexecution m;
	manager m1;
	m1.display();
	return(0);
}


