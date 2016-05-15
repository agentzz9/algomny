#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string takeXOR(string s1,string s2)
{
    string s;
    int i=0;
    for(i=0;i<7;i++) 
    {
        if(s1[i]=='1'&&s2[i]=='1')    
        {
            s[i]='0';    
            continue;
        }
        if(s1[i]=='0'&&s2[i]=='0')
        {
            s[i]='0';    
            continue;
        }
        if(s1[i]=='1'&&s2[i]=='0')
        {
            s[i]='1';    
            continue;
        }
        if(s1[i]=='0'&&s2[i]=='1')
        {
            s[i]='1';    
            continue;
        }
    }   
    return s;
}
int main()
{
    
    
    int t=1,T,N,states[105];
    string str[7];
    string ninetozero3times[30]=
    {
        "1111011",      //9
        "1111111",
        "1110000",
        "1011111",
        "1011011",
        "0110011",
        "1111001",
        "1101101",
        "0110000",
        "1111110",
        "1111011",      //9
        "1111111",
        "1110000",
        "1011111",
        "1011011",
        "0110011",
        "1111001",
        "1101101",
        "0110000",
        "1111110",
        "1111011",      //9
        "1111111",
        "1110000",
        "1011111",
        "1011011",
        "0110011",
        "1111001",
        "1101101",
        "0110000",
        "1111110"                  //0
    };
    
    int i,j,k;
    scanf("%d",&T);
    while(t<=T)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
           cin>>str[i];   
           cout<<str[i];  
        }
        
        t++;    
    }
    system("pause");
    return 0;    
}
