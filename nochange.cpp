#include<iostream>// 189 3 12 15 180
#include<cstdio>
using namespace std;

int main()
{
    int x,i,j,k,a,b,c;
    int v[10],cumulate[10],dp[100005];
    scanf("%d %d",&x,&k);
    for(i=1;i<=k;i++)
    {
            scanf("%d",&v[i]);
    }
    
    cumulate[1]=v[1];
    for(i=2;i<=k;i++)
        cumulate[i]=cumulate[i-1]+v[i];
    
    for(i=0;i<=x;i+=v[1])
        dp[i]=1;

    for(i=2;i<=k;i++)
    {
        for(j=0;j<=x;j++)
        {
            if(dp[j])
            {
                if(j+cumulate[i]<=x)
                    dp[j+cumulate[i]]=1;
            }       
        }  
    }
      
    if(dp[x])
        printf("\nYES");
    else
        printf("\nNO");
    
    system("pause");
    return 0;
}
