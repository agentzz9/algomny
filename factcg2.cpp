#include<stdio.h>
#define N 10000005   //10^7 not possible:(
#define ROOTN 3165      //3162.2776601683793319988935444327
unsigned int smallestprime[N]={0};
int main()
{
    unsigned int i,j,k,a,b,c,x,y,z,n,final;
    
    //unsigned int smallestprime[N]={0};
    //bool smallestprime[N]={0};
    
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
    for(i=ROOTN;i<=10000005;i++)
    {
        if(smallestprime[i]==0)
        {
            smallestprime[i]=i;
        }
    }
    
    smallestprime[10000000]=2;
    while(scanf("%u",&n)!=EOF)
    {
        
        printf("1");
        
            for(i=n;i>1;i=i/smallestprime[i])
            {
                
                printf(" x %u",smallestprime[i]);
                
            }
            printf("\n");
        /*
        for(i=2;i<=10000000;i++)
        {
            printf("\n %u -%u ",i,smallestprime[i]);
            
        }
        
        ch=getchar();
         */
    }
  //  ch=getchar();
    //system("pause");

    return 0;
}
