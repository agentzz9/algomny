#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;
class student
{
	int roll,year,sem;
	public:
	char dpt[20];
	student()
	{
		year=0;
		roll=0;
		sem=0;
		dpt[20]=0;
	}
	void reg()
	{
		cout<<"Enter the roll no.      :";
		cin>>roll;
		cout<<"\nEnter the semester      :";
		cin>>sem;
		cout<<"\nEnter the year          :";
		cin>>year;
		cout<<"\nEnter the department    :";
		getchar();
		gets(dpt);
	}
	void upgrade();

};
void student::upgrade()
{
	cout<<"\nThe roll no. is            :"<<roll;
	cout<<"\nThe semester is            :"<<sem;
	cout<<"\nThe year is                :"<<year;
	cout<<"\nThe upgraded department is :";
	puts(dpt);
}
int main()
{
	int per;
	student st;
	st.reg();
	cout<<"\nEnter the percentage of last semester : ";
	cin>>per;
	if(per>75)
	strcpy(st.dpt,"COE");
		else if(per>70)
		strcpy(st.dpt,"ECE");
			else if(per>65)
			strcpy(st.dpt,"ME");
				else
				cout<<"\nSorry no department upgradation possible ";
	st.upgrade();
	getch();
}


