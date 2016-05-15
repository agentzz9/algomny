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
void isort(int arr[5])
{
	int i,j,t;

	for(i=1;i<=4;i++)
	{
		t=arr[i];
		j=i-1;
		while(arr[j]>t&&j>=0)
		{
			arr[j+1]=arr[j];
			arr[j]=t;
			j--;
		}
	}

}
int main()
{
	int arr[5];
	
	printf("Enter 5 elements(for insertion sort):\n");
	input(arr);
	isort(arr);
	printf("\nSorted:\n");
	output(arr);printf("\n\n");
    system("pause");
	return 0;
}


