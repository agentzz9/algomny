#include<iostream> //check abcpathh instead.
#include<queue>
using namespace std;
struct node
{
    int x,y;
    char val;
    node(int tx,int ty,char tval)
    {
        x=tx;
        y=ty;
        val=tval;
    }    
};
queue<node> q;
int h,w,i,j,k,push,maxans,tans;
int nx,ny,turnx[8]={1,1,0,-1,-1,-1,0,1},turny[8]={0,1,1,1,0,-1,-1,-1};
char a[55][55]={NULL};
int bfs(int r,int c)
{
        int ans;
        char last;
        int visited[55][55]={0};
        
        while(!q.empty())
        {
            node obj=q.front();
            q.pop();
            visited[r][c]=1;
            last=obj.val;
                
            for(k=0;k<8;k++)
            {
                nx=obj.x+turnx[k];
                ny=obj.y+turny[k];
                if((nx<h)&&(ny<w)&&(nx>=0)&&(ny>=0)&&(visited[nx][ny]==0)&&(a[nx][ny]==obj.val+1))
                {
                    node newobj(nx,ny,a[nx][ny]);
                    q.push(newobj);
                    visited[nx][ny]=1;
                   
                }
               
            }
                
        }
        ans=((int)(last-'A'))+1;
        return ans;

}

int main()
{
    int t=0;
    while(1)
    {
        push=0;
        maxans=0;
        tans=0;
        scanf("%d %d",&h,&w);
        ++t; 
        if(h==0&&w==0)
            break;
        else
        {
            for(i=0;i<h;i++)
            {
                    scanf("%s",a[i]);      
            }
            for(i=0;i<h;i++)
            {
                for(j=0;j<w;j++)
                {
                    if(a[i][j]=='A')
                    {
                      
                        node obj(i,j,'A');
                        q.push(obj);
                        
                        push=1;
                        tans=bfs(i,j);
                        
                        if(tans>=maxans)
                            maxans=tans;
                        
                    }
                }
            }
            
            if(push==1)
                printf("Case %d: %d\n",t,maxans);
            else
                printf("Case %d: 0\n",t);
                
        }
        
    }
     
    return 0;
    
}
