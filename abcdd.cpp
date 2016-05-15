#include<iostream>
#include<cstdio>
#include<utility> //for pair
#include<algorithm> //for sort
using namespace std;
pair <char,int> count[4];
int n,nn;

void solvebydfs(char c[2][100005],int index,char prev)
{
    //cout<<index<<endl;
    for(int i=0;i<4;i++)
    {
        if((index<nn) && (::count[i].second>0) && (prev!=::count[i].first) && (c[0][index]!=::count[i].first))
        {
            ::count[i].second--;
            c[1][index]=::count[i].first;
            solvebydfs(c,index+1,c[1][index]);
            ::count[i].second++;
            
        }     
    }    
}
bool myfunc(pair <char,int> x,pair <char,int> y)
{
    return (x.second < y.second);
        
}
int main()
{
    int i,j;
    char c[2][100005];
    
    scanf("%d",&n);
    for(i=0;i<4;i++)
    {
        ::count[i] = make_pair((char)('A'+i),n);
    }
    
    nn = 2*n;
    fflush(stdin);
    gets(c[0]);
    
     /*
    for(i=0;i<4;i++)
    {
        cout<<count[i].first<<" "<<count[i].second<<endl;    
    }cout<<endl;
    */
     
    for(i=0;i<nn;i++)
    {
        for(j=0;j<4;j++)
        {
            if(c[0][i] == ::count[j].first)
                ::count[j].second--;    
        }    
    }    
    /*
    for(i=0;i<4;i++)
    {
        cout<<count[i].first<<" "<<count[i].second<<endl;    
    }cout<<endl;
    
    sort(count,count+4,myfunc);
    
    for(i=0;i<4;i++)
    {
        cout<<count[i].first<<" "<<count[i].second<<endl;    
    }cout<<endl;
    */
    
    solvebydfs(c,0,'X');
        
    fflush(stdin);
    fflush(stdout);
    
    cout<<endl;
    for(i=0;i<4;i++)
    {
        cout<<::count[i].first<<" "<<::count[i].second<<endl;    
    }cout<<endl;
    
    puts(c[1]);
    
    system("pause");
    return 0;
}

