#include<stdio.h>
void merge(int arr[10005],int low,int mid,int high)
{
    int tarr[10005],p1,p2,p3,i;
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
void mergesort(int arr[10005],int low,int high)
{
    int mid;
    
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
    int n,m,D,t,h[505],flag,i,j,pos;
    scanf("%d",&t);
    while(t)
    {
        flag=1;
        pos=0;
        scanf("%d %d %d",&n,&m,&D);
        for(i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
        }
        i--;
        mergesort(h,0,i);
        for(j=1;j<=m;j++)
        {
            
            h[pos]=h[pos]-D;
            if(h[pos]<=D)
            {
                pos++;
            }
            
            
        }
        for(j=0;j<n;j++)
        {
            if(h[j]<=0)
            {
                flag=0;break;
            }
        }
        if(flag==0)
            printf("NO\n");
        else
            printf("YES\n");
    
        t--;
    } 
   // system("pause");
    return 0;
}
