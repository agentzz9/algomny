#include<stdio.h> 
#define ROOT109 31625 
int cubes[1000005]={0},count[1000005]={0};
int main()
{
    int t,n;
    int i,j,prev=0,cas=0;
    
    for(i=2;i*i*i<=1000000;i++)
    {
        if(cubes[i]==0)
        {
            for(j=i*i*i;j<=1000000;j+=(i*i*i))
            {
                cubes[j]=1;    
            }
            
        }
    }
    for(i=1;i<=1000000;i++)
    {
        if(cubes[i]==0)//if cube FREE
        {
            count[i]=prev+1;
            prev=count[i];
            
           // printf("%d %d\n",i,count[i]); 
           // getchar();    
        }    
    }    
    scanf("%d",&t);
    while(t)
    {
        cas++;
        scanf("%d",&n);
        
        printf("Case %d: ",cas);
        if(cubes[n]==0)
            printf("%d\n",count[n]);
        else
            printf("Not Cube Free\n");
            
        t--;    
    }
    
    system("pause");    
    return 0;
}

/*#include<stdio.h>
#define N 1000005
#define cubeROOTN 100
unsigned int numbers[N]={0},cubefrees[N]={0};
int searchcubefree(unsigned int tn,unsigned int tlen)
{
    unsigned int low,high,mid;
/*
    for(a=1;a<tlen;a++)
    {
        if(tn==cubefrees[a])
            return a;
    }
    
    return -1;

    low=1;
    high=tlen;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(cubefrees[mid]==tn)
        {
            return mid;
        }
        else
            if(cubefrees[mid]>tn)
            {
                high=mid-1;
            }
            else
                {
                    low=mid+1;
                }
    
    }
    
    return -1;
    
        
}
int main()
{
    unsigned int t,n,i,j,k,x,len;
    char ch;
    int res;
    for(i=2;i<=cubeROOTN;i++)
    {
        if(numbers[i]==0)
        {
            for(j=i*i*i;j<=N;j+=i*i*i)
            {
                numbers[j]=1;
            }
        }
    }
    i=1;
    for(k=1;k<=N;k++)
    {
        if(numbers[k]==0)
        {
            cubefrees[i++]=k;
        }
    }
    len=i-1;
    
    /*
    for(k=0;k<=30;k++)
    {
        printf("%u-%u\n",k,cubefree[k]);
    }
    ch=getchar();
    return 0;
    
    scanf("%u",&t);
    x=1;
    while(t--)
    {
        scanf("%u",&n);
        printf("Case %u: ",x);
        res=searchcubefree(n,len);
        if(res==-1)
        {
            printf("Not Cube Free\n");
        }
        else
            printf("%u\n",res);
        
        x++;
        
    
    }
    
    system("pause");
    return 0;
}
*/
