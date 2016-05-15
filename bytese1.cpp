#include<iostream>
#include<cstdio>
using namespace std;
int time_at[105][105],visited[105][105],m,n;
int a,b,T,time_elapsed,min_final_time;
int turn_row[4] = {-1, +0, +1, +0}; 
int turn_col[4] = {+0, +1, +0, -1};
void findByDfs(int row, int col)
{
 //printf(" (%d,%d) ",row,col);
        
    visited[row][col] = 1;
    time_elapsed += time_at[row][col];
    
  //  printf(" time_elapsed: %d\n",time_elapsed);
    
    if(time_elapsed > T)
    {
        time_elapsed -= time_at[row][col];
        visited[row][col] = 0;
        return;
        
    }
    if(row==a-1 && col==b-1)
    {
        if(time_elapsed <= min_final_time)
        {
            min_final_time = time_elapsed;
        }
        time_elapsed -= time_at[row][col];
        visited[row][col] = 0;
        return;
    }   
    
    for(int i=0; i<4; i++)
    {
        int new_row = row + turn_row[i];
        int new_col = col + turn_col[i];
        if(new_row>=0 && new_col>=0 && new_row<m && new_col<n && !visited[new_row][new_col])
        {
            findByDfs(new_row, new_col);
            visited[new_row][new_col] = 0;    
        } 
        /*if(new_row==a-1 && new_col==b-1 && !visited[new_row][new_col])
        {
            findByDfs(new_row, new_col);
            visited[new_row][new_col] = 0;
            break;   
        }
        
        else if(new_row>=0 && new_col>=0 && new_row<m && new_col<n && !visited[new_row][new_col])
        {
            findByDfs(new_row, new_col);
            visited[new_row][new_col] = 0;    
        } 
        */   
    }
    time_elapsed -= time_at[row][col];
    
}
int main()
{
    int k;
    scanf("%d",&k);
    
    while(k--)
    {
        
        scanf("%d %d",&m,&n);
        for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&time_at[i][j]);    
        scanf("%d %d %d",&a,&b,&T);
        
        time_elapsed = 0;
        min_final_time = 99999;
        for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = 0;
        
        
        findByDfs(0, 0);
      //  cout<<"min_final_time: "<<min_final_time<<endl;
        
        if(min_final_time == 99999)
            printf("NO\n");
        else
            printf("YES\n%d\n",T-min_final_time);    
        
       
    }
    
    system("pause");
    return 0;    
}
