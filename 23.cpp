#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct node
{
	int data;
	node *next; //self referencial structure
		    //a data type pointing to itself
};
class queue
{
	node *front, *rear;
	public:
		queue();   	//constructor
		void qinsert();    //inserting in the queue
		void qdelete();	   //deleting from the queue
		void qshow();	   //displaying the values in the queue
		~queue();	   //destructor
};
//member function to initialize the elements
queue::queue()
{
	front=NULL;
	rear=NULL;
}
//member function to insert the data into the queue
void queue::qinsert()
{
	node *temp;
	temp=new node;		//creates a new node
	cout<<"Enter data to be inserted ";
	cin>>temp->data;
	temp->next=NULL;
	if (front==NULL) 	//queue was empty
	{
		front=rear=temp;
	}
	else			//values were present
	{
		rear->next=temp;  //attach the value at the end
		rear=temp;	  //shift the rear position
	}
}
//member function to delete the data from the queue
void queue::qdelete()
{
	if (front==NULL)
	{
		cout<<"Queue is empty\n";
	}
	else
	{
		node *temp;
		int tdata;
		temp=front;
		tdata=front->data; //storing the data to temp var
		front=front->next; //shifting the front pointer to next node
		delete temp;
		//important
		if (front==NULL)  //if no values are left rear too has to change
		{
			rear=NULL;
		}
		cout<<"Data deleted is "<<tdata<<endl;
	}
}
//member function to show the queue
void queue::qshow()
{
	node *temp;
	temp=front;	//assigning the front node to temp node
	cout<<"Queue is ";
	while (temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
//member function to release the memory space
queue::~queue()
{
	node *temp;
	while (front!=NULL)
	{
		temp=front;
		front=front->next;
		delete temp;
	}
}
void main()
{
	clrscr();
	int ch=0;
	queue qobj;
	while (ch<4)
	{
		cout<<endl;
		cout<<"1.Insert\n";
		cout<<"2.Delete\n";
		cout<<"3.Show\n";
		cout<<"4.Exit\n";
		cout<<"Enter choice ";
		cin>>ch;
		switch(ch)
		{
			case 1:qobj.qinsert(); break;
			case 2:qobj.qdelete(); break;
			case 3:qobj.qshow();
		}
	}
}
