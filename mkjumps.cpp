#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int valid_board[15][15];
int visited[15][15],count, max_count;
void countByDfs(int row, int col)
{
    int turn_row[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
    int turn_col[8] = {-1 ,+1, -2, +2, -2, +2, -1, +1};
    int new_row,new_col;
    
    visited[row][col] = 1;    
    ::count++;
    if(::max_count < ::count)
        ::max_count = ::count;
     
    for(int i=0; i<8; i++)
    {
        new_row = row + turn_row[i];
        new_col = col + turn_col[i];
        
        if(new_row>=0 && new_col>=0 && new_row<10 && new_col<10 && valid_board[new_row][new_col] && !visited[new_row][new_col])
        {
            countByDfs(new_row, new_col);
            visited[new_row][new_col] = 0;
            ::count--;
        }    
    }        
}
int main()
{
    int nrows = 1,a,n,kase=0,init_row,init_col,sqs_notreachable,square_count;
    
    char sqstring[10]="" ;
    while(1)
    {
        kase++;
        square_count = 0;
        ::count = 0; ::max_count = 0;
        for(int i=0; i<15; i++)
        for(int j=0; j<15; j++)
            valid_board[i][j] = 0;
            
        scanf("%d",&nrows);
        if(!nrows) break;
        
        for(int i=0; i<nrows; i++)
        {
            scanf("%d %d",&a,&n);
            if(i==0)
            {
                init_row = 0;
                init_col = a;       
            }
            while(n--)
            {
                valid_board[i][a++] = 1;
                square_count++;
            }
        }
        
        countByDfs(init_row,init_col);
        
        sqs_notreachable = square_count - ::max_count;
        switch(sqs_notreachable)
        {
            case 1: strcpy(sqstring,"square"); break;
            default: strcpy(sqstring,"squares"); 
        }
        printf("Case %d, %d %s can not be reached.\n",kase,sqs_notreachable,sqstring);
        
    }
    system("pause");
    return 0;    
}
