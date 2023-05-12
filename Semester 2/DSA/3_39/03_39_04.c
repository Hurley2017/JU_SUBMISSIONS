#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
int isEmpty(Stack s);
int isEqual(Stack r, Stack l);
int main()
{
    Stack s1, s2;
    int size1, size2, con = 1, sw;
    printf("Size of Stack 1 : ");
    scanf("%d", &size1);
    init(&s1, size1);
    printf("Size of Stack 2 : ");
    scanf("%d", &size2);
    init(&s2, size2);
}
int isEqual(Stack r, Stack l)
{
    if(r.top != l.top)
    {
        return 0;
    }
    if(r.size != l.size)
    {
        return 0;
    }
    for(int i=0; i<r.size; i++)
    {
        if(*(r.data+i) != *(l.data+i))
        {
            return 0;
        }
    }
    return 1;
}

int isEmpty(Stack s)
{
    if(s.top == 0)
    {
        return 1;
    }
    return 0;
}
void display(Stack *s)
{
    if(s->top == 0)
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