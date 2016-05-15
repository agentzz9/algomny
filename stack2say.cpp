#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct node
{
    int info;
    node *link;
};
node *top=NULL;//(node*)malloc(sizeof(node));
//top=NULL;
void push(int item)
{
    if(top==NULL)
    {
        node *temp;
        temp=(node*)malloc(sizeof(node));
        
        temp->info=item;
        top=temp;
        top->link=NULL;
    }
    else
    {
        node *temp;
        temp=(node*)malloc(sizeof(node));
    
        temp->info=item;
        temp->link=top;
        top=temp;
    }
}
int pop()
{
    if(top==NULL)
    {
        cout<<"Underflow";
    }
    else
    {
        node *temp;
        temp=(node*)malloc(sizeof(node));
        int t;
        t=top->info;
        temp=top;
        top=top->link;
        free(temp);
        return t;
    }
}
void display()
{
    node* temp=(node*)malloc(sizeof(node));
    temp=top;
    while(temp!=NULL)
    {
        cout<<temp->info<<endl;
        temp=temp->link;
    }
}

int main()
{
    //node *top=(node*)malloc(sizeof(node));
    //top=NULL;
    /*int ch=0,x;
    while(ch<=3)
    {
        cout<<"1.pUSH\n2.pop\n3.display"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: push();break;
            case 2: x=pop();cout<<x<<"popped"<<endl;break;
            case 3: display();break;
        }
    }*/
    return 0;
}


    
    
    
    
   
