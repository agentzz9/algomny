#include<stdio.h>
#include<conio.h>
int stringlen(char *str)
{
	int i,count=0;
	for(i=0;*(str+i)!='\0';i++)
	{
		count++;
	}
	return count;
}

int main()
{
	char s[50];
	int l;

	printf("\nEnter String :");
	gets(s);
	l=stringlen(s);
	
	printf("\n String Length= %d\n\n",l);
	system("pause");
	return 0;
}

	

