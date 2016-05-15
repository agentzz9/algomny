#include<stdio.h>
int arr[5];
int top=-1;
void push(int tn)
{
	if(top==4)
	{
		printf("\nStack Overflow");
	}
	else
	{
		top++;
		arr[top]=tn;
	}
}
int pop()
{
	if(top==-1)
	{
		printf("\nStack Underflow");
	}
	else
	{
		int t;
		t=arr[top];
		top--;
		return t;
	}
}
void show()
{
	int i;
	if(top==-1)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("\n");
		for(i=top;i>=0;i--)
		{
			printf("%d ",arr[i]);
		}
	}
}
int  main()
{
	int ch,n,x='\0';
	ch=0;
	while(ch<4)
	{
		printf("\n1.push\n2.pop\n3.show\n4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter no: ");scanf("%d",&n);push(n);
			        break;
			case 2:x=pop();if(x!='\0'){printf("\n%d popped",x);} break;
			case 3:show();break;
			default: printf("\nerror\n");break;
		}
	}
	return 0;
}
