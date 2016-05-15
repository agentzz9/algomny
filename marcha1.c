#include<stdio.h>
int main()
{
    int t,n,m,i,wallet[25],N,bit,j,flag,sum;
    scanf("%d",&t);
    
    
    while(t)
    {
        flag=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&wallet[i]);
        }
        N=1;
        for(i=1;i<=n;i++)
        {
            N=N*2;
        }
        
        for(i=1;i<=N;i++)
        {
            j=i;
            bit=n-1;
            sum=0;
            while(bit>=0)
            {
                if(j&1)
                    sum=sum+wallet[bit];
                j=j>>1;
                bit--;
                   
            }
            if(sum==m)
            {
                flag=1;break;
            }
        }
        if(flag==1)
            printf("Yes\n");
            else if(flag==0)
                printf("No\n");
            
        
            
        t--;
    }
    system("pause");
    return 0;
}
