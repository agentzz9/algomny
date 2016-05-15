#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int number(char a,char b){

    return ((int)(a-'0'))*10+(int)(b-'0');
    
}
int main(){

    char s[5005];
    
    while(1){
        
        long long dp[5005]={0},len=0;
        
        gets(s);
        
        len=strlen(s);
        if(s[0]=='0')
            break;
            
        dp[0]=1;
        
        for(int i=1;i<len;i++){
        
            if(number('0',s[i])>0)
                dp[i]=dp[i-1];
            
            if(number(s[i-1],s[i])>9&&number(s[i-1],s[i])<=26){
                if(i==1) {dp[i]++; continue;}
                else dp[i]+=dp[i-2];
            }
            
        }
        /*
        for(int i=0;i<len;i++)
            printf("%lld ",dp[i]);
        */
        printf("%lld\n",dp[len-1]);
        
    }
    
    system("pause");
    return 0;
    
}
