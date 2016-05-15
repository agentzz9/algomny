#include<iostream>
#include<cstdio>
using namespace std;
char grid[15][15];
int M,N;
int turn_r[8]={-1, -2, -2, -1, +1, +2, +2, +1};
int turn_c[8]={+2, +1, -1, -2, -2, -1, +1, +2};
int max_depth, max_depth_outer;
int last;
bool doesntAttackAnyFrom(int r, int c, int visited[15][15], int x)
{

	x = (x==2)?1:2;
	for(int i=0; i<8; i++)
	{
		int nr = r + turn_r[i];
		int nc = c + turn_c[i];
		if(nr>=M || nr<0 || nc>=N || nc<0 || grid[nr][nc]=='#' || visited[nr][nc]==0)
			continue;
		if(visited[nr][nc]!=x)
			return false;
	}
	return true;
}

int solveUsingDfs(int r, int c, int visited[15][15], int depth)
{
	
//	cout<<"1:"<<endl;
	if(grid[r][c]=='#' || visited[r][c]) return 0;
//	cout<<"2:"<<endl;
	printf("depth=%d, (%d,%d): %c \n", depth, r, c, grid[r][c]);
	
	visited[r][c] = (last==2)?1:2;
	last = (last==2)?1:2;
	
//	cout<<"3:"<<endl;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			printf("%d ",visited[i][j]);
		}cout<<endl;
	}cout<<endl;
	getchar();
//	cout<<"4:"<<endl;
	max_depth = (depth>max_depth)?depth:max_depth;
	for(int nr=0; nr<M; nr++)
	for(int nc=0; nc<N; nc++)
	{
//		cout<<"5:"<<endl;
		if(nr==r && nc==c) {
//			cout<<"6:"<<endl;
			continue;	
		}
		if(nr>=0 && nc>=0 && nr<M && nc<N && grid[nr][nc]!='#' && !visited[nr][nc] && doesntAttackAnyFrom(nr,nc,visited,last))
		{
//			cout<<"7:"<<endl;
			solveUsingDfs(nr, nc, visited, depth+1);
		}
	}
//	cout<<"8:"<<endl;
	return max_depth;
}

int main()
{
	int T;
	int visited[15][15];
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&M,&N);
		for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
		{
			cin>>grid[i][j];
			visited[i][j] = 0;
		}
		max_depth_outer = 0;
		
		for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
		{
			max_depth = 0;
		//	visited[i][j]=(flag)?1:2;
		//	flag = !flag;
			
//			cout<<"next Iter:"<<endl;
		
			last = 2;
			solveUsingDfs(i, j, visited, 1);
			
			max_depth_outer = (max_depth_outer>max_depth)?max_depth_outer:max_depth;
			
			for(int a=0;a<M;a++){for(int b=0;b<N;b++){visited[a][b]=0;}}
		}
		
		printf("%d\n", max_depth_outer);
	
	
	}
	return 0;
}
