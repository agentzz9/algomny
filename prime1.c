#include<stdio.h>
#define ROOTN 31625
                                        //10^9 root = ROOTN
int main()
{
    int i,j,k,t,n,m,flag[ROOTN]={0},primes[3500]={0},comp=-1;
    
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
        scanf("%d %d",&m,&n);
        
        for(i=m;i<=n;i++)
        {
            if(i>=ROOTN)
            {
                for(j=0;j<k;j++)
                {
                    if(primes[j]%i==0&&primes[j]!=i)
                    {
                        comp=1;
                        break;
                    }
                }
                if(comp==1)
                {
                    comp=-1;
                    
                }
                else
                {
                    printf("%d\n",i);
                    
                }   
                 
                continue;    
                
            }
            else
            {
                if(flag[i]==0)
                {
                    printf("%d\n",i);    
                }
                continue;
            }
        }
        
        t--;    
    }
    system("pause");
    return 0;    
}
/*
#include<stdio.h>//sqrt of 10^9 = 31622.776601683793319988935444327
int main()
{
    int t,flag[31625]={0},primes[3500];
    int m,n,i,j,k,comp;
                //flag=0 means prime
    
    flag[0]=1;
    flag[1]=1;
    
    for(i=4;i<=31625;i+=2)
        flag[i]=1;
    for(i=6;i<=31625;i+=3)
        flag[i]=1;
        
    for(i=5;i<=31625;)
    {
        if(flag[i]==0)
        {
            for(j=i*i;j<=31625;j=j+2*i)
            {
                flag[j]=1;
            }
        }
        if(i%6==1)
            i=i+4;
        else i=i+2;
    }
    k=0;
    for(i=2;i<=31625;i++)
    {
        if(flag[i]!=1)
        {
            primes[k++]=i;
        }
    }
   // printf("%d",k);
    
    scanf("%d",&t);
    
    
    while(t)
    {
        scanf("%d %d",&m,&n);
        for(i=m;i<=n;i++)
        {
             comp=-1;

            if(i==1)
             continue;

            for(j=0; primes[j]*primes[j]<=n ;j++)
            {
                if(primes[j]==0)
                    printf("\nHERE");
                if(i%primes[j]==0 && i!=primes[j])
                {
                    comp=1;
                    break;
                }
            }

            if(comp!=1)
            {
                printf("%d\n",i);
            }
        }
        t--;
        printf("\n");
        
    }
    system("pause");
    return 0;
}
*/
