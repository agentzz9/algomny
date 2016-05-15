#include<iostream.h>
using namespace std;
int methodElly(char name[55])
{
    int p1,p2;
    int len,ans;
    len=strlen(name);
    ans=len;
    if(len==1)
        return 1;
    p1=0;
    p2=1;
    while(p1<len)
    {
        if(name[p1]=='a'||name[p1]=='e'||name[p1]=='i'||name[p1]=='o'||name[p1]=='u'||name[p1]=='y')
        {
            if(name[p2]=='a'||name[p2]=='e'||name[p2]=='i'||name[p2]=='o'||name[p2]=='u'||name[p2]=='y')
            {
                p1++;p2++;
                ans--;
                continue;
            }
            else
            {
                p1++;p2++;
                continue;
            }
        }
        else
        {
            p1++;p2++;continue;
        }
    }
    return ans;
}
        
        

int main()
{
    
