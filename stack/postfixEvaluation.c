#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define NONE -999



typedef struct
{
    int items[MAX];
    int top;

}Stack;

int isFull(Stack s)
{return s.top==MAX-1;}

int isEmpty(Stack s)
{return s.top==-1;}
int isnum(char input)
{
    switch(input)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
                return 1;
                break;
        default :
            return 0;

    }
}
void push(Stack *ps, int element)
{
    if(isFull(*ps))
    {
            printf("\nStack overflown");
            return;
    }
    else
        ps->items[++ps->top]=element;

}

int pop(Stack *ps)
{
        if(isEmpty(*ps))
        {
            printf("\nStack underflow");
            return NONE;
        }
        else    
            return ps->items[ps->top--];
}

int evalPostFix(char input[])
{
    Stack stack;
    stack.top=-1;
    int len,i,num1,num2,num;

    len=strlen(input);


    for(i=0;i<len;i++)
    {
        if(input[i]==' ')
            continue;
        else if(isnum(input[i]))
        {
            num=0;
            while(isnum(input[i]))
            {
                num = num*10 + (input[i]-'0');
                i++;
            }
            push(&stack,num);
            i--; //for compusating the increment of i's values done in the while loop
        }
        else
        {
            num2=pop(&stack);
            num1=pop(&stack);

            switch(input[i])
            {
                case '+':
                        push(&stack,num1+num2);
                        break;
                case '-':
                        push(&stack,num1-num2);
                        break;
                case '*':
                        push(&stack,num1*num2);
                        break;
                case '/':
                        if(num2!=0)
                        {
                            push(&stack,num1+num2);
                            break;
                        }
                        else
                            exit(1);
                default:
                    printf("\nIllegal argument");
                    exit(1);

                
            }
        }

    }
    return pop(&stack);

}

int main(void)
{
    char input[MAX];
    int result;
    printf("\nEnter the Postfix expression you want to evaluate: ");
    scanf("%[^\n]s",input);
    result = evalPostFix(input);

    printf("\nThe result is : %d",result);

}