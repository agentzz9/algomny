#include<iostream>
#include<cstdio>
using namespace std;
int s[1000000];
int main()
{
    
    int T,x,y,z,sum;
    for(int i=0;i<1000000;i++)
    {
        s[i]=1;
    }
    s[0]=0;
    s[1]=0;
   // printf("here");
    s[2]=1;
    for(int i=4;i<=31623;i+=2)
    {
        s[i]=0;
    }
    for(int i=3;i<=31623;i+=2)
    {
            for(int j=i+i;j<=31623;j+=i)
            {
                s[j]=0;
            
            }
              
    }
   
   
    scanf("%d",&T);
    
    
    /*
    for(int i=0;i<100;i++)
    {
        if(s[i]==1)
            printf("%d\n",i);
        
    }*/
    
    while(T>0)
    {
        
        scanf("%d %d",&x,&y);
        sum=x+y;
        for(int i=1;i<=32163;i++)
        {
                if(s[sum+i]==1)
                {
                    printf("%d\n",i);  
                    break;  
                }
        }
        --T;    
    }
    
    system("pause");
    return 0;    
}
