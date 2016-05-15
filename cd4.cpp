#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<char,vector<char> > m,output;
map<char,int> visited; //pushed;

void fistOf(char P)
{
    int i,j,start=1;
    int s = m[P].size();

    visited[P]=1;

    for(i=0;i<s;i++)
    {
        if(start==1)
        {
            if(m[P][i]>='a' && m[P][i]<='z' || m[P][i]<='$')
                output[P].push_back(m[P][i]);
            else
            if(m[P][i]>='A' && m[P][i]<='Z')
                if(visited[m[P][i]]==0)
                    fistOf(m[P][i]);

            start=0;
            //if(pushed[P]==0)
            {
                for(j=0;j<output[m[P][i]].size();j++)
                {
                    if(output[m[P][i]][j]=='$')
                        start=1;

                    output[P].push_back(output[m[P][i]][j]);
                }
                //pushed[P]=1;
            }

        }
        else
        {
            if(m[P][i]=='|')
                start=1;
        }
    }
}

int main()
{
    int i,j,k,p;

    char c[50],str[50];

    cout<<"\nEnter no. of production:";
        cin>>p;

    for(i=1;i<=p;i++)
    {
        cout<<"\nEnter left side for production "<<i<<": ";
            cin>>c[i];

        visited[c[i]]=0;
       // pushed[c[i]]=0;

        cout<<"\nEnter its right side:  ";
            cin>>str;
        for(j=0;str[j]!=0;j++)
        m[c[i]].push_back(str[j]);
    }

    for(i=1;i<=p;i++)
        if(visited[c[i]]==0)
            fistOf(c[i]);

    for(i=1;i<=p;i++)
    {
        cout<<"\n"<<c[i];
        for(j=0;j<output[c[i]].size();j++)
            cout<<"->"<<output[c[i]][j];
    }
    system("pause");
    return 0;
}

