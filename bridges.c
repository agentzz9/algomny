#include<stdio.h>
void merge(int a1[1005],int low,int mid,int high,int a2[1005])
{
    int p1,p2,p3,i,tarr[1005],tarr2[1005];
    
    p1=low;
    p2=mid+1;
    p3=low;
    while((p1<=mid)&&(p2<=high))
    {
        if(a1[p1]==a1[p2])
        {
            if(a2[p1]<=a2[p2])
            {
                tarr[p3]=a1[p1];tarr2[p3]=a2[p1];
                p3++;p1++;
                
            }
            else
            {
                tarr[p3]=a1[p2];tarr2[p3]=a2[p2];
                p3++;p2++;
                
            
            }   
            /*
            tarr[p3]=a1[p1];tarr2[p3]=a2[p1];
            p1++;p3++;
            tarr[p3]=a1[p2];tarr2[p3]=a2[p2];
            p3++;p2++;
            */
        }
        else if(a1[p1]<a1[p2])
            {
                tarr[p3]=a1[p1];tarr2[p3]=a2[p1];
                p3++;p1++;
            }
            else
            {
                tarr[p3]=a1[p2];tarr2[p3]=a2[p2];
                p3++;p2++;
            }
    }
    while(p1<=mid)
    {
        tarr[p3]=a1[p1];tarr2[p3]=a2[p1];
        p3++;p1++;
    }
    while(p2<=high)
    {
        tarr[p3]=a1[p2];tarr2[p3]=a2[p2];
        p3++;p2++;
    }
    for(i=low;i<=high;i++)
    {
        a1[i]=tarr[i];
        a2[i]=tarr2[i];
    }
}
       
void mergesort(int a1[1005],int low,int high,int a2[1005])
{
    int mid;
    mid=(high+low)/2;
    if(low<high)
    {
        mergesort(a1,low,mid,a2);
        mergesort(a1,mid+1,high,a2);
        merge(a1,low,mid,high,a2);
    }
}
int main()
{
    int t,n,i,max,j;
    int a1[1005],a2[1005];
    int dp[1005];
    scanf("%d",&t);
    while(t)
    {
        scanf("%d",&n);
        for(i=0;i<n;++i)
            scanf("%d",&a1[i]);
        for(i=0;i<n;++i)
            scanf("%d",&a2[i]);
            
        for(i=0;i<1005;i++)
            dp[i]=1;
            
        mergesort(a1,0,n-1,a2);
        
        
        for(i=1;i<n;i++)
        {
            for(j=0;j<=i-1;j++)
            {
                if(a2[j]<=a2[i]&&dp[i]<dp[j]+1)
                {    
                    dp[i]=dp[j]+1;
                }
                
            }
            
        }
        
        max=dp[0];
        for(i=1;i<n;i++)
        {
            if(max<dp[i])
                max=dp[i];
        }
        printf("%d\n",max);
        
        
            
            
        /*    
        for(i=0;i<n;i++)
            printf("%d ",dp[i]);
         */   
                    
                
        /*
        for(i=0;i<n;i++)
            printf("%d ",a1[i]);
            
        printf("\n");
        for(i=0;i<n;i++)
            printf("%d ",a2[i]);
         */   
        
        --t;
    }
    system("pause");
    return 0;
}

    
