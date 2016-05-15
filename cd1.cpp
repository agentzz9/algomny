#include<stdio.h>
#include<iostream>
#include<fstream>
#include<map>
#include<conio.h>
using namespace std;
map<string,int>m;
int main()
{
    freopen("x.txt","r",stdin);
    string s="";
    int lines=0,words=0;
    while(1)
    {
            //fflush(stdin);
            char c=getchar();
            if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            s+=c;
            else
            if(c==' ')
               {    if(s.length())
                   {   words++;
                          if(m[s])
                          m[s]++;
                          else
                          m[s]=1;
                   }
                   s="";
            }
            else
            if(c=='\n')
            {     lines++;
                  words++;
                  if(s.length())
                   {
                          if(m[s])
                          m[s]++;
                          else
                          m[s]=1;
                   }
                   s="";
            }
            else
            break;
    }
    cout<<"Lines: "<<lines<<endl;
    cout<<"Words: "<<words<<endl;
    map<string,int>:: iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
     printf("%s=%d times\n",it->first.c_str(),it->second);
    }
    getch();
    system("pause");
 
    return 0;
}
