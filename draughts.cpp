#include<iostream>//furik pairs, rubik no. of rooms...
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,furik=0,rubik,room[50005]={0},v[50005]={0},ones=0,nc2=0;
vector<int> path[50005];

int dfs(int i)
{
    v[i]=1;
    
   // cout<<"("<<room[i]<<")"<<"-"<<i<<"->";
    
    vector<int>::iterator x=path[i].begin();
     
     while(x!=path[i].end())
     {
            if(v[*x]!=1)
            {
                
                if(room[*v]==1)
                    ones++;
                dfs(*x);
                
                
    
            }
            x++;
     }
    
    //
      
    return 0;
}
    

int main()
{
    
    int i,l,m,p,q;
    
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&room[i]);
        
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&p,&q);
        path[p].push_back(q);
        path[q].push_back(p);
    }
    
    
    for(i=1;i<=n;i++)
    {
        if((v[i]==0)&&(room[i]==1))
        {
            ones++;
            dfs(i); 
            nc2=((ones)*(ones-1))/2;
            ones=0;
            furik=furik+nc2;
           
        }
    }
    
    printf("%d\n",furik);
  
    getchar();getchar();
    return 0;
}
