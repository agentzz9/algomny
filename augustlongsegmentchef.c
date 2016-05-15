#include<stdio.h>
int main()
{
    long long t,n,a[100005],i,li,ri,ans;
    
    long long mi;
    
    
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    scanf("%lld",&t);
    while(t)
    {
        ans=1;
        scanf("%lld %lld %lld",&li,&ri,&mi);
        for(i=li;i<=ri;i++)
        {
            
            ans=(ans*a[i])%mi;
        }
        printf("%lld\n",ans);
        
            
        t--;
    }
    system("pause");
    return 0;
}
