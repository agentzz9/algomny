#include<iostream.h>
#include<conio.h>
#include<process.h>
int push(int,int&,int []);
int pop(int [],int&);
void display(int [],int);
void main()
{
     clrscr();
     int stack[5];
     int top=-1,item,x;
     char ch='y';
     while(ch=='y'||ch=='Y')
     {
      cout<<"enter item for insertion";
      cin>>item;
      x=push(item,top,stack);
      if(x==-1)
      {
       cout<<"overflow";
       break;
      }
       cout<<"stack now is:"<<endl;
                   display(stack,top);
                         cout<<"want to enter more elements";
                  cin>>ch;
      }
cout<<"now deletion begins"<<endl;
ch='y';
while(ch=='y'||ch=='Y')
{
x=pop(stack,top);
if(x==-1)
{
cout<<"underflow";
break;
}
else
{
cout<<"element deleted is:"<<x<<endl;
cout<<"stack now is:"<<endl;
display(stack,top);
}
cout<<"want to delete more elements";
cin>>ch;
}
getch();
}
int push(int item,int &top,int stack[])
{
if(top==4)
return -1;
else
{
top++;
stack[top]=item;
}
return 0;
}
int pop(int stack[],int &top)
{
int x;
if(top==-1)
return -1;
else
{
x=stack[top];
top--;
}
return x;

}

void display(int stack[],int top)
{
for(int i=top;i>=0;i--)
{
cout<<stack[i]<<endl;
}
}
