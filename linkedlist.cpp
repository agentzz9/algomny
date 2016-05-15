#include<iostream.h>
#include<stdio.h>
using namespace std;
struct node
{
    int data;
    node *next;
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
    node *current,*beforecurrent;
    int count=1;
    temp->data=value;
    
    current=*head;
    if(position==1 || (*head==NULL && position>=0))
    {
        temp->next=current;
        *head=temp;
        return 1;    
    }    
    else
    {
        while(count<position && current!=NULL)
        {
            count++;
            beforecurrent=current;
            current=current->next;
            
        }
        if(current!=NULL)
        {
            
            beforecurrent->next=temp;
            temp->next=current;
            return 1;
            
        }
        else
        {
            beforecurrent->next=temp;
            temp->next=NULL;
            return 1;
        }
        
    }
        
}
int deletion(node **head,int position)
{
    node *temp=new node;
    temp->next=NULL;
    node *current,*beforecurrent;
    current=*head;
    int prevcount=1;
    
    if(*head==NULL)
    {
        return 1;    
    }
    if(position==1)
    {
        temp=current;
        *head=current->next;
        delete temp;        
    }
    else
    {
        while(prevcount<=position-1 && current!=NULL)
        {
            prevcount++;
            beforecurrent=current;
            current=current->next;
            
        }
        if(current==NULL)
        {
            return 1;   
        
        }
        else
        {
            temp=current;
            beforecurrent->next=current->next;
            delete temp;
            return 1;            
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
