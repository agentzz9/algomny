#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
class employee
{	int  year,rank,i;
	char dob[6];
	long double salary;
	public:
	void getval();
	employee()
	{ year = 0;
	  rank = 0;
	  salary = 0;

	}
      void output()
	{
	 int f=0;
     cout<<"\n On the basis of experience ("<<year<<");"<<endl;
	 if(year>=10)
	 {      rank--;
		cout<<"Congratulations you are promoted by one rank so now your current rank is: "<<rank<<endl;
        salary*=1.25;
		cout<<"And also you will get a salary raise by 25% so from now on your salary will be: "<<salary<<endl;
        f=1;
      }
	  if(year>=5&&year<10)
	{ cout<<"Since your experience is not above 10 years so you will not promoted:  \n"<<rank<<endl;
	salary*=1.1;
	 cout<<"But you will get a salary increment by 10% so salary:"<<salary<<endl;
     f=1;
	 }
	  
      if(f!=1)
              cout<<"(Salary and rank remains same)"<<endl;
      cout<<"And your date of birth is DDMMYYYY:";
	  puts(dob);
	  
  

	  }

};

void  employee::getval()
{
	cout<<" enter the values:\n";
	cout<<"\n How much years of experience do you have? ";
	cin>> year;
	cout<<"\n Current Rank ? : ";
	cin>> rank;
	cout<<"\n Current salary ? ";
	cin>> salary;
	cout<<"\n Date of birth DDMMYYYY: ";
	getchar();
	gets(dob);

}

int   main()
{
	employee e1;
	e1.getval();
	e1.output();
   getch();
   return 0;


}
