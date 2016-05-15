#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

pair<int,int> a[500005];
int main()
{
    int i,n,k,tmp,leftptr,rightptr,i1,i2,ans=0,minn=999999,flag=0,l,r;
   
    scanf("%d%d",&n,&k);
    
    for(i=1;i<=n;i++)
    {
        scanf("%d",&tmp);
        
        a[i].first=tmp;
        a[i].second=i;
        
    }
    
    sort(a+1,a+n+1);
  
    leftptr=1;
    rightptr=n;
    while(leftptr<=n && rightptr>=1)
    {
        l=a[leftptr].first;
        r=a[rightptr].first;
        if(l+r==k && l!=r)
        {
            flag=1;
            
            i1=a[leftptr].second;
            i2=a[rightptr].second;
            
            if(i1<=n/2 && i2<=n/2)
            {
                ans=max(i1,i2);
            }
            else if(i1<=n/2 && i2>n/2)
            {
                ans=max(i1,n-i2+1);
            }
            else if(i1>n/2 && i2<=n/2)
            {
                ans=max(i2,n-i1+1);
            }
            else if(i1>n/2 && i2>n/2)
            {
                ans=max(n-i1+1,n-i2+1);
            }
            
            minn=min(minn,ans);
            
            leftptr++;
            //rightptr--;
            
            continue;
            
            
        }
        if(l+r < k)
        {
            leftptr++;
            continue;
        }
        if(l+r > k)
        {
            rightptr--;
            continue;
        }
        else//both equal l==r
        {
            leftptr++;
            //rightptr--;
            continue;
        }
    }
    
    if(flag==1)
        printf("%d",minn);
    else
        printf("-1");
    
    getchar();getchar();
    return 0;
    
    
    
}
