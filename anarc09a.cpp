#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
int checkParenthesis(char s[2005])
{
    stack<char> Stk;
    int no_of_wrong_opens = 0;

    for(int index=0; s[index]!='\0'; index++)
    {
        if(s[index]=='{')
        {
            Stk.push(s[index]);    
        }
        else if(s[index]=='}')
        {
            if(!Stk.empty())
            {
                Stk.pop();    
            }
            else
            {
                no_of_wrong_opens++;
                Stk.push('{');    
            }
                
        }
            
    } 
    return ( (no_of_wrong_opens) + (Stk.size()/2) );
        
        

}
int main()
{
    int k=1,K,ans;
    char s[2005];    
    
    while(1)
    {
        scanf("%s",s);
      
        if(s[0]=='-')
        {
            break;        
        }
        else
        {
            printf("%d. %d\n",k++,checkParenthesis(s));    
        }
    }
    
    system("pause");
    return 0;    
}
