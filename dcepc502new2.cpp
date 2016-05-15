#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node
{
	int r,c;
	node(int a,int b)
	{
		r=a;
		c=b;
	}
};
char grid[15][15];				// 1 = white, 2= black... lets say...turn = 1, 2
int visited[15][15];
int M,N;
int turn_r[8]={-1, -2, -2, -1, +1, +2, +2, +1};
int turn_c[8]={+2, +1, -1, -2, -2, -1, +1, +2};
int maximum, no_of_nodes;
int opposite(int x)
{
	return (x==1)?2:1;
}
bool isSafe(node current, int turn)
{
	bool result = true;
	for(int i=0; i<8; i++)
	{
		int nr = current.r + turn_r[i];
		int nc = current.c + turn_c[i];
		if(nr>=M || nr<0 || nc>=N || nc<0 || grid[nr][nc]=='#' || visited[nr][nc]==0)
			continue;
		if(visited[nr][nc]==opposite(turn))
		{
			result = false;
			break;
		}
	}
	return result;
}
void solve(int turn, int occupied ,queue<node> Q)
{
	int popped = 0;
	maximum = (occupied>=maximum)?occupied:maximum;
	if(maximum == no_of_nodes)
		return ;
	while( occupied+popped < no_of_nodes && !Q.empty() )
	{
		node temp = Q.front(); Q.pop();
		popped++;
		
		if(!isSafe(temp, turn))
			continue;
			
		visited[temp.r][temp.c] = turn;
		solve(opposite(turn), occupied+1, Q);
		
		visited[temp.r][temp.c] = 0;
		Q.push(temp);
		
	}
	
}


int main()
{
	int T, temp;
	
	scanf("%d",&T);
	while(T--)
	{
		maximum = 0;
		no_of_nodes = 0;
		queue<node> Q;
	
		scanf("%d %d",&M,&N);
		for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]=='.')
			{
				visited[i][j] = 0;
				Q.push(node(i,j));
				no_of_nodes++;
			}
			else
				visited[i][j] = -1;
		}
		
		temp = no_of_nodes;
		while(temp--)
		{
			node current = Q.front(); Q.pop();
			visited[current.r][current.c] = 1;
			
			solve(2, 1, Q);
			
			visited[current.r][current.c] = 0;
			Q.push(current);
			
		}
		
		printf("\n%d",maximum);
		
	}
	return 0;
}
