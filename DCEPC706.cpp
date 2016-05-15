#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

char grid[210][210];
int visited1[210][210],visited2[210][210],visited3[210][210],r1,r2,r3,c1,c2,c3;
int M,N,level;
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

void printvisiteds()
{

	cout<<"______________________________________________________________________________"<<endl;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<visited1[i][j]<<"  ";
		}cout<<endl;
	}
	
	cout<<"______________________________________________________________________________"<<endl;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<visited2[i][j]<<"  ";
		}cout<<endl;
	}
	
	
	cout<<"______________________________________________________________________________"<<endl;
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<visited3[i][j]<<"  ";
		}cout<<endl;
	}

	cout<<"______________________________________________________________________________"<<endl;


}
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
void set_visited_type(vertex v)
{
	switch(v.type)
	{
		case 1: visited1[v.r][v.c]=1; break;
		case 2: visited2[v.r][v.c]=1; break;
		case 3: visited3[v.r][v.c]=1; break;
		default: break;
		
	}
	
}
int all_three_at(vertex curr_vertex)
{
	return (visited1[curr_vertex.r][curr_vertex.c] && visited2[curr_vertex.r][curr_vertex.c] && visited3[curr_vertex.r][curr_vertex.c]);
}

int calc_usingbfs()
{
	Q.push(vertex(r1,c1,1)); visited1[r1][c1]=1;
	Q.push(vertex(r2,c2,2)); visited2[r2][c2]=1;
	Q.push(vertex(r3,c3,3)); visited3[r3][c3]=1;
	Q.push(vertex(0,0,0));
	
	while(!Q.empty())
	{
		
		vertex curr_vertex = Q.front(); Q.pop();
		
		printf("\n(%d,%d), %d ",curr_vertex.r,curr_vertex.c,level);
				
		if(curr_vertex.type==0)
		{
			level++;
			if(!Q.empty())
			{
				Q.push(vertex(0,0,0));
				
				continue;
			}
			else	break;
		}
		
		set_visited_type(curr_vertex);
		
		if(all_three_at(curr_vertex))
		{
		
			printf("\n\t(%d,%d)\t\n",curr_vertex.r,curr_vertex.c);
		//	getchar();
			break;
		}
		else
		{
			for(int i=0; i<4; i++)
			{
				vertex next_vertex = vertex(curr_vertex.r+turn_r[i], curr_vertex.c+turn_c[i], curr_vertex.type);
				
				if(next_vertex.r>=M || next_vertex.r<0 || next_vertex.c<0 || next_vertex.c>=N || grid[next_vertex.r][next_vertex.c]=='#')
					continue;
				
				else if(!check_visited_type(next_vertex))
				{
					Q.push(next_vertex);
					set_visited_type(next_vertex);
				}		
			}
		}
	}
	return level;
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
		}
		while(!Q.empty()){ Q.pop(); }
		
		
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
		M+=2;N+=2;level=0;
		/*
		for(int i=0; i<M; i++)
		{	
			for(int j=0; j<N; j++)
			{	printf("%d,%d: %c ",i,j,grid[i][j]);	}
			printf("\n");
		}
		*/
		printf("%d\n",calc_usingbfs());
		printvisiteds();
	
	}
	return 0;
}
