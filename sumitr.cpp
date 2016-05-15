#include<stdio.h>
int main()
{
    int a[110][110]={-1},d[110][110],x=0,j,t,n,i;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d",&n);
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=x;j++)
            {
                scanf("%d",&a[i][j]);
                if(j==0)
                {
                    if(i==0)
                    {
                        d[i][j]=a[i][j];
                    }
                    else
                    {
                        d[i][j]=d[i-1][j]+a[i][j];
                    }
                }
                else if(a[j+1]==-1)
                    {
                        d[i][j]=d[i-1][j-1]+a[i][j];
                    }
                    else
                    {
                        if(d[i-1][j]>=d[i-1][j-1])
                        {
                            d[i][j]=d[i-1][j]+a[i][j];
                        }
                        else
                        {
                            d[i][j]=d[i-1][j-1]+a[i][j];
                        }
                    }
                    
            x++;
            }
            
        
        t--;
    }
    return 0;
}
