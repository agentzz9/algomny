#include<stdio.h>
long long count=0,t;
void merge(long long arr[200005],long long low,long long mid,long long high)
{
    long long tarr[200005],p1,p2,p3,i;
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
        else if(arr[p1]<arr[p2])
            {
                tarr[p3++]=arr[p1++];
            }
            else
            {
                t=mid-p1+1;
                count=count+t;                
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
void mergesort(long long arr[200005],long long low,long long high)
{
    long long mid;
    
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
    long long t,n,i,j;
    long long a[200005];
    count=0;
    scanf("%lld",&t);
    printf("\n");
    while(t>0)
    {
        count=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        i--;
        mergesort(a,0,i);
        printf("%lld\n",count);
        
        t--;
    }
    system("pause");
    return 0;
}
