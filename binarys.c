#include<stdio.h>
char arr[200]="hello";
void generate(int n,int k)
{
    int j;
    if(n<1)
        printf("%s\n",arr);
    else
    {
        for(j=0;j<k;j++)
        {
            arr[n-1]=j;
            generate(n-1,k);
        }
    }
    
}
   
int main()
{
 
    int n,k;
    n=5;k=3;
    
    generate(n,k);
    system("pause");
    return 0;
}
 
    
