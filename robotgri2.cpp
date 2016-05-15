#include<iostream>
#include<queue>
#define MOD 2147483647 //2^31-1
using namespace std;
struct node
{
    int r,c;
    char val;
    node(int tr,int tc,char tval)
    {
        r=tr;c=tc;val=tval;
    }
};
queue<node> q;
        
char grid[1005][1005]={NULL};
int mark[1005][1005]={0},turnr[4]={1,0,-1,0},turnc[4]={0,1,0,-1};
int answer=1,n,nr,nc,flag=0;
long long dp[1005][1005]={0},count=0;

int bfs(int tr,int tc)
{
    while(!q.empty())
    {
        int k;
        node obj=q.front();
        q.pop();
        mark[tr][tc]=1;
        
        if((obj.r==n-1)&&(obj.c==n-1))
        {
            return 2;
        }
        for(k=0;k<=3;k++)
        {
            nr=obj.r+turnr[k];
            nc=obj.c+turnc[k];
            if((nr<n)&&(nc<n)&&(nr>=0)&&(nc>=0)&&(mark[nr][nc]==0)&&(grid[nr][nc]!='#'))
            {
                    node newobj(nr,nc,grid[nr][nc]);
                    q.push(newobj);
                    mark[nr][nc]=1;
                   
            }
        }
    }
    return 3;
}
        
/*int dfs2(int tr,int tc)
{
    int k;

    if(tr==n-1&&tc==n-1)
    {
        answer=2;
        return 0;
    }
    else
    {
        for(k=0;k<=3;k++)
        {
            nr=tr+turnr[k];
            nc=tc+turnc[k];
            if(nr>=0&&nc>=0&&nr<n&&nc<n&&grid[nr][nc]!='#'&&mark[nr][nc]!=1)
            {    
                mark[nr][nc]=1;
                dfs2(nr,nc);
                mark[nr][nc]=0;
            }
        }
    }
}
*/

int main()
{
    int i,j,k,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
            scanf("%s",&grid[i]);      
    }
    // NO. OF PATHS CALCULATED HERE
    //first row
    for(i=0;i<n;i++)
    {
        if(grid[0][i]!='#')
        {
            dp[0][i]=1;
        }
        else
        {   dp[0][i]=0;
            break;
        }
    }
    while(++i<n)
    {
        dp[0][i]=0;
    }
    //first column
    for(i=0;i<n;i++)
    {
        if(grid[i][0]!='#')
        {
            dp[i][0]=1;
        }
        else
        {   dp[i][0]=0;
            break;
        }
    }
    while(++i<n)
    {
        dp[i][0]=0;
    }
    //rest of the grid
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(grid[i][j]!='#')
            {   
                dp[i][j]=((dp[i-1][j]%MOD)+(dp[i][j-1]%MOD))%MOD;
                continue;
            }
            if(grid[i][j]=='#')
            {
                dp[i][j]=0;
            }
        }
    }
    
    /////TILL HERE
    
    if(dp[n-1][n-1]!=0)
    {
        printf("%lld",dp[n-1][n-1]);
        fflush(stdin);
        getchar();
        return 0;
    }
    else 
    {
//////////////////////////////////////////////
        /*mark[0][0]=1;
        dfs2(0,0);
        mark[0][0]=0;
        */
        node obj(0,0,grid[0][0]);
        q.push(obj);
        answer=bfs(0,0);
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
            
    
    return 0;
} 
  
