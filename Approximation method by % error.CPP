#include<iostream.h>
#include<math.h>
#include<stdio.h>
#include<process.h>
#include<conio.h>

float m,z,coef[10],l,a,b,c;
int k,j,expo[10];
long double z1,a1,b1,c1,m1;

float f(float x)
{       z=0;
	m=x;
	for(j=1;j<=k;j++)
		{
		z=z+ (coef[j] * pow(m,expo[j]));
		}
return(z);
}

long double g(long double x1)
{       z1=0;
	m1=x1;
	for(j=1;j<=k;j++)
		{
	z1=z1+ (coef[j] * pow(m1,expo[j]));
		}
return(z1);
}


void rootf();
void bisection();
void regulaf();

void main()
{
clrscr();
int ch;
while(1)
{
cout<<"\nMENU: \n1.Find the interval of a function. \n2.Bisection method \n3.regula Falsi \n4.Exit";
cout<<"\n Enter your choice:";
cin>>ch;

switch(ch)
{
case 1: rootf();
	break;

case 2: bisection();
	break;

case 3: regulaf();
	break;

case 4: exit(0);
default:cout<<"\n Inavlid choice.";
}
}
getch();
}

void rootf()
{
int j,k,exp[10];
float n,z=0,coef[10];

cout<<"enter the no. of terms:";
cin>>k;
for(j=1;j<=k;j++)
{
cout<<"enter the coeff and power of 1:";
cin>>coef[j]>>exp[j];
}
cout<<"\nThe given polynomial is:";
for(j=1;j<=k;j++)
{
cout<<coef[j]<<"x ^ "<<exp[j]<<" + ";
}
cout<<"\nEnter the value on which you want to find the value of function:";
cin>>n;

for(j=1;j<=k;j++)
{
z=z+ (coef[j] * pow(n,exp[j]));
}
cout<<"ans:"<<z;
getch();
}



void bisection()
{
cout<<"enter the no. of terms:";
cin>>k;
for(j=1;j<=k;j++)
{
cout<<"enter the coeff and power of of respective terms:";
cin>>coef[j]>>expo[j];
}
cout<<"\nThe given polynomial is:";
for(j=1;j<=k;j++)
{
cout<<coef[j]<<"x ^ "<<expo[j]<<" + ";
}

cout<<endl<<" Enter the range "<<endl;
cin>>a;
cin>>b;

cout<<"\n Enter the percentage error:";
cin>>l;

while(fabs(b-a)>l)
{

		c=(a+b)/2;
		if(f(a)*f(c)<0)
			{
			cout<<" a = "<<a<<" b = "<<b<<" c = "<<c<<" f(c) = "<<f(c)<<endl;
			a=a;
			b=c;
			}
		else
			{
			cout<<" a = "<<a<<" b = "<<b<<" c = "<<c<<" f(c) = "<<f(c)<<endl;
			a=c;
			b=b;
			}

}
cout<<endl<<" The root in the interval is :"<<c<<endl;

getch();
}



void regulaf()
{
cout<<"enter the no. of terms:";
cin>>k;
for(j=1;j<=k;j++)
{
cout<<"enter the coeff and power of respective terms:";
cin>>coef[j]>>expo[j];
}
cout<<"\nThe given polynomial is:";
for(j=1;j<=k;j++)
{
cout<<coef[j]<<"x ^ "<<expo[j]<<" + ";
}

cout<<endl<<" Enter the range "<<endl;
cin>>a1;
cin>>b1;

cout<<"\n Enter the percentage error:";
cin>>l;

while(fabs(b1-a1)>l)
{


		c1=(a1*g(b1) - b1*g(a1)) / (g(b1) - g(a1));
		if(g(a1)*g(c1)<0)
			{
			cout<<" a = "<<a1<<" b = "<<b1<<" c = "<<c1<<" f(c) = "<<g(c1)<<endl;
			a1=a1;
			b1=c1;
			}
		else
			{
			cout<<" a = "<<a1<<" b = "<<b1<<" c = "<<c1<<" f(c) = "<<g(c1)<<endl;
			a1=c1;
			b1=b1;
			}

}
cout<<" The root in the interval is "<<c1<<endl;
}