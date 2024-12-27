#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>

#define MAX 10
#define NEG_INF -32768

typedef struct
{
	int items[MAX];
	int top;
}Stack;

int isFull(Stack s)
{return (MAX-1==s.top?1:0);}

int isEmpty(Stack s)
{return (-1==s.top?1:0);}


int push(Stack *ps,int x)
{
	if(isFull(*ps))
		return 0;
	else
	{
		ps->items[++ps->top]=x;
		return 1;
	}
}


int pop(Stack *ps)
{
	/*if(isEmpty(*ps))
		return NEG_INF;
	else
		return ps->items[ps->top--];
	*/
	return (isEmpty(*ps)?NEG_INF:ps->items[ps->top--]);
}


int peek(Stack s)
{
       /*if(isEmpty(s))
		return NEG_INF;
	else
		return s.items[s.top];
	*/
       return (isEmpty(s)?NEG_INF:s.items[s.top]);
}


void show(Stack s)
{
	int i;
	if(isEmpty(s))
	{
		printf("\nStack is empty nothing to show");
		return;
	}
	else
	{
		printf("\nStack contains : ");
		for(i=s.top;i>=0;i--)
			printf("%d ",s.items[i]);
	}
}



int main(void)
{
	Stack stack;
	stack.top=-1;
	int i,res,choice;
	
	//clrscr();
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Show\n5.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 :
				printf("\nEnter element to push : ");
				scanf("%d",&res);
				/*if(push(&stack,res))
					printf("\nElement Pushed ");
				else
					printf("\nElement can't be pushed ");
				*/
				(push(&stack,res)?printf("\nElement Inserted"):printf("\nStack Overflow "));
				break;
			case 2 :
				res=pop(&stack);
				(res==NEG_INF?printf("\nStack underflow nothing to pop"):printf("\nPopped Element  = %d",res));
				break;
			case 3 :
				res=peek(stack);
				(res==NEG_INF?printf("\nStack underflow nothing to peek"):printf("\nPeeked Element = %d",res));
				break;
			case 4 :
				show(stack);
				break;
			case 5 :
				exit(1);
				break;
			default :
				printf("\nOOPS wrong choice try again");


		}
	}
}