#include<cstdio>
#include<iostream>
using namespace std;
bool breakcondition(int top, int right, int down, int left)
{
    return (top>down || left>right);    
}
void spiralprint(int a[100][100],int r,int c)
{
    int top, right, down, left;
    top = 0;
    right = c-1;
    down = r-1;
    left = 0;
    
    while(1)
    {
        for(int i=left; i<=right; i++)
        {
            printf("%d ",a[top][i]);    
        }
        top++;
        if(breakcondition(top,right,down,left)) break;
        
        for(int i=top; i<=down; i++)
        {
            printf("%d ",a[i][right]);    
        }
        right--;
        if(breakcondition(top,right,down,left)) break;
        
        for(int i=right; i>=left; i--)
        {
            printf("%d ",a[down][i]);
        }
        down--;
        if(breakcondition(top,right,down,left)) break;
        
        for(int i=down; i>=top; i--)
        {
            printf("%d ",a[i][left]);    
        }
        left++;
        if(breakcondition(top,right,down,left)) break;
        
    }  
    
    
}
int main()
{

    int r,c,a[100][100];
    
    scanf("%d %d",&r,&c);
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);    
            
        }    
    }
    printf("\n");
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);    
            
        }    cout<<endl;
    }
    cout<<endl;
    
    
    spiralprint(a,r,c);
    

    system("pause");
    return 0;
}
