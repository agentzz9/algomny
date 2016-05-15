#include<cstdio>          //  A- a | aA | $
#include<cstdlib>         //  B- b | bB | $
                           //
                           //
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string global;
int p;
vector<string> productions[27];
vector<char> ans[27];
char first(char c)
{
    //cout<<endl<<c<<endl;
    if(c>='a'&&c<='z')
    {
        return c;
    }
    if(c>='A'&&c<='Z')
    {
        int j=((int)(c-'A'))+1;
        
         
           int l=productions[j].size();
            for(int i=0;i<l;i++)
            {
                    string x=productions[j][i];
                    global=x;
                    char ch=x[p];
                    //cout<<"here";
                    return first(ch);
                   
                    p=0;
             
            }
                      
    }
    if(c=='$')
    {
            p++;
            return first(global[p]);
    }
    if(c=='\0')
    {
            return '$';
    }

}
int main()
{
    int i,j,k,l,p,nt,t,v[27]={0},n,goon=0;
    string s;
 
    printf("\n Enter No. of  Non terminals ");
    scanf("%d",&nt);
    printf("\n Enter the productions:\n");
    
    i=1;
    while(i<=nt)
    {
            v[i]=1;
            printf("For %c(NonTerminal) , no. of productions? : ",(char)('A'+i-1));
            scanf("%d",&n);
            for(k=1;k<=n;k++)
            {
                    printf("%d:",k);
                    cin>>s;
                    productions[i].push_back(s);
                            
            }
           i++;
    }
   
    cout<<"\n\tTHE GRAMMAR IS:\n";
    for(int j=1;j<=nt;j++)
    {
            cout<<(char)('A'+j-1)<<"->";
            
            
            int l=productions[j].size();
            for(int i=0;i<l;i++)
            {
                    cout<<productions[j][i]<<" | ";
             
            }
            cout<<endl;
            
    }
    cout<<"----------------------------------------------------------";
    p=0;
    
    for(int j=1;j<=nt;j++)
    {
           // cout<<(char)('A'+j-1)<<"--"<<endl;
            
            int l=productions[j].size();
            for(int i=0;i<l;i++)
            {
                    string x=productions[j][i];
                    global=x;
                    char ch=x[p];
                    //cout<<"here";
                    ans[j].push_back(first(ch));
                    
                    p=0;
             
            }
            cout<<endl;
            
    }
    
    cout<<"__________ANSWER______________"<<endl;
    for(int j=1;j<=nt;j++)
    {
            cout<<(char)('A'+j-1)<<"->"<<endl;
            
            int l=productions[j].size();
            for(int i=0;i<l;i++)
            {
                    cout<<ans[j][i]<<endl;
             
            }
            cout<<endl;
            
    }
    
    fflush(stdin);printf("\n...");
    getchar();
    return 0;
}
