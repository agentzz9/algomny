#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoxy(int x,int y)
{
    CursorPosition.X=x;
    CursorPosition.Y=y;
    SetConsoleCursorPosition(console,CursorPosition);
}
void wait(long long time)
{
    long long i,j,k;
    for(i=0;i<=time;i++);
        
}
int main(int argc, char *argv[])
{
    int u=0,v=0,s=0,t=0,a=0,f=0;
    long long tf=390000010;
    char ch='\0';
    cout<<"Enter s:";
    cin>>s;
    cout<<"Enter u(pos/sec):";
    cin>>u;
    cout<<"Enter t units:";
    cin>>t;
    //stationary,just position,s
    if(u==0&&t==0)
    {
        while(1)
        {
            gotoxy((s+=0)%80,10);
            printf("*");
            wait(tf);//almost 1 sec... :P
            system("CLS");
        }
    }
    //has initial velocity,u
    if(u!=0&&t==0)
    {
        
        tf=tf/u;
        while(1)
        {
            gotoxy((s+=1)%80,10);
            printf("*");
            wait(tf);//almost 1 sec... :P
            system("CLS");
        }
    }
    if(u!=0&&t!=0)
    {
        tf=tf/u;
        while(1)
        {
            gotoxy((s+=1)%80,10);
            printf("*");
            wait(tf);//almost 1 sec... :P
            
            
            system("CLS");
        }
    }
        
        
    system("PAUSE");
    return EXIT_SUCCESS;
}
