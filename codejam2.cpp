#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
//void shiftaction(grid
int main()
{ 
    int T,N;
    string DIR;
    int t=1,r,c,k,grid[25][25]={0},p1,p2;
    scanf("%d",&T);
    while(t<=T)
    {
        //scanf("%d %d",&N,&DIR);
        cin>>N>>DIR;
        for(r=0;r<N;r++)
        {
            for(c=0;c<N;c++)
            {
                scanf("%d",&grid[r][c]);    
            }    
        }
        if(DIR=="right")
        {
            for(r=0;r<N;r++)
            {
                p1=N-1;p2=p1-1;
                while(p1>0)
                {
                    while(1)
                    {
                        p2--;
                        if(grid[r][p2]==0)
                            continue;
                        if(grid[r][p2]==grid[r][p1])
                        {
                            
                            grid[r][p1]*=2;
                            grid[r][p2]=0;
                            p1=p2-2;
                            continue;    
                        }
                                    
                    }
                }
                shiftaction(grid[r]);
                
            }   
        }
            
        
        
        
        
        
        t++;    
    }
    system("pause");
    return 0;    
}
