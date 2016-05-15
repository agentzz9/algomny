#include<stdio.h>
#include<string.h>
#include<ctype.h>
char* toCamel(char cssPropertyName[55])
{
    int i,len,p=0;
    char ans[55];
    len=strlen(cssPropertyName);
        
    for(i=0;i<len;i++)
    {
        if(cssPropertyName[i]=='-')
        {
            i++;
            ans[p++]=toupper(cssPropertyName[i]);   
            continue;
        }
        ans[p++]=cssPropertyName[i];
    }
    ans[p]='\0';
    
    return &ans;
}
        
    
int main()
{
    char cssPropertyName[50]="top-border-width";
    
    char outputstring[55];
    
    outputstring=toCamel(cssPropertyName);
    
    printf("%s",outputstring);
    
    system("pause");
    return 0;
}
