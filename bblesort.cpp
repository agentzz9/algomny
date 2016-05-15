#include<stdio.h>

int main()
{
    int n,arr[100],i,j,t;
    printf("\nEnter no. of elements\n");
    scanf("%d",&n);
    
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=1;j<n-i;j++)
        {
            if(arr[j-1]>arr[j])
            {
                t=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=t;
            }
        }
    }
    printf("\nSORTED\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    fflush(stdin);
    getchar();
    return 0;
}
