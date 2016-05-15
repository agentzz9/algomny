#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include <algorithm>

using namespace std;

vector<int> vec[100][100];
vector<int> dfa[100][100];
vector< vector<int> > newstates;

int main()
{
    int n,i,j,k;

    cout<<"enter no. of states:\t";
           cin>>n;
    queue<vector<int> > Q;

    vector<int> v;
    v.push_back(1);
    Q.push(v);

    for(i=1;i<=n;i++)
       {
            int y;

            cout<<"For ("<<i<<",a)-> ";
            cin>>y;
            while(y)
            {
                vec[i][0].push_back(y);
                cin>>y;
            }

            if(i==1)
              	   Q.push(vec[i][0]);

            cout<<"For ("<<i<<",b)-> ";
            cin>>y;

            while(y)
            {
                vec[i][1].push_back(y);
                cin>>y;
            }

            if(i==1)
            {
                Q.push(vec[i][1]);
            }
       }

       k=0;

       while(!Q.empty())
       {
            vector<int> temp;
            temp = Q.front();
            Q.pop();

            int size = temp.size(),match=0;
            //Finding in newstates array

            for(i=0;i<newstates.size();i++)
            {
                int flag=0;

                if(size==newstates[i].size())
                {
                    for(j=0;j<newstates[i].size();j++)
                    {

                        if(temp[j]==newstates[i][j])
                        {
                            match=1;
                        }
                        else
                        {
                            match=0;
                            break;
                        }
                    }
                 }

                 if(match == 1)
                    break;
            }

            if( match==0 ) //its a newstate. make it's transition states.
            {
                newstates.push_back(temp);

                for(i=0;i<temp.size();i++)
                {
                    for(j=0;j<vec[temp[i]][0].size();j++)
                        dfa[k][0].push_back(vec[temp[i]][0][j]);

                    sort(dfa[k][0].begin(),dfa[k][0].end());
                    dfa[k][0].erase(unique(dfa[k][0].begin(),dfa[k][0].end()),dfa[k][0].end());  // removing duplicates.

                    for(j=0;j<vec[temp[i]][1].size();j++)
                        dfa[k][1].push_back(vec[temp[i]][1][j]);

                    sort(dfa[k][1].begin(),dfa[k][1].end());
                    dfa[k][1].erase(unique(dfa[k][1].begin(),dfa[k][1].end()),dfa[k][1].end());  // removing duplicates.
                }
                Q.push(dfa[k][0]);
                Q.push(dfa[k][1]);

                k++;
            }
       }

       cout<<"\nDFA STATES         a         b \n\n";

       for(i=0;i<newstates.size();i++)
       {
            cout<<"( ";
            for(j=0;j<newstates[i].size();j++)
                cout<<newstates[i][j]<<",";
            cout<<" )      ";

            for(j=0;j<2;j++)
            {
                cout<<"( " ;
                for(k=0;k<dfa[i][j].size();k++)
                    cout<<dfa[i][j][k]<<",";
                cout<<" )      ";
            }
            cout<<"\n";
       }
    system("pause");
    return 0;
}





