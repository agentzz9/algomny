#include<iostream>
#include<cstdio>
using namespace std;
int main()
{

    int x,i,n,m,a[100005]={0},frontt,index;
    char c;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    frontt=0;

    for(i=1;i<=m;i++)
    {

        scanf(" %c %d",&c,&x);

        if(c=='R')
        {
            x--;
            index=(frontt+x)%n;
            printf("\n%d",a[index]);

        }
        if(c=='C')  //left
        {
            frontt=(frontt+x)%n;
        }
        if(c=='A') //right shift
        {
            while(x)
            {
                if(frontt==0)
                    frontt=n-1;
                else
                    frontt--;

                x--;
            }
        }

    }
    return 0;
}
