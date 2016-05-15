#include<stdio.h>
#define s(x); scanf("%d",&x);
#define L(i,s,l) for(i=0;i<l;i++)
main()
{
    int a[110][110],d[110][110],x,j,t,n,i,m,p,k=110,z=0;
    
    
    /*for(i=0;i<110;i++)
        for(j=0;j<110;j++)
            a[i][j]=-1;
    */
    L(i,z,k)
        L(j,z,k)
            a[i][j]=-1;
        
    
    
    s(t);
    //scanf("%d",&t);
    while(t>0)
    {
        x=0;
        //printf("\ntest loop\n");
        s(n);
        //scanf("%d",&n);
        //for(i=0;i<n;i++)
        L(i,z,n)
        {
            //printf("\nouter loop\n");
            //while(scanf("%s",&a[i])!='\0');
            x++;
            //for(j=0;j<=x;j++)
            L(j,z,x)
            {
                //printf("\ninner loop\n");
                //printf("\nX=%d\n",x);
                //scanf("%d",&a[i][j]);
                s(a[i][j]);
                if(j==0)
                    if(i==0)
                        d[i][j]=a[i][j];
                    else
                        d[i][j]=d[i-1][j]+a[i][j];
                else if(a[i][j+1]==-1)
                        d[i][j]=d[i-1][j-1]+a[i][j];
                    else
                        if(d[i-1][j]>=d[i-1][j-1])
                            d[i][j]=d[i-1][j]+a[i][j];
                        else
                            d[i][j]=d[i-1][j-1]+a[i][j];
            }    
            if(i==n-1)
            {
                //printf("\ni=n-1 executed\n");
                m=d[n-1][0];
                //for(p=0;p<=x;p++)
                L(p,z,x)
                    if(d[i][p]>m)
                        m=d[i][p];
                
            }
        
        
        }
    printf("%d",m);    
        
    t--;
    }
    system("pause");
    
}
