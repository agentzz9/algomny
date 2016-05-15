#include<iostream>
#include<cstdio>
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
    printf("\n");
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
int hasKnodes(node *hook,int k)
{
    node *current=new node;
    int count=1;
    
    
    current=hook;
    if(current->next==NULL)
        return 1;
        
    while(count<=k)
    {
        current=current->next;
        if(current==NULL)
            break;
        count++;
            
    }    
    if(count==k)
        return 0;
    else
        return -1;
    
           
}
node* reverse(node *hook,int k)
{
    int count=1;
    node *nextnode=new node;
    node *temp=new node;
    temp=NULL;
    
    while(hook)
    {
        
        nextnode=hook->next;
        hook->next=temp;
        
        temp=hook;
        hook=nextnode;
        count++;
        if(count==k)
            break;
    }
    return temp;
    
    
}
int Kreorder(node **head,int k)
{
    int count=0;
    if(*head==NULL)
        return 0;
    if((*head)->next==(*head))
        return 0;
        
    node *hook;
    hook=*head;
    
    while(1)
    {
        if(hasKnodes(hook,k))
        {
            hook=reverse(hook,k);
            //reverse first k nodes;
            
            while(count<=k)
            {
                hook=hook->next;
                count++;
            }
            //set k+1th as new hook;    
        }  
        else
            break; 
        
    }    
    return 0;
    
}


int main()
{
    int k;
    node *head1=new node;
    node *head2=new node;
    node *head3=new node;
    node *head4=new node;
    node *head5=new node;
    node *head6=new node;
    
    head1=NULL;
    head2=NULL;
    head3=NULL;
    head4=NULL;
    head5=NULL;
    head6=NULL;
    
    insert(&head2,1,11);
    
    insert(&head3,1,11);
    insert(&head3,2,22);
    
    insert(&head4,1,11);
    insert(&head4,2,22);
    insert(&head4,3,33);
    
    insert(&head5,1,11);
    insert(&head5,2,22);
    insert(&head5,3,33);
    insert(&head5,4,44);
    
    insert(&head6,1,11);
    insert(&head6,2,22);
    insert(&head6,3,33);
    insert(&head6,4,44);
    insert(&head6,5,55);
    
    printf("Lists:\n");
    printf("1:");traverse(head1);
    printf("2:");traverse(head2);
    printf("3:");traverse(head3);
    printf("4:");traverse(head4);
    printf("5:");traverse(head5);
    printf("6:");traverse(head6);
    printf("______________________\n");
    
    printf("Enter k:");scanf("%d",&k);
    
    
    printf("Lists Now:\n");
    printf("1:");Kreorder(&head1,k);traverse(head1);
    system("pause");
    printf("2:");Kreorder(&head2,k);traverse(head2);
    system("pause");
    printf("3:");traverse(head3);
    printf("4:");traverse(head4);
    printf("5:");traverse(head5);
    printf("6:");traverse(head6);
    
    
    
    
    
    
    
    
    
    
    
    system("pause");
    return 0;
}
