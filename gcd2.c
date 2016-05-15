/*#include<stdio.h>
#include<string.h>
long long gcd(int a,int b)
{
    if(b==0)
        return a;
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);

}
int main()
{
    
    long long a,g,n,s=0,r,len,i;
    char bs[300];
    
    scanf("%lld",&n);
    while(n)
    {
        scanf("%lld %s",&a,bs);
        len=strlen(bs);
        r=(long long)(bs[0]-'0');
        s=0;
        if(a==0)
        {
             printf("%s\n",bs);
             n--;
             continue;       
        }
        for(i=1;i<len;i++)
        {
            s=10*r+((long long)(bs[i]-'0'));            
            r=s%a;
        }
        g=gcd(a,r);
        printf("%lld\n",g);
        
        n--;    
    }
    
    system("pause");
    return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
int gcd(int a, int b)
{
	if (b==0)
		return a;
	if (a%b==0)
	   return b;
    else
		return gcd(b,a%b);
}
int main()
{
    int a,t,ans,x,len,i;
    char b[255];
    scanf("%d",&t);
    while(t)
    {
        scanf("%d %s",&a,b);
        len=strlen(b);
        x=0;
        if(a==0)
        {
            printf("%s\n",b);
        }
        else
        {
            for(i=0;i<len;i++)
            {
                x=(x*10+b[i]-'0')%a;
            }
            ans=gcd(a,x);
            printf("%d\n",ans);
        }
        t--;
    }
   system("pause");
    return 0;
}
*/
