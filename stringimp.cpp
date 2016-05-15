#include<iostream>
using namespace std;
int strlent(char *str)
{
    char *p=str;
    int count=0;
    
    while(*p!='\0')
    {
        count++;
        p++;
    }    
 
    return count;
    
}
char* reversestring(char *str)
{
        int i,len;
        len=strlent(str);
        int limit;
        char t;
        if(len%2==0)
            limit=len/2-1;
            else
            limit=len/2;
    
        for(i=0;i<=limit;i++)
        {
            t=str[i];
            str[i]=str[len-i-1];
            str[len-i-1]=t;    
        }
        return str;
}

char* reversestringforeachword(char *str)
{    
    char *p,*p1,*p2;
    
    p=str;
    p1=NULL;
    p2=NULL;
    
    while(1)
    {
            if(*p==' ')
            {
                p++;
                continue;
                
            }
            if(*p=='\0')
                break;
        
            p1=p;
            p2=p1;
            while((*p2)!=' ' && (*p2)!='\0')
            {
                p2++;
                    
            }p2--;
            
            p=p2+1;
            
            while(p1<=p2)
            {
                char t;
                t=*(p1);
                *(p1)=*(p2);
                *(p2)=t;    
                
                p1++;
                p2--;
            }
      }
    return str;
    
}
char* removespaces(char* str)
{   
    char *p=str;
    char *buff=(char*)malloc(100*sizeof(char));
    char *s;
    s=buff;
    
    while(*(p)!='\0')
    {
        if(*(p)==' ' && *(p+1)==' ')
        {
            p++;continue;    
        }
        else
        {
            *buff=*p;
            buff++;
            p++;    
        }
    }
    *(buff)='\0';
    
  //  str=s;
    return s;
}
int main()
{
    
    char *ans=(char*)malloc(100*sizeof(char));
    char *str=(char*)malloc(100*sizeof(char));
    
    gets(str);
    cout<<str<<endl;
    reversestring(str);
    reversestringforeachword(str);
    //removespaces(str);   str doenst change
    str=removespaces(str);
    
    puts(str);
    
    system("pause");
    return 0;    
}
