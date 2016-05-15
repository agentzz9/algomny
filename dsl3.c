#include<stdio.h>
#include<conio.h>
void input(int arr[5])
{
	int i;
	for(i=0;i<=4;i++)
	{
		scanf("%d",&arr[i]);
	}
}
void output(int arr[5])
{
    int i;
	for(i=0;i<=4;i++)
	{
		printf("%d\t",arr[i]);
	}
}
void bsort(int arr[5])
{
	int i,j,t,f;
	for(i=0;i<=3&&f;i++)
	{
		f=0;
		for(j=0;j<=3-i;j++)
		{
			if(arr[j]>=arr[j+1])
			{
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;f=1;
			}
		}
	}
}
int main()
{
	int arr[5];
	
	printf("Enter 5 elements(for bubble sort):\n");
	input(arr);
	bsort(arr);
	printf("\nSorted:\n");
	output(arr);printf("\n\n");
	
	system("pause");
	return 0;
}


