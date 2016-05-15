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
void ssort(int arr[5])
{
	int i,j,t,small,pos;
	for(i=0;i<=3;i++)
	{
		small=arr[i];
		pos=i;
		for(j=i+1;j<=4;j++)
		{
			if(small>arr[j])
			{
				small=arr[j];
				pos=j;
			}

		}
		t=arr[i];
		arr[i]=arr[pos];
		arr[pos]=t;
	}
}
int main()
{
	int arr[5];
	
	printf("Enter 5 elements(for selection sort):\n");
	input(arr);
	ssort(arr);
	printf("\nSorted:\n");
	output(arr);printf("\n\n");
    system("pause");
	return 0;
}


