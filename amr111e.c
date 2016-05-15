#include<stdio.h>
#define ROOTN 31625                        //10^9 root = ROOTN
int lucky[1000005];
int main()
{
    int i,j,k,t,n,m,flag[ROOTN]={0},primes[3500]={0},comp=-1,count=0,index=1;
    
    flag[0]=1;
    flag[1]=1;

    for(i=4;i<ROOTN;i+=2)
        flag[i]=1;
        
    for(i=3;i<ROOTN;i=i+2)
    {
        if(flag[i]==0)
        {
            for(j=i*i;j<ROOTN;j+=i)
            {
                flag[j]=1;    
            }
        }    
    }
    k=0;
    for(i=0;i<ROOTN;i++)
    {
        if(flag[i]==0)
        {
            primes[k++]=i;
        }
            
    }
 //printf("hey");
  
    for(i=30;i<=1000000;i++)
    {
        count=0;
        for(j=0;j<k;j++)
        {
            if(i%primes[j]==0&&i!=primes[j])
            {
                count++;    
                if(count>=3)
                {
                    
                    lucky[index++]=i;
                    count=0;
                    break;    
                }
                
            }
        
            
        }   
        if(index>=1002) break;
        
    }
//   printf("hey");
    /* 
    for(i=0;i<k;i++)
    {
        printf("%d\n",primes[i]);
        getchar();
    }
    */
    
    scanf("%d",&t);
    while(t)
    {
        scanf("%d",&n);
        printf("%d\n",lucky[n]);
        
        t--;    
    }
    system("pause");
    return 0;    
}
