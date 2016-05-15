#include<cstdio>

using namespace std;
int main()
{
    
    int i,n,k,t,count=0;
    
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);  
        if(t%k==0)
        {
            count++;
        } 
         
    }
    printf("\n%d",count);
    
  //  system("pause");
}
