#include<stdio.h>
int alpha[4];
int i,j,n,twon,index;
char a1[100005],a2[10005];
void recursive(int index,int prev)
{
    int k;
    for(k=0;k<=3;++k)
    {
        if(index<twon&&alpha[k]>0&&a1[index]!=(char)(k+(int)'A')&&prev!=k)
        {
            a2[index]=(char)(k+(int)'A');
            --alpha[k];
            recursive(index+1,k);
            ++alpha[k];
        }
    }
    
}   
int main()
{
   char *ans;
    
    scanf("%d",&n);
    for(i=0;i<=3;++i)
        alpha[i]=n;
        
    twon=2*n;
        
    scanf("%s",a1);
    for(i=0;a1[i]!='\0';++i)
    {
        switch(a1[i])
        {
            case 'A':alpha[0]--;break;
            case 'B':alpha[1]--;break;
            case 'C':alpha[2]--;break;
            case 'D':alpha[3]--;break;
        }
    }
    //fill first
    recursive(0,-1);
    
    //printf("%s %d%d%d%d",a1,alpha[0],alpha[1],alpha[2],alpha[3]);
          
    printf("%s",a2);
    
    printf("%s %d%d%d%d",a1,alpha[0],alpha[1],alpha[2],alpha[3]);
      
    system("pause");
    
    return 0;
}

    
