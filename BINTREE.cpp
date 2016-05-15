#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int  main()
{
    int N,i,j,big,small,smallcount,bigcount,commonancestor,ans,smallbackup;
    
    scanf("%d",&N);
    while(N>0)
    {
        ans=-1;
      /*  for(i=0;i<=999999999;i++)
        {
            visited[i]=0;
        }
        */
        
        map<int,int> visited;
     // bool visited[1000000000];
      //  cout<<"\ndone\n";
        scanf("%d %d",&i,&j);
        
        small=(i<=j)?i:j;
        if(i==small)
            big=j;
            else
                big=i;
        smallbackup=small;
        smallcount=0;
        bigcount=0;
        //visited[small]=1;    
        visited[small]=11;
        while(1)
        {
            /*
            if(small%2!=0)
            {
                small--;
            }*/
            if(small==1)
                break;
            small=small/2;
            visited[small]=11;
            smallcount++;
            
        }
     //   cout<<"small count="<<smallcount<<endl;
        while(1)
        {
              if(visited[big]==1)
              {
                commonancestor=big;
                break;
              }
              big=big/2;
              bigcount++;  
               // cout<<"here\n?";
        }
       // cout<<"big count="<<bigcount<<endl;
      //  cout<<"common ancestor="<<commonancestor<<endl;
        smallcount=0;
        small=smallbackup;
        while(1)
        {
            /*
            if(small%2!=0)
            {
                small--;
            }*/
            if(small==commonancestor)
                break;
            small=small/2;
            smallcount++;
            
        }
      //  cout<<"smallcount2 bigcount2 ans="<<smallcount<<" "<<bigcount<<endl;
        ans=bigcount+smallcount;
        
        
        printf("%d\n",ans);
        
        
        N--;    
    }
  
    
   
    system("pause");    
    return 0;
}
