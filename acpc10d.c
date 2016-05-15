#include<stdio.h>
#define MIN2(a, b) ((a <= b) ? a : b)
#define MIN3(a, b, c) ((c <= MIN2(a, b)) ? c : MIN2(a, b) ) 
#define MIN4(a, b, c, d) ((d <= MIN3(a, b, c)) ? d : MIN3(a, b, c) )
int grid[100000][3]={0},dp[100000][3]={0},rows,r,c,tc=1;
int main()
{
    while(1)
    {
        scanf("%d",&rows);
            if(rows==0)
            {
                return 0;
            }
            
        for(r=0;r<rows;++r)
        {
            scanf("%d %d %d",&grid[r][0],&grid[r][1],&grid[r][2]);
        }
        
        dp[0][0]=0;
        dp[0][1]=grid[0][1];
        dp[0][2]=grid[0][1]+grid[0][2];
        for(r=1;r<rows;++r)
        {
            for(c=0;c<3;++c)
            {
                switch(c)
                {
                    case 0:
                        if(r==1)
                        {
                            dp[r][c]=grid[r][c]+dp[r-1][c+1];
                            break;
                        }
                        dp[r][c]=grid[r][c]+MIN2(dp[r-1][c],dp[r-1][c+1]);
                        break;
                        
                    case 1:
                        if(r==1)
                        {
                            dp[r][c]=grid[r][c]+MIN3(dp[r][c-1],dp[r-1][c],dp[r-1][c+1]);
                            break;
                        }
                        dp[r][c]=grid[r][c]+MIN4(dp[r][c-1],dp[r-1][c-1],dp[r-1][c],dp[r-1][c+1]);
                        break;
                        
                    case 2:
                        dp[r][c]=grid[r][c]+MIN3(dp[r][c-1],dp[r-1][c-1],dp[r-1][c]);
                        break;
                        
                   // default:printf("LOL");break;
                }
            }
        }
       /* 
        printf("\n\n");
        for(r=0;r<rows;++r)
        {
            for(c=0;c<3;++c)
            {
                printf("%d  ",dp[r][c]);
            }
            printf("\n");
        }
        printf("\n\n");
        */
        printf("%d. %d\n",tc,dp[rows-1][1]);
        ++tc;
        
    }
    system("pause");
    return 0;
}

        
    
