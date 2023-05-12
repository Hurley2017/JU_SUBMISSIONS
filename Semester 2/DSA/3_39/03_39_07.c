#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#define max 90
typedef struct
{
    int *data;
    int top, size;
} Stack;
void display(Stack *s);
void init(Stack *s, int size);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int isOperator(char c);
int Precedence(char c);
int isEmpty(Stack s);
int evaluation(char *postfix);
int whichop(char ch)
{
    if(ch == '+')
        return 1;
    if(ch == '-')
        return 2;
    if(ch == '/')
        return 3;
    if(ch == '*')
        return 4;
}
int main()
{
    char *postfix = (char*)malloc(max*sizeof(char));
    printf("Enter the postfix expression : ");
    fgets(postfix, max, stdin);
    printf("Evaluated : %d\n", evaluation(postfix));
    return 0;
}
int evaluation(char *postfix)
{
    printf("%s\n", postfix);
    int counter = 0;
    Stack s;
    init(&s, max);
    while(*(postfix+counter) != '\0')
    {
        display(&s);
        if(isOperator(*(postfix + counter)))
        {
            switch (whichop(*(postfix+counter)))
            {
                case 1: 
                    push(&s, (pop(&s)+pop(&s)));
                    break;
                case 2:
                    push(&s, (pop(&s)-pop(&s)));
                    break;
                case 3:
                    push(&s, (pop(&s)/pop(&s)));
                    break;
                case 4:
                    push(&s, (pop(&s)+pop(&s)));
                    break;
            }
        }
        else
        {
            push(&s, *(postfix+counter)-48);
        }
        counter++;
    }
    printf("%d", pop(&s));
    return pop(&s);
}
int isEmpty(Stack s)
{
    return s.top==0;
}
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int Precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}
void display(Stack *s)
{
    if(isEmpty(*s))
    {
        printf("Stack Empty!\n");
        return;
    }
    for(int i=0; i<s->top; i++)
    {
        printf("|%d", *(s->data+i));
    }
    printf("\n");
}
void init(Stack *s, int size)
{
    s->data = (int*)malloc(size*sizeof(int));
    s->size = size;
    s->top = 0;
}
void push(Stack *s, int value)
{
    if(s->size == s->top)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        *(s->data+s->top) = value;
        s->top++;
    }
}
int pop(Stack *s)
{
    if(s->top == 0)
    {
        printf("Stack Underflow!\n");
        return INT_MAX;
    }
    else
    {
        int t = s->top;
        s->top--;
        return *(s->data+t-1);
    }
}
int peek(Stack *s)
{
    if(s->top == 0)
    {
        printf("Stack Empty!\n");
        return INT_MAX;
    }
    else
    {
        return *(s->data+s->top-1);
    }
}