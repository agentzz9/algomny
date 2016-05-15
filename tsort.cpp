#include<iostream.h>
using namespace std;
void merge(long arr[10005],long low,long mid,long high)
{
    long tarr[10005],p1,p2,p3,i;
    p1=low;
    p2=mid+1;
    p3=low;
    while((p1<=mid)&&(p2<=high))
    {
        if(arr[p1]==arr[p2])
        {
            tarr[p3++]=arr[p1++];
            tarr[p3++]=arr[p2++];
        }
        else if(arr[p1]>arr[p2])
            {
                tarr[p3++]=arr[p1++];
            }
            else
            {
                tarr[p3++]=arr[p2++];
            }
    }
    while(p1<=mid)
    {
        tarr[p3++]=arr[p1++];
    }
    while(p2<=high)
    {
        tarr[p3++]=arr[p2++];
    }
    for(i=low;i<=high;i++)
    {
        arr[i]=tarr[i];
    }
}
void mergesort(long arr[10005],long low,long high)
{
    long mid;
    
    mid=(low+high)/2;   
    if(low<high)
    {
        
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main()
{
    long t,arr[10005],i,j;
    scanf("%ld",&t);
    //cin>>t;
    i=0;
    while(t>0)
    {
        scanf("%ld",&arr[i]);
        i++;
        t--;
    }
    i--;  
    mergesort(arr,0,i);
    for(j=0;j<=i;j++)
    {
        printf("\n%ld",arr[j]);
    }
    
    system("pause");
    return 0;
}

