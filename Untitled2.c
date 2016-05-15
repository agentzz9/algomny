#include<stdio.h>
int main()
{
    int a2[1005],dp[1005],i,n=10,j;
    
    for(i=0;i<1005;i++)
        dp[i]=1;
    for(i=0;i<n;++i)
            scanf("%d",&a2[i]);
            
     for(i=1;i<n;i++)
        {
            for(j=0;j<=i-1;j++)
            {
                if(a2[j]<a2[i]&&dp[i]<dp[j]+1)
                {    
                    dp[i]=dp[j]+1;
                }
                
            }
            
        }
        
        for(i=0;i<n;++i)
            printf("%d ",dp[i]);
            
            system("pause");
            return 0;
}
            
        
