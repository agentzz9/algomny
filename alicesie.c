#include<stdio.h>
int main()
{
    long long t,n,i,j;
    scanf("%lld",&t);
    while(t)
    {
        scanf("%lld",&n);
        i=n/2;
        j=n-i;
        printf("%lld\n",j);
        t--;
    }
    fflush(stdin);
    getchar();
    return 0;
}
