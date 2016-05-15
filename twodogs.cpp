#include<cstdio>
#include<iostream>
#include<vector.h>
#include<string>
#include<algorithm>
int n,k,tmp,arr[50005]={0},mark[50005]={0},index;
vector<int> t[2];
vector<int> pairs[2];
int main()
{
    scanf("%d %d",&n,&k);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        arr[i]=tmp;
        t[0].push_back(tmp);
        
    }
    
    sort(t[0].begin(),t[0].end());
    
    vector<int>::iterator x=t[0].begin();
    while(x!=t[0].end())
    {
        index=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==*x&&mark[i]!=1)
            {
                mark[i]=1;
                index=i;
                break;
            }
        }
        t[1].push_back(index);
        
        x++;
    }
    /*
    vector<int>::iterator y=t[0].begin();
    while(y!=t[0].end())
    {
        
        printf("%d ",*y);
        
        y++;
    }
    printf("\n");
    
    
    vector<int>::iterator z=t[1].begin();
    while(z!=t[1].end())
    {
        
        printf("%d ",*z);
        
        z++;
    }
    */
    
    vector<int>::iterator d1=t[0].begin();
    vector<int>::iterator d2=t[0].end();
    
    vector<int>::iterator d3=t[1].begin();
    vector<int>::iterator d4=t[1].end();
    
  
    while(d1!=t[0].end()||d2!=t[0].begin())
    {
        if((*d1)+(*d2)==k)
        {
            
            pairs[0].push_back(*d3);
            pairs[1].push_back(*d4);
            
        }
        if((*d1)+(*d2)<k)
        {
            d1++;
            d3++;
            continue;
        }
        
        if((*d1)+(*d2)>k)
        {
            d2--;
            d4--;
            continue;
        }
    }
    
    
    vector<int>::iterator y=pairs[0].begin();
    vector<int>::iterator z=pairs[1].begin();
    while(y!=pairs[0].end())
    {
        
        printf("(%d,%d) ",*y,*z);
        
        y++;
        z++;
    }
    
    
    
    
    getchar();getchar();
    return 0;
    
    
    
}
