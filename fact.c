#include<stdio.h>
#include<conio.h>
int main()
{
	unsigned long int N,a,n;
	int arr[200],t=0,m=1,i,x;
	
	printf("\n Enter no.: ");scanf("%lu",&N);
	n=N-1;

	//putting the no.(N) into the array....>>>
	
	i=0;
	while(N>0)
	{
		arr[i]=N%10;
		N=N/10;
		i++;
	}
	m=i-1;

	//<<<<<<<<<<<<<<correctly stored till here^^^^^^^^^^^^
	//__________________________
	
	//storing its factorial.>>>>
	while(n>0)
	{
		//mult n with the N and update arr to n
		t=0;
		for(i=0;i<=m;i++)
		{
			x=n*arr[i]+t;
			t=x/10;
			arr[i]=x%10;
		}
		m++;//-----
		while(t!=0)
		{
			arr[m]=t%10;
			t=t/10;
			m++;
		}
		arr[m]='\0';//-----
		
		n--;
	}
	//___________________________________________________

	//printing the factorial ie the array in reverse...
	
	for(a=0;a<=m;a++)
	{
		printf("%d",arr[a]);
	}
	//______________________________
	system("pause");
	return 0;
}
	
	