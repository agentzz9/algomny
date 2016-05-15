#include<stdio.h>
unsigned long long mul,t,global[1000005];
unsigned long long sum=0;
void merge(unsigned long long arr[100005],unsigned long long low,unsigned long long mid,unsigned long long high)
{
    unsigned long long tarr[100005],p1,p2,p3,i,count,l;
    p1=low;
    p2=mid+1;
    p3=low;
    //dep++;
    //printf("\ndep=",dep);
    
    while((p1<=mid)&&(p2<=high))
    {
        if(arr[p1]==arr[p2])
        {
            count=0;
            count=high-p2;
            global[arr[p1]]=global[arr[p1]]+count;
            tarr[p3++]=arr[p2++];
           
        }
        else if(arr[p1]<arr[p2])
            {
                count=0;
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
void mergesort(unsigned long long arr[100005],unsigned long long low,unsigned long long high)
{
    unsigned long long mid;
    
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
    unsigned long long t,n,a[100005],i,j,x,temp;
    scanf("%llu",&t);
    while(t>0)
    {
        sum=0;
        for(i=0;i<1000005;i++)
            global[i]=0;
        
        scanf("%llu",&n);
        for(i=0;i<n;i++)
        {
            scanf("%llu",&a[i]);
        }
        i--;
     
        mergesort(a,0,i);
        for(i=0;i<1000005;i++)
        {
            temp=global[i]*i;
            sum=sum+temp;
        }
      
        printf("%llu\n",sum);
        t--;
    }
   system("pause");
    return 0;
}

        
