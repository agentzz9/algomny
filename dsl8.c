#include<stdio.h>
#include<conio.h>

int main()
{
	char s[50];
	int n=0,i=0,t;
	printf("Enter string: ");
	gets(s);

	while(s[i++]!='\0')//for strlen
		n++;

	for(i=0;i<(n/2);i++)
	{
		t=s[i];
		s[i]=s[n-(i+1)];
		s[n-(i+1)]=t;
	}
	
	printf("\nReversed to : %s\n",s);
	system("pause");
	return 0;
}

		
