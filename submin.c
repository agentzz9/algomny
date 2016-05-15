#include<stdio.h>
int fn(int tn,int ta[55],int tk)
{
    int num,i,j,k,min=-1,count=0;
    for(num=0;num<=tn-1;num++)
    {
        for(i=0;i<(tn-num);i++)
        {
            k=i+num;
            min=ta[i];
            for(j=i;j<=k;j++)
            {
               // printf("%d, ",ta[j]);
                if(ta[j]<min)
                {
                    min=ta[j];
                }
            
            }
            if(min==tk)
                count++;
            
            //printf("\n");
        }
        //printf("\n");
    }
    
    
    return count;
    
}

int main()
{
    int i,n,a[55],q,k,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
           
    }
    scanf("%d",&q);
    while(q)
    {
        scanf("%d",&k);
        ans=fn(n,a,k); 
        printf("%d\n",ans);
        --q;
    }
    
    system("pause");
    return 0;
    
    
    
    
}
