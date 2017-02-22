#include<stdio.h>

#define max 40
void push();
void pop();
void display();
int menu();
int stack[max], top=0;

void main()
{
	int ch;
	
	do{
		ch=menu();
		switch(ch)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4:	exit(-1);
			default: printf("\n Enter a valid choice \n ");
		}
	}while(1);
}

int menu()
{
	int ch;
	printf("\n === Stack using C ==\n");
	printf("\n1.push\n2.pop\n3.display\n4.exit");
	printf("\n Enter your choice\n");
	scanf("%d",&ch);
	return ch; 
}

void push()
{
	if(top == max)
		printf("\n Overflow");
	else 
	{
		int element;
		printf("Enter an element\n");
		scanf("%d",&element);
		printf("\n Element (%d) has been pushed to stack at %d pos",element,top);
		stack[top++] = element;
	}
}

void pop()
{
 	if(top == -1)
		printf("\n Underflow");
	else 
	{
		top--;
		printf("\n Element (%d) has been popped out!!",element);
	}
}

void display()
{
	if(top==0)
		printf("\n Stack is empty ");
	else 
	{
		int i;
		for(i=0;i<max;i++)
			printf("%d",stack[i]);
	}
}


