#include<stdio.h>
int main()
{
    char a[2][100005],t;
    int i,j,k,n,len;
    scanf("%d",&n);
    
    scanf("%s",a[0]);
    
    for(len=0;a[0][len]!='\0';len++);
    
    for(i=0;i<len;i+=2)
    {
        if((a[0][i]=='A'&&a[0][i+1]=='B')||(a[0][i]=='B'&&a[0][i+1]=='A'))
        {
            a[1][i]='C'; a[1][i+1]='D';
            continue;
        }
        if((a[0][i]=='B'&&a[0][i+1]=='C')||(a[0][i]=='C'&&a[0][i+1]=='B'))
        {
            a[1][i]='A'; a[1][i+1]='D';
            continue;
        }
        if((a[0][i]=='C'&&a[0][i+1]=='D')||(a[0][i]=='D'&&a[0][i+1]=='C'))
        {
            a[1][i]='A'; a[1][i+1]='B';
            continue;
        }
        if((a[0][i]=='A'&&a[0][i+1]=='C')||(a[0][i]=='C'&&a[0][i+1]=='A'))
        {
            a[1][i]='B'; a[1][i+1]='D';
            continue;
        }
        if((a[0][i]=='A'&&a[0][i+1]=='D')||(a[0][i]=='D'&&a[0][i+1]=='A'))
        {
            a[1][i]='C'; a[1][i+1]='B';
            continue;
        }
        if((a[0][i]=='B'&&a[0][i+1]=='D')||(a[0][i]=='D'&&a[0][i+1]=='B'))
        {
            a[1][i]='A'; a[1][i+1]='C';
            continue;
        }
    }
    a[1][i]='\0';
    
    for(i=1;i<len-2;i+=2)
    {
        if(a[1][i]==a[1][i+1])
        {
            t=a[1][i+1];
            a[1][i+1]=a[1][i+2];
            a[1][i+2]=t;
        }
    }
        
    
    printf("%s",a[1]);
    
    
    system("pause");
    return 0;
}

