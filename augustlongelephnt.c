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
    int t,n,m,i,c,j,p;
   
   
    scanf("%d",&t);
    while(t)
    {
        int path[100005]={0},room[105][105]={0},ans=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&path[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&c);
            for(j=0;j<=c-1;j++)
            {
                scanf("%d",&room[i][j]);
            }
        }
        
        
        //processing and output...
        for(i=0;i<n;i++)
        {    
            mergesort(room[i],0,100);
        }
        for(i=0;i<m;i++)
        {
            p=path[i];
            for(j=0;j<100;j++)
            {
                if(room[p][j]!=0)
                {
                    ans=ans+room[p][j];
                    room[p][j]=0;
                    break;
                }
            }
        }
        printf("%d\n",ans);
        
        t--;
    }
    
    system("pause");
    return 0;
}
