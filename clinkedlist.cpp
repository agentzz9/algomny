#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
int traverse(node *head)
{
    node *temp=(node*)malloc(sizeof(node));
    int count=0;
    if(head==NULL)
    {
        return count;
    }
    else
    {
            temp=head;
            do
            {
                printf("%d ",temp->data);
                temp=temp->next;
                count++;
            
            }while(temp!=head);
        
             return count; 
        
    }
    
}
int insertbegin(node **head,int data)
{
    
    node *temp=(node*)malloc(sizeof(node));
    
    node *current;
 
    current=*head;
    
    temp->data=data;
    temp->next=temp;
    
    if(current==NULL)
    {
        *head=temp;
        return 1;        
    }
    else
    {
        if(current->next==current)
        {
            temp->next=current;
            current->next=temp;
            *head=temp;
            return 1;
        }
        else
        {
            temp->next=*head;
            
            while(current->next!=*head)
            {
                current=current->next;
            }
            current->next=temp;
            *head=temp;
            return 1;    
            
        }
    }
}
int insertend(node **head,int data)
{
    node *current;
    node *temp=(node*)malloc(sizeof(node));
    
    temp->data=data;
    temp->next=temp;
    current=*head;
    
    if(*head==NULL)
    {
        *head=temp;
        return 0;
    }
    else
    {
        while(current->next!=*head)
            current=current->next;
        temp->next=*head;
        current->next=temp;
        return 1;
            
    }
    
}
int deleteend(node **head) 
{
    node *temp,*p;
    temp=*head;
    node *current;
    current=*head;
    p=*head;
    
    if(*head==NULL)
    {
        return -1;
    }
    
    while(current->next!=*head)
    {
        temp=current;
        current=current->next;
    }
    //if(*head->next==*head)
    if(temp->next==*head)
    {
        *head=NULL;
        return 0;
    }
    temp->next=*head;
    free(current);
    return 0;
    
}
int deletebegin(node **head)
{
    node *temp=new node;
    node *p;
    temp=*head;
    
    if(*head==NULL)
    {
        return -1;
    }
    else
    {
        if(temp->next==*head)
        {
            *head=NULL;
            return 0;   
        }
        else
        {
            p=*head;
            while(temp->next!=*head)
            {
                temp=temp->next;
                    
            }   
           temp->next=p->next;
           // temp->next=*head->next;
            *head=p->next;
            free(p);
            return 0; 
        }
    }
}
int main()
{
    int ch,pos,n;
    //node *head=(node*)malloc(sizeof(node));
    node *head= new node;
    //head->next=head;
    head=NULL;
    
    do
    {
        printf("1.View");
        printf("2.insertbegin");
        printf("3.insertend");
        printf("4.deleteend");
        printf("5.deletebegin");
        printf("99.exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("count: %d,",traverse(head)); break;     //callbyval
            case 2: printf("entervalue: ");
                    scanf("%d",&n);
                    insertbegin(&head,n);
                    break;
            case 3: printf("entervalue: ");
                    scanf("%d",&n);
                    insertend(&head,n);
                    break;
            case 4: deleteend(&head);break;
            case 5: deletebegin(&head);break;
            default: break;
           
        }
    
    }while(ch!=99);    
    system("pause");
    return 0;   
}
