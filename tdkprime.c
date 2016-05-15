#include<stdio.h>//sqrt of 9999999 = 3162.2775020544923707326540916478
int main()// k 1 to 5000000 2236.0679774997896964091736687313
{ // 5000000 th prime is 86028121
//rest check testcases in question
    int flag[10005]={0},primes[3500];
    int i,j,k,l,m,comp,count,a,x,t,q;
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
            i=i+4;
        else i=i+2;
    }
    
    k=0;
    for(i=2;i<=10000;i++)
    {
        if(flag[i]!=1)
        {
            primes[k++]=i;
        }
    }
    
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&q);
        count=1;
        if(q==1)
        {
            printf("2\n");
            continue;
        }
        for(j=3;j<100000000;j+=2)
        {
                if(j==1)// 1 nor prime nor composite
                continue;
            
            comp=-1;
        
            for(k=0;primes[k]*primes[k]<=100000000&&k<1229;k++)
            {
                if(j%primes[k]==0 && j!=primes[k])
                {            
                    comp=1;
                    break;
                }
            }
            if(comp!=1)
            {
                count++;
                if(count==q)
                {
                    printf("%d\n",j);
                    break;
                }   
            } 
        }
        
    }//end of while
    system("pause");
    return 0;
}
        
        
    
    
