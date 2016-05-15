#include<iostream>
#include<cstdio>
#include<queue>
#define INF 900000000
using namespace std;
char grid[205][205];
int time_at[205][205],time_elapsed[205][205];
int r1,c1,r2,c2,M,N;
int turn_r[4]={-1,+0,+1,+0};
int turn_c[4]={+0,+1,+0,-1};
struct node
{
    int r,c;
    node(int x,int y)
    {
        r=x;
        c=y;
    }        
};
queue<node> Q;
int solve_by_djk(int r1,int c1)
{
	int time_elapsed_nrnc;
	
	Q.push(node(r1,c1));
	time_elapsed[r1][c1]=time_at[r1][c1];
	
	while(!Q.empty())
	{
		node temp=Q.front(); Q.pop();
		for (int i=0; i<4; i++)
		{
			int nr = temp.r + turn_r[i], nc = temp.c + turn_c[i];
			if (nr<0 || nc<0 || nr>=M || nc>=N) continue;
			
			if(grid[nr][nc]=='.')
			{
				
				time_elapsed_nrnc = time_elapsed[temp.r][temp.c] + time_at[nr][nc] + 1;
				
				if(time_elapsed_nrnc < time_elapsed[nr][nc])
				{
					time_elapsed[nr][nc] = time_elapsed_nrnc;
					Q.push(node(nr,nc));
				}
	
				
			}
			else if(grid[nr][nc]=='#')
			{
				
				
				if(time_elapsed[temp.r][temp.c] < time_at[nr][nc])
				{
					int time_remaining = time_at[nr][nc] - time_elapsed[temp.r][temp.c];
					time_elapsed_nrnc = time_remaining + time_elapsed[temp.r][temp.c];
					
				}
				else if(time_elapsed[temp.r][temp.c] >= time_at[nr][nc])
				{
					time_elapsed_nrnc = time_elapsed[temp.r][temp.c] + 1;
				}
	
				if(time_elapsed_nrnc < time_elapsed[nr][nc])
				{
					time_elapsed[nr][nc] = time_elapsed_nrnc;
					Q.push(node(nr,nc));
				}
	
	
				
			}
		}
		
	}
	
	return time_elapsed[r2][c2];
	
}
int main()
{
    int T;
    
    scanf("%d",&T);
    while(T--)
    {
    	
        scanf("%d %d", &M, &N);
        for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
        {   
			time_elapsed[i][j]=INF;
		}
        for(int i=0; i<M; i++)
        {
            scanf("%s",&grid[i]);
        }
        for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
        {
            scanf("%d",&time_at[i][j]);    
		}
        scanf("%d %d", &r1, &c1);
        scanf("%d %d", &r2, &c2);
        printf("%d\n", solve_by_djk(r1,c1));
    }
   
    return 0;
}
