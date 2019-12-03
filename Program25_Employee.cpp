/*  Write a class Employee for an application which will have data members for employee id, employee name and salary.
Provide the following functionalities in Employee class.

	1. Initialing objects using default and parameterized constructors.
	2. Accepting and displaying the information of employee from console
	
	class Employee
	{
		int emp_id;
		char emp_name[20];
		double salary;
	public:
		Employee();
		Employee(int, char*, double);
		void Accept();
		void Display();
	};

In "main" function declare an array of Employee objects. Write a menu driven program to -
	a. Insert record into an array.
	b. Update information of specific employee on the basis of emp_id accepted from user
	c. Display all records. 
*/


#include<iostream>
#include<cstring>

using namespace std;

class Employee
{
	int emp_id,cnt=0;
	char emp_name[20];
	int salary;
	
	public:
		Employee();
		Employee(int,char*, int);
		void Accept();
		void Display();
		void Update(Employee[]);
};

Employee::Employee()
{
	emp_id=10;
	strcpy(emp_name," gg ");
	salary=200000;
}

Employee::Employee(int id,char *n,int s)
{
	emp_id=id;
	strcpy(emp_name,n);
	salary=s;
}

void Employee::Accept()
{
	cout<<"\nEnter Id, name and salary"<<endl;
	cin>>emp_id>>emp_name>>salary;
	cnt++;
}

void Employee::Display()
{
	cout<<"Employee Id = "<<emp_id<<endl;
	cout<<"Employee Name = "<<emp_name<<endl;
	cout<<"Employee Salary = "<<salary<<endl<<endl;
}

void Employee::Update(Employee e1[])
{
	int id,i;
	int eid=emp_id;
	
	cout<<"\nEnter ID to update information : "<<endl;
	cin>>id;
	
	for(i=0;i<3;i++)
	{
		if(id==e1[i].emp_id)
		{
			cout<<"\nEnter new ID, name and salary : "<<endl;
			cin>>emp_id>>emp_name>>salary;
	
			if(id==eid)
			{
				emp_id=emp_id;
				strcpy(emp_name,emp_name);
				salary=salary;
			}
		}
		else
		{
			cout<<"\nEnter correct id"<<endl;
		}
	}
	
}

int main()
{
	Employee e1[3];
	Employee e2;
	int ch,i,n,n1;
	
	do
	{
		cout<<"\n\n1. Insert \n2. Update \n3. Display \n4. Exit"<<endl;
		cout<<"\nEnter your choice : "<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				//cout<<"\nHow many record you want to insert"<<endl;
				//cin>>n;
				for(i=0;i<3;i++)
				e1[i].Accept();
			break;
			
			case 2:
				e1[0].Update(e1);
			break;
			
			case 3:
				for(i=0;i<3;i++)
				e1[i].Display();
			break;

			case 4:
				exit(0);
			
			default:
				cout<<"Enter correct choice.";
		}
	}while(ch<=4);
	return 0;
}
