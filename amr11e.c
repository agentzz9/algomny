#include<stdio.h>//1000th lucky =2664
int main()
{
    int t;
    int flag[10005]={0},primes[3500],lucky[1005];
    int i,j,k,l,m,comp,count=0,a,x,n,finish3,finishfull;
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
    k--;
    finishfull=0;
    finish3=0;
    a=3;
    lucky[1]=30;
    lucky[2]=42;
    for(i=43;i<=3000;i++)
    {
        count=0;
        finish3=0;
      //  printf("outer loop %d \n",i);
        for(j=0;primes[j]<i;j++)
        {
            
        //    printf("inner loop%d ",j);
            if(i%primes[j]==0 && i!=primes[j])
            {
                count++;
                if(count==3)
                {
                    finish3=1;
                    break;
                }
            }
        }
        if(finish3==1)
        {
            lucky[a++]=i;
            if(a==1001)
            {
                finishfull=1;
                break;
            }
            
        }
        if(finishfull==1)
            break;
    }
   // printf("%d",lucky[1000]);
    //printf("done");
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",lucky[n]);
        
    }//endofwhile
    system("pause");
    return 0;
}
