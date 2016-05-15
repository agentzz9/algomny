#include<stdio.h>
#include<conio.h>
int main()
{
	unsigned long int N,a;
	int arr[200],t=0,m=1,i;
	
	printf("\n Enter no. :\n");scanf("%lu",&N);
	//putting the no. into the array....>>>
	
	i=0;
	while(N>0)
	{
		arr[i]=N%10;
		N=N/10;
		i++;
	}
	m=i;
	
	for(i=0;i<m;i++)
	{
		printf("%d",arr[i]);
	}

	system("pause");
	return 0;
}

	
	
	
	

	
	
	
	