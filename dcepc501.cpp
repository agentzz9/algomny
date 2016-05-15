#include<iostream>
#include<cstdio>
#define max2(a,b) (a>=b?a:b)
#define max3(a,b,c) (a>=max2(b,c))?a:max2(b,c)
using namespace std;

int a[100010]={0};
long long int dp[100010]={0};
int t,n;
long long int ans;

long long int solve(int i)
{
    if(i>=n)
        return 0;
    if(dp[i]!=0)
                return dp[i];
    if(i==n-3)
    {   
        dp[i]=a[i]+a[i+1]+a[i+2];
        return dp[i];
    }
    else if(i==n-2)
    {
        dp[i]=a[i]+a[i+1];
        return dp[i];
    }
    else if(i==n-1)
    {
        dp[i]=a[i];
        return dp[i];
    }           
    dp[i]=max3(a[i]+solve(i+2),a[i]+a[i+1]+solve(i+4),a[i]+a[i+1]+a[i+2]+solve(i+6));
    return dp[i];
}
int main()
{   
   
    scanf("%d",&t);
    while(t--){
    
    	for(int i=0;i<100010;i++)
            a[i]=0;
        for(int i=0;i<100010;i++)
            dp[i]=0;
        
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        	scanf("%d",&a[i]);
      
        ans=solve(0);
      
    	printf("%lld\n",ans);
            
    }

    system("pause");
    return 0;
}
