#include<stdio.h>
#define N 10000000   //10^7 not possible:(
#define ROOTN 3165      //3162.2776601683793319988935444327
int main()
{
    unsigned int i,j,k,a,b,c,x,y,z,n;
    bool smallestprime[N]={0};
    char ch;
    smallestprime[0]=0;
    smallestprime[1]=0;
    for(i=2;i<ROOTN;i++)
    {
      
        if(smallestprime[i]==0)
        {  
            smallestprime[i]=i; 
            for(j=i*i;j<N;j+=i)
            {
                if(smallestprime[j]==0)
                {    
                    smallestprime[j]=i;
                }
            }
        }
    }
    while(scanf("%u",&n)!=EOF)
    {
        
        printf("1");
        
            for(i=n;i>1;i=i/smallestprime[i])
            {
                printf("x%u",smallestprime[i]);
            }
            printf("\n");
        
            
            
        /*
        for(i=2;i<=12;i++)
        {
            printf("\n %u -%u ",i,smallestprime[i]);
        }*/
         
    }
    system("pause");

    return 0;
}
