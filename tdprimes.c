#include<stdio.h>
#define ROOTN 10000                        //10^8 root = ROOTN
int flag[ROOTN]={0};
int main()
{
    int i,j,k,t,n,m,primes[3500]={0},comp=-1,count=1,index=1;
    
    flag[0]=1;
    flag[1]=1;

    for(i=4;i<ROOTN;i+=2)
        flag[i]=1;
        
    printf("2\n");count++;    
    for(i=3;i<ROOTN;i+=2)
    {
        if(flag[i]==0)
        {
            if((count-1)%100==0)
            {
                printf("%d\n",i);
               // getchar();
            }
            count++;
        
            
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
        printf("%d %d\n",i,primes[i]);
       // getchar();
    }*/
    
    for(i=ROOTN;i<=100000000;i+=2)
    {
            comp=-1;
            for(j=0;primes[j]*primes[j]<=i;j++)
            {
                if(i%primes[j]==0&&i!=primes[j])
                {
                    comp=1;
                    break;
                }    
            }
            if(comp!=1)
            {
                if((count-1)%100==0)
                {
                    printf("%d\n",i);
                  //  getchar();
                    
                }
                count++;          
            }
                   
    }
    system("pause");
    return 0;    
}


/*#include<stdio.h>//sqrt of 9999999 = 3162.2775020544923707326540916478
int main()
{
    int flag[10005]={0},primes[3500];
    int i,j,k,l,m,comp,count=99,a,x;
    char ch;
    flag[0]=1;
    flag[1]=1;
   
    
    for(i=4;i<=10000;i+=2)
        flag[i]=1;
    for(i=6;i<=10000;i+=3)
        flag[i]=1;
        
    for(i=5;i<=10000;)
    {
        if(flag[i]==0)
        {
            for(j=i*i;j<=10000;j=j+2*i)
            {
                flag[j]=1;
            }
        }
        if(i%6==1)
        {
            //printf("4 1st");
            //getch();
            i=i+4;
        
        }
        else 
        {
            //printf("2 1st");
            //getch();
            i=i+2;
        
        }
        
    }
    
    k=0;
    for(i=2;i<=10000;i++)
    {
        if(flag[i]!=1)
        {
            primes[k++]=i;
        }
    }
    /*
    for(i=0;i<k;i++) // 1229 primes before 10000 correct
    {
        printf("%d-%d ",primes[i],i+1);
    }
    ch=getch();
    
    printf("2\n");
    count=0;
    for(j=3;j<100000000;j+=2)
    {
        
        comp=-1;
        
      
        for(k=0;primes[k]*primes[k]<=100000000&&k<1229;k++)
        {
      //      if(k==1229)
       //         printf("\n prime bound broken\n");
        //    if(primes[k]==0)
        //            printf("\nHERE zero\n");
            if(j%primes[k]==0 && j!=primes[k])
            {            
                comp=1;
                break;
            }
        } 
        
        
        if(comp!=1)
        {
            count++;
            if(count==100)
            {
               ch=getch();
                
                printf("%d\n",j);
                count=0;
            }
            
        }
        
        
    }
    
    system("pause");
    return 0;
}
        
        
    
    
*/
