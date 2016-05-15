#include<cstdio>
#include<fstream>
using namespace std;
int main()
{
    int n=1,N,I,P[2005],C,smaller,other,i,j;
    
    scanf("%d",&N);
    while(n<=N)
    {
        scanf("%d",&C);
        scanf("%d",&I);
        for(i=1;i<=I;i++)
        {
            scanf("%d",&P[i]);
        }
        
        
        for(i=1;i<=I;i++)
        {
            for(j=1;j<=I;j++)    
            {
                 if(P[i]+P[j]==C)
                 {
                        smaller=(i<=j)?i:j;
                        if(smaller==i)
                             other=j;
                            else
                              other=i;
                         break;      
                  } 
                  
            }
            
        }
                
        
        printf("Case #%d: %d %d\n",n,smaller,other);
        n++;   
    }
       
   // system("pause");
    return 0;    
}
