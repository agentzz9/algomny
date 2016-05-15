#include<stdio.h>//sqrt of 9999999 = 3162.2775020544923707326540916478
int main()
{
    int f[10005],p[1230];
    int i,j,l,c,ct=0,tg=1,t;
    f[0]=-1;
    f[1]=-1;
    for(i=0;i<=10005;i++)
        f[i]=-1;
   
    for(i=6;i<=10000;i+=3)
        f[i]=1;
        
    for(i=5;i<=10000;)
    {
        if(f[i])
        {
            for(j=i*i;j<=10000;j+=t)
            {
                f[j]=1;
                t=2*i;
            }
        }
       
        if(tg)
        {
            i+=2;
            tg=-1;
        }
        else
        {
            i+=4;
            tg=1;
        }
            
    }
    
    j=1;
    p[0]=2;
    p[1]=3;
    for(i=5;i<=10000;i+=2)
    {
        if(f[i]!=1)
        {
            p[++j]=i;
        }
    }
    /*
    for(i=0;i<=k;i++) // 1229 primes before 10000 correct
    {
        //ch=getch();
        printf("%d-%d ",primes[i],i+1);
    }
    ch=getch();
    */
    //printf("2\n");
    ct=0;
    for(j=0;j<=1200;j+=100)           
    {
               //ch=getch();
                
                printf("%d\n",p[j]);
    
    }
    
    //1200th indexof primes-9739
    
    for(i=9741;i<100000000;i+=2)
    {
        c=-1;
        
        for(j=0;p[j]<=10000&&j<1229;++j)
        {
            if(i%p[j]==0 && i!=p[j])
            {            
                c=1;
                break;
            }
        } 
        
        if(c!=1)
        {
            ++ct;
            if(ct==100)
            {
               //ch=getch();
                
                printf("%d\n",i);
                ct=0;
            }
            
        }
        
        
    }
    
    system("pause");
    return 0;
}
        
        
    
    
