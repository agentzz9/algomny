#include<stdio.h>
long long sum=0,mul,t,global[1000005]={0};
void merge(long long arr[1000005],long long low,long long mid,long long high)
{
    long long tarr[1000005],p1,p2,p3,i,count=0,l;
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
                count=high-p2+1;
                global[arr[p1]]=global[arr[p1]]+count;
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
void mergesort(long long arr[1000005],long long low,long long high)
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
    long long t,n,a[1000005],i,j,x;
    scanf("%lld",&t);
    while(t>0)
    {
        sum=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        i--;
        
       /* for(i=0;i<=15;i++)
            printf("%lld",global[i]);
            system("pause");
           */ 
        mergesort(a,0,i);
        for(i=0;i<=1000005;i++)
        {
            sum=sum+global[i]*i;
        }
        /* for(i=0;i<=15;i++)
            printf("%lld",global[i]);
            system("pause");
        */
        printf("%lld",sum);
        t--;
    }
    system("pause");
    return 0;
}

        
