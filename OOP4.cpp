#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
int count=-1;
class employee
{
	char dob[11];
	long double salary;
	unsigned long int rank,no;//employee no is unique to every1
	public:
		employee()
		{
			int i;
			for(i=0;i<11;i++)
			{
				dob[i]='0';
			}
			no=0;salary=0;rank=0;
		}
		
		char* retdob() { return dob; }
		long double retno() { return no; }
		long double retsal() { return salary; }
		unsigned long int retrank() { return rank; }
		void input()
		{
			printf("\nFill in the details:\n");
			printf("Date Of Birth(dd-mm-yyyy): ");
			scanf("%s",dob);
			printf("\nNumber ");scanf("%lu",&no);
			printf("\nSalary ");scanf("%Lf",&salary);
			printf("\nRank ");scanf("%lu",&rank);
		}
		void output()
		{
            printf("Date Of Birth(dd-mm-yyyy): %s",dob);
			printf("\nNumber %lu",no);
			printf("\nSalary %Lf",salary);
			printf("\nRank %lu",rank);
		}
		void incsalary()
		{
			salary=(.1*salary)+salary;
		}
		void incrank()
		{
			rank--;
			salary=(.25*salary)+salary;
		}
};
int searchdata(employee obj[255],unsigned long int tno)
{
	int i;
	for(i=0;i<256;i++)
	{
		if(obj[i].retno()==tno)
		{
			return 1;
		}
	}
	return -1;
}
int main()
{
	//clrscr();
	employee obj[255];
	char ch;
	int i,f,pos=-1;
	unsigned long int tno;
	do
	{
		printf("\nWelcome\n");
		printf("\nEnter Employee No.: ");scanf("lu",&tno);
		f=searchdata(obj,tno);
		while(f)
		{	count++;
			printf("\n Number doesnt exist");
			printf("\nCreating new: ");
			obj[count].input();
			system("pause");
			break;
		}
		for(i=0;i<256;i++)
		{
			if(obj[i].retno()==tno)
				{pos=i;break;}
		}
		printf("\n Do you want to increase salary by 10%?");
		scanf("%c",&ch);
		if(ch=='y')
		    obj[pos].incsalary();
		printf("\n Do you want to increase rank by 1?");
		printf("\n (This will increment salary by 25%)");
		scanf("%c",&ch);
		if(ch=='y')
		    obj[pos].incrank();
		printf("Updated:\n");obj[pos].output();
		system("pause");
		printf("\n**Do you want to continue or exit program??**\n");
		scanf("%c",&ch);
	}while(ch=='y');
	return 0;
}

		
		
		
		


