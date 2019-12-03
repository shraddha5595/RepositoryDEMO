#include<iostream>
#include<cmath>
using namespace std;

class complex
{
	int real;
	int img;
	public: 
	      complex();
	      complex(int, int);
	      void accept();
	      void display();
	      complex operator + (complex&x);
	      complex operator - (complex&x);
	      complex operator ++();
	      complex operator ++(int);
};

	complex::complex()
	{
	real = 0;
	img = 0;
	}

	complex::complex(int r, int i)
	{
	real = r;
	img = i;
	}

	void complex::accept()
	{
	cin>>real;
	cin>>img;
	}

	void complex::display()
	{
		char ch;
		ch=(img>0)?'+':'-';
		cout<<real<<ch<<abs(img)<<"i"<<endl;
	
		
	}
	
	complex complex::operator +(complex&c)
	{ 
		complex temp;
		temp.real=this->real+c.real;
		temp.img= this->img+c.img;
		return temp;
	
	}
	complex complex::operator -(complex&c)
	{	
		complex temp;
		temp.real=this->real-c.real;
		temp.img=this->img-c.img;
		return temp;
	}
	
	complex complex::operator ++()
	{
		complex temp;
		temp.real = ++real;
		temp.img = ++img;
		return temp;
	}
	
	complex complex::operator ++(int)
	{
		complex temp;
		temp.real = real++;
		temp.img = img++;
		return temp;
	}
	
	int main()
	{
	complex c1(10,20);
	complex c2(11,22);
	complex c3,c6;
	c3=c1+c2;
	c6=c1-c2;
	complex c4,c5;
	c4=++c1;
	c5=c1++;
	c3.display();
	c6.display();
	c4.display();
	c5.display();
	return 0;
}

