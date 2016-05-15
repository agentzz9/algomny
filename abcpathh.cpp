#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
char grid[55][55];
int visited[55][55]={0};
int turnr[8]={-1,-1,0,1,1,1,0,-1},turnc[8]={0,1,1,1,0,-1,-1,-1},h,w;
struct node
{
    int r,c;
    char val;
    node(int tr,int tc,char tval)
    {
        r=tr;c=tc;val=tval;    
    }    
};
queue<node> Q;

int solve(int r,int c)  //bfs
{
    int nr,nc,last;
    
    Q.push(node(r,c,grid[r][c]));
    
    while(!Q.empty())
    {
        node t=Q.front();
        Q.pop();
        last=t.val;
        visited[t.r][t.c]=1;
        
        for(int i=0;i<8;i++)
        {
            nr=t.r+turnr[i];
            nc=t.c+turnc[i];
            if(nr>=0&&nr<h&&nc>=0&&nc<w&&grid[nr][nc]==t.val+1&&!visited[nr][nc])
            {   
               
                Q.push(node(nr,nc,grid[nr][nc]));
                visited[nr][nc]=1;
            }   
        }
        
    }
    return (int)(last-'A')+1;
        
}
int main()
{
    int t=1;
    while(1)
    {
        
        int solution=0,max=0;
        for(int i=0;i<55;i++) 
        for(int j=0;j<55;j++)
            visited[i][j]=0;    
        
        scanf("%d %d",&h,&w);
        if(h==0&&w==0) break;
        
        for(int r=0;r<h;r++)
        {  
                scanf("%s",&grid[r]);        
        }
        
        for(int r=0;r<h;r++)
        {
            for(int c=0;c<w;c++)
            {
                if(grid[r][c]=='A')
                {
                    solution=solve(r,c);
                    if(solution>=max)
                        max=solution;
                
                }    
                
            }    
        }
        
        printf("Case %d: %d\n",t++,max);
        
    }
    system("pause");
    return 0;    
}
