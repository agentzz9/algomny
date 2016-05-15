#include<stdio.h>
/*float convert(float a)
{
    float x;
    int y;
    x=1000000*a;
    y=x/10000;
    x=y*10000;
    a=x/1000000;
    
    return a;
}*/
int main()
{
    int t,i,u,n,m,c,pos;
    float r,d,lastmonth,xps,min;
    scanf("%d",&t);
    while(t)
    {
        scanf("%f %d %d",&d,&u,&n);
        
        //d=convert(d);
        
        lastmonth=d*u;
        min=lastmonth;
        pos=0;
        for(i=0;i<=n-1;i++)
        {
            scanf("%d %f %d",&m,&r,&c);
            
          //  r=convert(r);
            
            xps=(c+(u*r*m))/m;
            if(xps<min)
            {
                min=xps;
                pos=i;
            }
        }
        if(min==lastmonth)
        {
            printf("0\n");
        }
        else if(min!=lastmonth)
        {
            printf("%d\n",pos+1);
        }
            
            
            
        t--;
    }
   // system("pause");
    return 0;
}
 

