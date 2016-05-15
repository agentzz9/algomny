#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[5],i,pos,n,f=0;
	
	printf("For demonstrating Linear Search enter 5 elements:\n");
	for(i=0;i<=4;i++)
	{
		scanf("%d",arr[i]);
	}
	printf("Enter element to search(linearly): ");
	scanf("%d",&n);
	for(i=0;i<=4;i++)
	{
		if(arr[i]==n)
		{
			pos=i;f=1;break;//assuming no repetitions
		}
	}
	if(f==1)
		printf("Element %d found at position: %d ",n,pos+1);
	else
	    printf("Element not found...");
	    
	system("pause");return 0;
}


	