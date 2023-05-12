#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define location "/home/tusher/Desktop/JU_SUBMISSIONS/Semester 2/DSA/3_39/3.txt"
#define read "r"
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
int main()
{
    FILE *fp = fopen(location, read);
    int size = 0;
    char container;
    while(1)
    {
        container = fgetc(fp);
        if(container == EOF)
        {
            break;
        }
        size++;
    }
    rewind(fp);
    Stack s;
    init(&s, size);
    while(1)
    {
        container = fgetc(fp);
        if(container == EOF)
        {
            break;
        }
        push(&s, container-48);
    }
    while(!isEmpty(s))
    {
        printf("%d ", pop(&s));
    }
    printf("\n");
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