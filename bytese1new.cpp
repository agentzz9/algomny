#include<iostream>
#include<cstdio>
#include<queue>
#include<cstdlib>
using namespace std;
struct vertex
{
    int r,c;
    vertex(int a,int b)
    {
        r=a;
        c=b;
    }    
};
int time_at[105][105],m,n;
int a,b,T,index;
int turn_row[4] = {-1, +0, +1, +0}; 
int turn_col[4] = {+0, +1, +0, -1};
int *time_vector,*prev;
priority_queue<vertex> Q;
int indexOf(int r,int c)
{
    return n*r+c;        
}
bool operator<(const vertex &a, const vertex &b) 
{
  return time_vector[indexOf(a.r,a.c)] > time_vector[indexOf(b.r,b.c)];
}
void calcTimeVectorUsingDijkstra()
{
    
    Q.push(vertex(0,0));

    while(!Q.empty())
    {
            
            vertex temp = Q.top();Q.pop();
        
            
            for(int i=0; i<4; i++)
            {
                int nr,nc,timE;
                nr=temp.r+turn_row[i]; nc=temp.c+turn_col[i];
                
                if(nr>=0 && nc>=0 && nr<m && nc<n)
                {    
                    timE = time_vector[indexOf(temp.r,temp.c)] + time_at[nr][nc];
                    
                    if(time_vector[indexOf(nr,nc)] == -1)
                    {
                        time_vector[indexOf(nr,nc)] = timE;
                        prev[indexOf(nr,nc)] = indexOf(temp.r,temp.c);
                        Q.push(vertex(nr,nc));
                           
                    }    
                    else if (time_vector[indexOf(nr,nc)] > timE)
                    {
                        time_vector[indexOf(nr,nc)] = timE;
                        prev[indexOf(nr,nc)] = indexOf(temp.r,temp.c); 
                        Q.push(vertex(nr,nc));
                        
                    }
                }
            }
      

    }   

}
int main()
{
    int k,time_left;
    scanf("%d",&k);
    
    while(k--)
    {
        index=0;
        scanf("%d %d",&m,&n);
        time_vector=(int*)malloc(sizeof(int)*(m*n));
        prev=(int*)malloc(sizeof(int)*(m*n));
        
        for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&time_at[i][j]);    
        scanf("%d %d %d",&a,&b,&T);
        prev[0]=0;
        time_vector[0]=time_at[0][0];
        for(int i=1; i<m*n; i++)
        {
            prev[0]=0;
            time_vector[i]=-1;
        }   
            
        calcTimeVectorUsingDijkstra();
  
        time_left = T - time_vector[indexOf(a-1,b-1)];
        if(time_left>=0)
        {
                printf("YES\n%d\n",time_left);
                
        }
        else
        {
            printf("NO\n");
        }
                
    }
    system("pause");
    return 0;    
}
