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
void conversion(char *infix, char *postfix);
int isEmpty(Stack s);
int main()
{
    char *infix = (char*)malloc(max*sizeof(char));
    char *postfix = (char*)malloc(max*sizeof(char));
    printf("Enter the postfix expression : ");
    fgets(infix, max, stdin);
    conversion(infix, postfix);
    printf("PostFix Expression is : %s\n", postfix);
    return 0;
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
void conversion(char *infix, char *postfix)
{
    Stack stack;
    init(&stack, max);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(stack) && peek(&stack) != '(')
            {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(stack) && peek(&stack) != '(')
            {
                printf("Invalid expression\n");
                exit(1);
            }
            pop(&stack);
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(stack) && Precedence(ch) <= Precedence(peek(&stack)))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }
    while (!isEmpty(stack))
    {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
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