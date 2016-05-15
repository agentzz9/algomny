#include<stdio.h>
int main()
{
    int i,j,k,x;
    
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++)
        {
            x=0;
            for(k=1;k<=100000;k++)
            {
                x++;
            }
            printf("%d\n",i);
        }
    }
    return 0;
}
