#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n,t,i,max,count,f[100000],p,flag,count2;
    char a[100000];
    
    scanf("%d",&n);
    
    while(n>0)
    {
        t=0;
        p=0;
        count2=1;
        max=0;
        int f[100000];
        char a[100000];
        
        
        scanf(" %[^\r\n]",a);//MEANING!!!!!! and y THIS works and not the other thing :(
        fflush(stdin);
        //gets(a);
        t=strlen(a);
        
        //cout<<"len"<<t<<endl;system("pause");
        if(t==0)
        {
            continue;
        }
        if(t>0)
        {
            count=0;
            flag=-1;
            if(a[t-1]!=' ')
            {
                a[t++]=' ';
                a[t]='\0';
            }
            for(i=0;a[i]!='\0';i++)
            {
                if(a[i]>='a'&& a[i]<='z')
                {
                    count++;
                    
                }
                if(a[i]==' ')
                {   
                    flag=1;
                    int r=i;
                    while(a[r]==' ')
                    {
                        r++;
                    }
                    i=r;
                    
                }
                if(flag==1)
                {
                    f[p++]=count+1;
                    count=0;
                    flag=0;
                }
               
            }
            f[p]=-1;
            f[0]--;
                
         /* for(int e=0;f[e]!=-1;e++)
            {
                cout<<f[e];
            }
          //  system("pause");
           */ 
        }
        count2=1;
        max=0;
        for(int e=1;e<=p;e++)
        {
             if(f[e-1]==f[e])
             {
                    count2++;
                }
                else
                {
                    count2=1;
                }
                
                if(count2>max)
                {
                    max=count2;
                }
                
                /*else
                {
                    count2=1;
                    max=-1;
                }*/
                
            
        }
     
        cout<<max<<endl;
       // system("pause");
        n--;
    }
    system("pause");
    return 0;
}
