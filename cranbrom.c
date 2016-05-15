#include<stdio.h>
#include<string.h>
#include<algorithm.h>
int main()
{
    int n,i,L[10005],j,k,l,t,m;//found = +ve 0=48
    char str[50];
    
   // char ch='0';
   // printf("%d",((int)ch-48));
    
    scanf("%d",&n);
    
    j=0;
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        gets(str);
        fflush(stdin);
        if(str[0]=='f')
        {
            k=6;t=0;
            while(str[k]!='\0')
            {
                    m=(int)(str[k]-'0');
                    t=t*10+m;
                    k++;
            }
            L[i]=t;        
               
            
           // printf("%d",L[i]);
           // getchar();
        }
          
        else
        {
           k=7;t=0;
            while(str[k]!='\0')
            {
                    m=(int)(str[k]-'0');
                    t=t*10+m;
                    k++;
            }
            L[i]=-t;
            
            
           // printf("%d",L[i]);
        }
        
    }//end of n inputs,L ready now
    
   /* for(i=0;i<n;i++)
    {
        printf("\n%d\n",L[i]);
    }
    getchar();
    */
    
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            
    
}
