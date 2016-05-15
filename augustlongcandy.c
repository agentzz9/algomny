#include<stdio.h>
int main()
{
    long long t,n,k,student,her;
    
    
    scanf("%lld",&t);
    while(t)
    {
        scanf("%lld %lld",&n,&k);
        if(k==0)
        {
            student=0;
            her=n;
        }
        else if(k==0&&n==0)
        {
            student=0;her=0;
        }
        else if( n<k )
        {
            student=0;her=n;
        }
        else if(n%k==0)
            {
                student=n/k;
                her=0;
            }
            else
            {
                student= n/k;
                her=n%k;
            }
            
        printf("%lld %lld\n",student,her);
        t--;
    }
    system("pause");
    return 0;
}
