#include<iostream>
#include<cstdio>
#define min2(a,b) (a<b?a:b)
using namespace std;
int main(){
    
    int t,r,c,R,C,i,j;
    scanf("%d",&t);
    while(t--){
        
        int s[505][505]={0},dp[505][505]={0};
        
        scanf("%d %d",&R,&C);
        
        for(int i=0; i<R; i++)
        for(int j=0; j<C; j++){
        
            scanf("%d",&s[i][j]);
        }
        
        for(j=C-1-1;j>=0;j--){
            
            dp[R-1][j]=dp[R-1][j+1]-s[R-1][j];
            if(dp[R-1][j]<0) dp[R-1][j]=0;
        
        }
        for(i=R-1-1;i>=0;i--){
            
            dp[i][C-1]=dp[i+1][C-1]-s[i][C-1];
            if(dp[i][C-1]<0) dp[i][C-1]=0;
        
        }
        
        for(i=R-1-1;i>=0;i--)
        for(j=C-1-1;j>=0;j--){
        
            dp[i][j]=min2(dp[i][j+1],dp[i+1][j])-s[i][j];
            
            if(dp[i][j]<0) dp[i][j]=0;
            
            
        }
        
        /*
        for(int i=0; i<R; i++){
            
            for(int j=0; j<C; j++){
            
                printf("%d ",dp[i][j]);
            
            }printf("\n");
        }
        
        */
        printf("%d\n",dp[0][0]+1);
        
        
    }
    
    system("pause");
    return 0;
    
}
