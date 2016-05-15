#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define TENR5 100005

using namespace std;

int keyArray[TENR5], N; 
bool isADoor[TENR5], isOpen[TENR5], visited[TENR5];
vector<int> graph[TENR5];
queue<int> Q,P;

void showGraph()
{
	cout<<"___________GRAPH_____________________\n";
	for(int i=1; i<=N; i++)
	{	
		cout<<i<<"->";
		for(int j=0; j<graph[i].size(); j++)
		{
			cout<<graph[i][j]<<"->";
		}
		cout<<endl;
	}
	cout<<"___________END GRAPH_____________________\n";
	
}

void clearStuff()
{
	while(!Q.empty())
		Q.pop();
	while(!P.empty())
		P.pop();
		
	for(int i=0; i<TENR5; i++)
	{
		keyArray[i] = -1;
		isADoor[i] = false;
		isOpen[i] = true;
		visited[i] = false;
		graph[i].clear();
	}
}

bool solveUsingBfs()
{
	Q.push(1);
	visited[1] = true;
	
	while( !Q.empty() )
	{
		while( !Q.empty() )
		{
			int temp = Q.front(); Q.pop();
			//cout<<temp<<" ";
			int sIze = graph[temp].size();
			for(int i=0; i<sIze; i++)
			{	int neigh = graph[temp][i];
				
				if(neigh == N) return true;
				if(!visited[neigh])
				{
					if(!isOpen[neigh])
					{
						visited[neigh]	= true;	
						continue;
					}		
					if(keyArray[neigh])
					{
						isOpen[keyArray[neigh]] = true;
						P.push(keyArray[neigh]);
					}
					visited[neigh] = true;
					Q.push(neigh);
				}
			}
		}
		while( !P.empty() )
		{
			int t = P.front(); P.pop();
			if(visited[t])
				Q.push(t);
		}
	}
	return false;
}

bool dfs(int vertex, int lastgraphertex, vector<int> graph[TENR5], bool visited[TENR5], bool isOpen[TENR5], int keyArray[TENR5])
{
	//cout<<vertex<<" ";
	if(vertex == lastgraphertex)
		return true;
	
	visited[vertex] = true;
	if(keyArray[vertex])
	{
		isOpen[ keyArray[vertex] ] = true;
	}
	
	for(int i=0; i<graph[vertex].size(); i++)
	{
		if(!visited[graph[vertex][i]] && isOpen[graph[vertex][i]])
		{
			if(dfs(graph[vertex][i], lastgraphertex, graph, visited, isOpen, keyArray) )
				return true;
			
			visited[vertex] = false;
		}
		if(!visited[graph[vertex][i]] && !isOpen[graph[vertex][i]])
		{
			visited[vertex] = false;
		}
		
	}
	return false;
}
bool solveUsingDfs()
{
	return dfs(1, N, graph, visited, isOpen, keyArray);
}

int main()
{
	int K, M, a, b;
	char verdict;
	while(true)
	{
		clearStuff();
		
		scanf("%d %d %d", &N, &K, &M);
		if(N==-1 && K==-1 && M==-1)
			break;
		for(int i=0; i<K; i++)
		{
			scanf("%d %d", &a, &b);	
			keyArray[a] = b;
			isADoor[b] = true;
			isOpen[b] = false;
		}

		for(int i=0; i<M; i++)
		{
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}	
		
	//	showGraph();
		
		verdict = (solveUsingBfs())?'Y':'N';
		printf("\n%c", verdict);
		
	}
}


