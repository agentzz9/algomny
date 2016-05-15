#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int R,C;
char grid[505][505];
int visited[505][505];
int turnr[4] = {+0,+1,+0,-1};
int turnc[4] = {+1,+0,-1,+0};
struct vertex
{
    int r,c;
    vertex(int a,int b)
    {
        r = a; c = b;    
    }    
};
queue <vertex> q;
void calcFinalState()
{
    while(!q.empty())
    {
        vertex temp = q.front(); q.pop();
        
		if(grid[temp.r][temp.c]<'a'||grid[temp.r][temp.c]>'z') continue;
		for(int i=0; i<4; i++)
        {
            int nr = temp.r + turnr[i], nc = temp.c + turnc[i]; 
            
            if(nr>=0 && nr<R && nc>=0 && nc<C && grid[nr][nc]!='#' && grid[nr][nc]!='*')
            {
				if(grid[nr][nc]=='.')
                {
					grid[nr][nc] = grid[temp.r][temp.c];
					visited[nr][nc] = visited[temp.r][temp.c] + 1;
					q.push(vertex(nr,nc)); 
				}
				else if(grid[nr][nc]!=grid[temp.r][temp.c] && visited[nr][nc]==visited[temp.r][temp.c] + 1)
				{
					grid[nr][nc] = '*';
				}
				            
            }
            
        }
        
        
        /*
        printf("\n______________________________\n");
        for(int i=0;i<R;i++)
        {
			for(int j=0;j<C;j++)
			{
				printf("%c ",grid[i][j]);
			}printf("\n");
		}printf("-------------------------------\n");
        for(int i=0;i<R;i++)
        {
			for(int j=0;j<C;j++)
			{
				printf("%d ",visited[i][j]);
			}printf("\n");
		}
		printf("\n");
		
		
		getchar();
																											*/
    }
}
int main()
{
    int T;
 
    scanf("%d",&T);
    while(T--)
    {
        
        scanf("%d %d",&R,&C);
        for(int i=0; i<R; i++)
        {
                scanf("%s",&grid[i]);
                for(int j=0; j<C; j++)
                {
                    if(grid[i][j]>='a' && grid[i][j]<='z')
                    {
                        q.push(vertex(i,j));
                    }    
                }
        }
        
        calcFinalState();
        
     
        for(int i=0; i<R; i++)
        {
            printf("%s\n",grid[i]);    
        }
        printf("\n");
        
        
        for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            grid[i][j]=NULL; 
        
        
        for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            visited[i][j]=0;
	
    }
    
    
  
    return 0;    
}
