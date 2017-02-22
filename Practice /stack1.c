#define MAX 4
#include<stdio.h>

int stack[MAX];
int top;

void push(int element)
{
	char a;
	if(top == MAX-1)
	{
		printf("Stack is full");
		return;
	}
	do
	{
		printf("\n Enter the element to be inserted:");
		scanf("%d",&element);
		stack[++top]=element;
		printf(" Do you want to continue inserting press y");
		a = getchar();
	}
	while(a=='y');
}

int pop()
{
	int t;
	if(top == -1)
	{
		printf("Stack empty");		
		return -1;
	}
	t = stack[top];
	top = top-1;
	return t;
}

void show()
{
	int i;
	printf("\n The stack elements are: ");
	for(i=0;i<=top;i++)
	{
		printf("%d\t",stack[i]);
	}
}

int main()
{
	char ch, a='y';
	int choice, element;
	top =-1;
	printf("====STACK USING C =====\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");

	do
	{
		printf("Enter your choice for the operation\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			{
				push(element);
				show();
				break;
			}
			case 2:
			{	
				element = pop();
				printf(" The element deleted is = %d\t ", element);
				show();
				break;
			}
			case 3:
			{
				show();
				break;
			}
			default: printf("You entered wrong choice ");
			break;
		}
		printf(" \n Do you want to continue press (y/n)");
		ch = getchar();
	}
while(ch=='y' || ch=='Y');
getchar();
}
