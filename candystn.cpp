#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,n,m,a[10005],flag;
    long long dp1[10005],dp2[10005],collection,bag;    
    scanf("%d",&t);
    while(t)
    {
        int min=100;
        for(int i=0;i<10005;i++)
        {
                dp1[i]=0;dp2[i]=0;
        }
        flag=1;
        
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        
        dp1[0]=0;
        
        for(int i=1;i<m;i++)
        {
                if(a[i-1]<a[i])
                     dp1[i]=dp1[i-1]+(a[i]-a[i-1]);
                else if(a[i-1]>a[i])
                     dp1[i]=dp1[i-1]-(a[i-1]-a[i]);
                else if(a[i]==a[i-1])
                     dp1[i]=dp1[i-1]-1;
                if(dp1[i]<0&&dp1[i]<min)
                    min=dp1[i];
                           
        }
       
        if(min==100)
            collection=1;
        else
            collection=min*-1+1;
        
        for(int i=0;i<m;i++)
            printf("%lld ",dp1[i]);
        printf("\n");
        
        
        if(collection>n)
        {
            printf("-1\n");
            t--;
            continue;    
        }
        
        bag=n-collection;
        
        dp2[0]=bag;
        
        for(int i=1;i<m;i++)
        {
            if(a[i-1]>a[i])
            {
                 dp2[i]=dp2[i-1]+(a[i-1]-a[i]);
                     
            }
            else if(a[i-1]<a[i])
            {
                 dp2[i]=dp2[i-1]-(a[i]-a[i-1]);
                 
            }
            else if(a[i-1]==a[i])
            {
                dp2[i]=dp2[i-1];    
            }
            if(dp2[i]<0)
            {
                  flag=0;
                  break;      
            }
                                   
        }
       
        for(int i=0;i<m;i++)
            printf("%lld ",dp2[i]);
        printf("\n");
        
        if(flag==0)
        {
            printf("-1\n");
            t--;
            continue;
                   
        }
        else
        {
            printf("%lld\n",collection);
        }
        t--;    
    }
    
    system("pause");    
    return 0;
}
