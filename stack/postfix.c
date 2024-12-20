#include <stdio.h>
#include <conio.h>
#include <string.h>

#define LEFT_PAREN -10
#define RIGHT_PAREN -20
#define OPERATOR -30
#define OPERAND -40

#define LEFT_PREC 0
#define ADD_PREC 1
#define SUB_PREC 1
#define MUL_PREC 2
#define DIV_PREC 2
#define MOD_PREC 3
#define POWER_PREC 3

#define SS 100
#define MAX 100

#define NONE -999
typedef struct
{
	char items[MAX];
	int top;
}Stack;

int isFull(Stack s)
{return (MAX-1==s.top?1:0);}

int isEmpty(Stack s)
{return (-1==s.top?1:0);}


void push(Stack *ps,char ch)
{
	if(isFull(*ps))
		printf("\nStack Overflow");
	else
		ps->items[++ps->top]=ch;
}


char pop(Stack *ps)
{
	if(isEmpty(*ps))
		return '\0';
	else	
		return ps->items[ps->top--];
}

char peek(Stack s)
{
	if(isEmpty(s))
		return '\0';
	else	
		return s.items[s.top];
}


int getType(char symbol)
{
		switch(symbol)
		{
				case '(' :
						return LEFT_PAREN;
				case ')' :
						return RIGHT_PAREN;
				case '+' :
				case '-':
				case '*':
				case '/':
				case '^':
				case '%':
						return OPERATOR;
				default:
						return OPERAND;
		}
}




int getPrec(char op)
{
	switch(op)
	{
		case '+':
			return ADD_PREC;
		case '-':
			return SUB_PREC;
		case '*':
			return MUL_PREC;
		case '/':
			return DIV_PREC;
		case '%':
			return MOD_PREC;
		case '^':
			return POWER_PREC;
		case '(':
			return LEFT_PREC;
		default:
			return NONE;
	}
}



void infixToPostFix(char infix[],char postFix[])
{
	char type,symbol,PoppedElement;
	int i=0,len=(strlen(infix)),prec=0,p=0;
	Stack stack;
	stack.top=-1;
	
	while(i<len)
	{
		symbol=infix[i];
		type=getType(infix[i]);
		
		switch(type)
		{
			case '(':
				push(&stack,symbol);
				break;
			case ')':
				while(PoppedElement=pop(&stack)!='(')
					postFix[p++]=PoppedElement;
				break;
			case OPERAND:
				postFix[p++]=symbol;
				break;
			case OPERATOR:
				prec = getPrec(symbol);
				
				while(!isEmpty(stack) && prec<=getPrec(peek(stack)))
					postFix[p++] = pop(&stack);
				push(&stack,symbol);
				break;
			
		}
		i++;
	}
	
	
	while(!isEmpty(stack))
		postFix[p++]=pop(&stack);	
	postFix[p]='\0';
}



int main(void)
{
	char infix[MAX],postFix[MAX];
	printf("\nEnter the infix expression : ");
	gets(infix);
	infixToPostFix(infix,postFix);
	printf("\nPostfix expression  : %s",postFix);
}
		
		