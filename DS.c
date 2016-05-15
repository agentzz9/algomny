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
int lsearch(int arr[5],int e)
{
	int pos=-1,i;
	for(i=0;i<=4;i++)
	{
		if(arr[i]==e)
		{
			pos=i;//assuming no repetitions
		}
	}
	return pos;
}
int bsearch(int arr[5],int e)
{
	int mid,top=0,bot=4,pos=-1;
	while((pos==-1)&&(top<=bot))
	{
		mid=(top+bot)/2;
		if(e==arr[mid])
			pos=mid;
		else
		if(e<arr[mid])
		    bot=mid-1;
		else
		    top=mid+1;
	}
	return pos;
}
int main()
{
	int arr[5],pos,n;//n is element to search...

	printf("For demonstrating Linear Search enter 5 elements:\n");
	input(arr);
	printf("Enter element to search(linearly): ");
	scanf("%d",&n);
	pos=lsearch(arr,n);
	printf("Element %d found at position(index): %d \n\n",n,pos);

	printf("For demonstrating Binary Search enter 5 elements in ASCENDING order only:\n");
	input(arr);
	printf("Enter element to search: ");
	scanf("%d",&n);
	pos=bsearch(arr,n);
	printf("Element %d found at position(index): %d \n\n",n,pos);

	system("pause");
	return 0;
}
