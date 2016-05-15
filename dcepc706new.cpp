#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#define max2(a,b) (a>b?a:b)
#define max3(a,b,c) (a>max2(b,c)?a:max2(b,c))
#define INF 999999
using namespace std;

char grid[210][210];
int time_grid[210][210],min_of_time_grid;
int visited1[210][210],visited2[210][210],visited3[210][210],r1,r2,r3,c1,c2,c3;
int M,N;
int turn_r[4]={+0,+1,+0,-1};
int turn_c[4]={+1,+0,-1,+0};

struct vertex
{
	int r,c,type;
	vertex(int a,int b,int x)						// 0= null, 1,2,3= the three people, 4=. 5=#.
	{
		r=a;c=b;
		type=x;
	}
};

queue<vertex> Q;

int check_visited_type(vertex v)
{
	switch(v.type)
	{
		case 1: return visited1[v.r][v.c]; 
		case 2: return visited2[v.r][v.c]; 
		case 3: return visited3[v.r][v.c]; 
		default:;
	}
	return 0;
}
void set_visited_type(vertex v,vertex p)
{
	switch(v.type)
	{
		case 1: visited1[v.r][v.c] = visited1[p.r][p.c] + 1;break;
		case 2:	visited2[v.r][v.c] = visited2[p.r][p.c] + 1;break;
		case 3:	visited3[v.r][v.c] = visited3[p.r][p.c] + 1;break;
		default: break;
		
	}
	
}
int all_three_at(vertex curr_vertex)
{
	return (visited1[curr_vertex.r][curr_vertex.c] && visited2[curr_vertex.r][curr_vertex.c] && visited3[curr_vertex.r][curr_vertex.c]);
}

int calc_usingbfs()
{
	Q.push(vertex(r1,c1,1)); visited1[r1][c1]++;
	Q.push(vertex(r2,c2,2)); visited2[r2][c2]++;
	Q.push(vertex(r3,c3,3)); visited3[r3][c3]++;
	
	
	while(!Q.empty())
	{
		vertex curr_vertex = Q.front(); Q.pop();
		
		if(all_three_at(curr_vertex))
		{
			time_grid[curr_vertex.r][curr_vertex.c] = max3(visited1[curr_vertex.r][curr_vertex.c],visited2[curr_vertex.r][curr_vertex.c],visited3[curr_vertex.r][curr_vertex.c]);
			if(time_grid[curr_vertex.r][curr_vertex.c] < min_of_time_grid)
			{
				min_of_time_grid = time_grid[curr_vertex.r][curr_vertex.c];	
			}	
		}
		
				
		for(int i=0; i<4; i++)
		{
			vertex next_vertex = vertex(curr_vertex.r+turn_r[i], curr_vertex.c+turn_c[i], curr_vertex.type);
			
			if(next_vertex.r>=M || next_vertex.r<0 || next_vertex.c<0 || next_vertex.c>=N || grid[next_vertex.r][next_vertex.c]=='#')
				continue;
			
			else if(!check_visited_type(next_vertex))
			{
				Q.push(next_vertex);
				set_visited_type(next_vertex,curr_vertex);
		
			}		
		}
		
	}
	return min_of_time_grid - 1;
}
int main() 
{
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&M,&N);
		for(int i=0; i<=209; i++)
		for(int j=0; j<=209; j++)
		{	
			grid[i][j]='.';	
			visited1[i][j]=0;
			visited2[i][j]=0;
			visited3[i][j]=0;
			time_grid[i][j]=0;
		}
		while(!Q.empty()){ Q.pop(); }
		min_of_time_grid = INF;
		
		
		for(int i=1; i<=M; i++)
		for(int j=1; j<=N; j++)
		{	
			cin>>grid[i][j];
			if(grid[i][j]!='.' && grid[i][j]!='#')
			{
				switch(grid[i][j])
				{
					case '1': r1=i;c1=j;break;
					case '2': r2=i;c2=j;break;
					case '3': r3=i;c3=j;break;
					default: break;
				}
			}
		}
		M+=2;N+=2;
		
		printf("%d\n",calc_usingbfs());
		
	
	}
	return 0;
}
