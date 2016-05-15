#include<iostream>
#define MOD 2147483647 //2^31-1
using namespace std;
char grid[1005][1005]={NULL};
int mark[1005][1005]={0};
int n,i,j;
long long count=0;
long long answer=1;
int flag=0;

int nx,ny,turnx[4]={1,0,-1,0},turny[4]={0,1,0,-1};

int dfs1(int tx,int ty)
{
    int k;

    if(tx==n-1&&ty==n-1)
    {
        (::count++)%MOD;
        flag=1;
        
    }
    
    else
    {
        for(k=0;k<=1;k++)
        {
            nx=tx+turnx[k];
            ny=ty+turny[k];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&grid[nx][ny]!='#')
                dfs1(nx,ny);
            
        }
    }
}
int dfs2(int tx,int ty)
{
    int k;

    if(tx==n-1&&ty==n-1)
    {
        answer=2;
        return 0;
    }
    else
    {
        for(k=0;k<=3;k++)
        {
            nx=tx+turnx[k];
            ny=ty+turny[k];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&grid[nx][ny]!='#'&&mark[nx][ny]!=1)
            {    
                mark[nx][ny]=1;
                dfs2(nx,ny);
                mark[nx][ny]=0;
            }
        }
    }
}

    
int main()
{
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
            scanf("%s",&grid[i]);      
    }
    dfs1(0,0);
    if(::count==0)
    {
        if(flag==1)
        {
            printf("%lld",::count);
            fflush(stdin);
            getchar();
            return 0;
        }
            
        
                  
        mark[0][0]=1;
        dfs2(0,0);
        mark[0][0]=0;
        if(answer==2)
        {
            printf("THE GAME IS A LIE");
            fflush(stdin);
            getchar();
            return 0;
        }
        else
        {
              printf("INCONCEIVABLE");
            fflush(stdin);
            getchar();
            return 0;
        }
        
            
    }
    else
    {
        printf("%lld",::count);
        fflush(stdin);
        getchar();
        return 0;
    }
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%c",grid[i][j]);
        }
        printf("\n");
    }
    */
    
}
