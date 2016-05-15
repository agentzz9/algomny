#include<iostream> //check for a recursive version too... this is bottom up.
#include<cstdio>
#define MAXINT 2147483647
using namespace std;
int sum(int x,int y,int a[105])
{
    int sum=0;
    for(int i=x;i<=y;i++)
    {
            sum=(sum+a[i])%100;
    }
        
    return sum;
}
int solve(int a[105],int m[105][105],int n)
{
    int temp,min;
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            
            min=MAXINT;
            for(int k=i;k<j;k++)
            {
                temp=m[i][k]+m[k+1][j]+sum(i,k,a)*sum(k+1,j,a);
                if(temp<=min)
                {
                    min=temp;
                    
                }   
                
            }
            m[i][j]=min;
            
        }    
    }
    
    return m[0][n-1];
        
}
int main()
{
    int n,a[105],ans;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        
        int m[105][105]={0};
        
        ans=solve(a,m,n);
       /* for(int i=0;i<=n-1;i++)
        {
            for(int j=0;j<=n-1;j++)
            {
                printf("%d  ",m[i][j]);
            }
            printf("\n");
        }       
        */
        
        printf("%d\n",ans);
        
    }
    system("pause");
    return 0;    
}
