#include<iostream>
#include<cstdio>
#define MAXINT 2147483647
using namespace std;
int MCM(int a[105],int m[105][105],int n)
{
    int temp,min;
    for(int i=n-2;i>=1;i--)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            
            min=MAXINT;
            for(int k=i;k<j;k++)
            {
                temp=m[i][k]+m[k+1][j]+a[i-1]*a[j]*a[k];
                if(temp<=min)
                {
                    min=temp;
                    
                }   
                
            }
            m[i][j]=min;
            
        }    
    }
    
    return m[1][n-1];
        
}
int main()
{
    int n,a[105],ans;
    while(scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        
        int m[105][105]={0};
        
        ans=MCM(a,m,n);
        for(int i=0;i<=n-1;i++)
        {
            for(int j=0;j<=n-1;j++)
            {
                printf("%d  ",m[i][j]);
            }
            printf("\n");
        }       
        
        //printf("%d\n",ans);
        
    }
    system("pause");
    return 0;    
}
