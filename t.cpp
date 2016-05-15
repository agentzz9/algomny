#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
    int data;
    node *next;    
};
int main()
{
        node *head=new node;
        head->data=55;
        head->next=NULL;
        
        printf("data, next=(%d,%d)",head->data,head->next->next);
        
        system("pause");
        return 0;
}
