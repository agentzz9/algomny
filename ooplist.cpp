#include<iostream.h>
#include<conio.h>
class node
{
      int data;
      node* link;
      static node* start;
      public:
             void input()
             {
                    cin>>data;
             }
             void output()
             {
                    cout<<data<<"\t";
             }
             static void set_start(node* tstart)
             {
                    start=tstart;
             }  
             void set_link(node* tlink)
             {
                    link=tlink;
             }
             static node* ret_start()
             {
                    return node::start;
             }
             node* ret_link()
             {
                   return link;
             }
             int ret_data()
             {
                   return data;
             }
             ~node(){}
};
node* node::start=NULL;

void insert1()//at the beginning
{
    node* temp;
    temp=new node;
    if(node::ret_start()==NULL)
    {
        node::set_start(temp);
        cout<<"Enter data: ";
        temp->input();
        temp->set_link(NULL);
    }
    else
    {
        cout<<"Enter data: ";
        temp->input();
        temp->set_link(node::ret_start());
        node::set_start(temp);
    }
    
}
void insert2()//at the end
{
    node* temp;
    node* temp2;
    temp=new node;
    temp2=new node;
    
    if(node::ret_start()!=NULL)//if list nonempty
    {
        temp=node::ret_start();
        while(temp->ret_link()!=NULL)//find current rear/temp2
        {
            temp=temp->ret_link();
        }
        temp->set_link(temp2);        
        cout<<"Enter data:";
        temp2->input();
        temp2->set_link(NULL);
    }
    else
    {
        node::set_start(temp);
        cout<<"Enter data: ";
        temp->input();
        temp->set_link(NULL);
    }
    
}    
void insert3()//in the middle
{
    int e,val;
    node* temp;
    node* ptr;
    node* temp2;
    temp=new node;
    ptr=new node;
    temp2=new node;

    
    cout<<"\nEnter the item after which you want to enter new no.:";
    cin>>e;
    temp=node::ret_start();
    while(temp!=NULL)
    {
        if(e==temp->ret_data())
        {
            ptr=temp;
        }
        temp=temp->ret_link();
    }
    temp=ptr->ret_link();
    cout<<"\nEnter the new value:";
    temp2->input();
    ptr->set_link(temp2);
    temp2->set_link(temp);
}
    
void del1()
{   char c;
    node* temp;
    temp=new node;
    if(node::ret_start()==NULL)
    {   
        cout<<"Empty List"<<endl;
        c=getchar();
    }
    else
    {
        temp=node::ret_start();
        temp->output();cout<<" Deleted.";
        node::set_start(temp->ret_link());
    }
    delete temp;
}
void del2() //from the end/rear
{   char c;
    node* temp;
    node* ptr;
    temp=new node;
    
    if(node::ret_start()==NULL)
    {   
        cout<<"Empty List"<<endl;
        c=getchar();
        delete temp;
    }
    else
    {
        temp=node::ret_start();
        while(temp->ret_link()!=NULL)//find current last
        {
              temp=temp->ret_link();
              ptr=temp;      
        }
        temp->output(); cout<<" Deleted";
        temp=NULL;
        ptr->set_link(NULL);
        delete temp;
    }
    
}   
void del3()
{
    node* temp;
    node* ptemp;
    temp=new node;
    ptemp=new node;
   
    int val; 
    cout<<"\nInsert the value to delete from the list";
    cin>>val;
    temp=node::ret_start();
    if(temp->ret_data()==val)
    {
        del1();
        return;
    }
    else
    {
        ptemp=temp;
        temp=temp->ret_link();
        while(temp!=NULL)
        {
            if(temp->ret_data()==val)
            {
                break;
            }
            ptemp=temp;
            temp=temp->ret_link();
        }
        ptemp->set_link(ptemp->ret_link()->ret_link());
        delete temp;
        cout<<"\ndone";
    }
}
                  
void display()
{   char ch1;
    node* temp;
    temp=new node;
    temp=node::ret_start();
    while(temp!=NULL)
    {
        temp->output();
        temp=temp->ret_link();
    }
}            
int main()
{
    int ch=1;
    do
    {
        cout<<endl;
        cout<<"1. Insert node(beginning)"<<endl;
        cout<<"2. Delete node(beginning)"<<endl;
        cout<<"3. Insert node(end)"<<endl;
        cout<<"4. Delete node(end)"<<endl;
        cout<<"5. Insert node(middle)"<<endl;
        cout<<"6. Delete node(middle)"<<endl;
        cout<<"9. Display list"<<endl;       
        cin>>ch;
        switch(ch)
        {
                  case 1:insert1();break;
                  case 2:del1();break;
                  case 3:insert2();break;
                  case 4:del2();break;
                  case 5:insert3();break;
                  case 6:del3();break;
                  case 9:display();break;
                  default: cout<<"\nERROR\n";
        }
    }while(ch<10);
    system("pause");
    return 0;
}
