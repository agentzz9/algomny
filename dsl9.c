#include<stdio.h>
#include<conio.h>
void stringcat(char *p1,char *p2)
{
	while(*p1!='\0')
	    p1++;
	    
	while(*p2!='\0')
	    *p1++=*p2++;

	*p1='\0';
}
int main()
{
	char s1[100],s2[50];
	printf("\nEnter string 1: ");
	gets(s1);
	printf("\nEnter string 2: ");
	gets(s2);
	stringcat(s1,s2);
	printf("\n Concatenated string: %s\n",s1);
	system("pause");
	return 0;
}