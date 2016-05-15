#include<stdio.h>
#include<conio.h>
int stringcmp(char *p1,char *p2)
{
	int diff;
	while((*(p1)!='\0') && (*(p1)==*(p2)))
	{
		p1++;
		p2++;
	}
	diff=((((int)(*(p1)))-((int)(*(p2)))));
	return diff;
}
int main()
{
	char s1[50],s2[50];
	int x;
	
	printf("\n Enter string 1: ");
	gets(s1);
    printf("\n Enter string 2: ");
	gets(s2);
	if(stringcmp(s1,s2)==0)
	    printf("\nEqual\n");
	else
	    printf("\nUnequal\n");
	system("pause");
	return 0;
}