#include<iostream.h>
#include<stdio.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
int traverse(node *head)
{
    node *current=head;
    int count=0;
    
    while(current!=NULL)
    {
        printf("%d ",current->data);
        count++;
        current=current->next;
      
    }
    return count;
    
}    
int insert(node **head,int position,int value)
{
    node *temp=new node;
    node *p,*beforecurrent,*current;
    int count=0;
    
    temp->data=value;
    
    if(*head==NULL)
    {   
        temp->next=NULL;
        temp->prev=NULL;
        *head=temp;
        return 0;
    }
    else
    {
        if(position==1)
        {
            temp->next=*head;
            (*head)->prev=temp;
            temp->prev=NULL;
            *head=temp;
            
            return 0;
        }
        else
        {
            current=*head;
        
            while(count<=position-1 && current!=NULL)
            {
                count++;
                beforecurrent=current;
                current=current->next;    
            }
            if(current==NULL)
            {
                   beforecurrent->next=temp;
                   temp->prev=beforecurrent;
                   temp->next=NULL;
                   return 0;
            }
            else
            {
                temp->next=current;
                current->prev=temp;
                beforecurrent->next=temp;
                temp->prev=beforecurrent;
                
                return 0;
            }
            
        }
        
    }
    
}
int deletion(node **head,int position)
{
    node *temp=new node,*b;
    int count=1;
    temp=*head;
    if(*head==NULL)
    {
        return -1;    
    }
    if(position==1)
    {
      
        *head=(*head)->next;
        if(*head!=NULL)
            (*head)->prev=NULL;
        delete temp;
        return 0;
    }
    else
    {
        
        while(count<=position-1 && temp->next!=NULL)
        {
            count++;
            
            temp=temp->next;
            
        }
        if(temp->next==NULL)
        {
            node *t2=temp->prev;
            if(t2!=NULL)  
                t2->next=NULL;
             else
             {
                *head=NULL;   
                return 0;
            }
                                                                    
            delete temp;
            return 0;
        }
        else
        {
            node *t2=temp->prev;
            t2->next=temp->next;
            temp->next->prev=t2;
            delete temp;
            return 0;
            
        }
        
    }
    
}
int removelist(node **head)
{
    if(*head==NULL)
    {
        return 1;
    }
    else
    {
        node *temp;
        node *current;
        
        current=*head;
        while(current)
        {
            temp=current;
            current=current->next;
            delete temp;
            
        }
        *head=NULL;
    }
           
    
}
int main()
{
    
    int ch;
   
    node *head=new node;
    head=NULL;
   
   
    int pos;
    int n;
    
    do
    {
        printf("1.View");
        printf("2.insert");
        printf("3.delete");
        printf("4.remove list");
        printf("99.exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("count: %d ",traverse(head)); break;     //callbyval
            case 2: printf("Enter where to insert: ");
                    scanf("%d",&pos);
                    printf("Enter value :");
                    scanf("%d",&n);
                    insert(&head,pos,n);    //by ref
                    break;
            case 3: printf("Enter where to delete: ");
                    scanf("%d",&pos);
                    deletion(&head,pos);//byref
                    break;
            case 4: removelist(&head);break;//byref
                
            default: break;
           
        }
    
    }while(ch!=99);    
        system("pause");
}
