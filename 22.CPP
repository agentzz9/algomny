#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct node
{
	int data;
	node *next; //self referencial structure
		    //a data type pointing to itself
};
class stack
{
	node *top;
	public:
		stack();   	//constructor
		void push();    //pushing value into the stack
		void pop();	//popping the value from the stack
		void show();	//displaying the values in the stack
		~stack();	//destructor
};
//initialize the element in the constructor
stack::stack()
{
	top=NULL;
}
//push the data into the stack
void stack::push()
{
	node *temp; 		//create a temporary node
	temp = new node; 	//allocate memory space
	cout<<"Enter data ";
	cin>>temp->data; 	//inputting the data
	temp->next=top;		//linking the data
	top=temp;		//shifting the pointer to the new top
	cout<<"Data has been pushed\n";
}
void stack::pop()
{
	if (top==NULL) 		//check if the stack is empty
	{
		cout<<"Stack is empty\n";
	}
	else
	{
		node *temp;	//creating a temporary node
		int tdata;	     //var to store the data
		tdata=top->data;     //storing the data
		temp=top;	     //storing the top node
		top=top->next;	     //shifting the pos to the next node
		delete temp;	     //deleting the prev data
		cout<<"Data popped "<<tdata<<endl;
	}
}
void stack::show()
{
	node *temp;
	temp=top;	//assigning the top node to temp node
	cout<<"The stack is \n";
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next; 	//move to the next node
	}
}
stack::~stack()
{
	node *temp;
	while(top!=NULL)
	{
		temp=top;
		top=top->next; 	//move to the next node
		delete temp;
	}
}
void main()
{
	clrscr();
	int ch=0;
	stack stobj;
	while (ch<4)
	{
		cout<<"1.Push\n";
		cout<<"2.Pop\n";
		cout<<"3.Show\n";
		cout<<"4.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:stobj.push();break;
			case 2:stobj.pop();break;
			case 3:stobj.show();break;
		}
	}
}
