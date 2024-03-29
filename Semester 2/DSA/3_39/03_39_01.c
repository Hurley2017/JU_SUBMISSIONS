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
void UI_Statements();
int main()
{
    int sw, con = 1, element, size, value0, value1, init_done = 1;
    Stack s1;
    UI_Statements();
    while(con)
    {
        printf("Enter your choice : ");
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                printf("Enter the size of the Stack : ");
                scanf("%d", &size);
                init(&s1, size);
                init_done = 0;
                break;
            case 2:
                if(init_done)
                {
                    printf("You need to create a stack first!\n");
                    break;
                }
                printf("Enter element to be pushed : ");
                scanf("%d", &element);
                push(&s1, element);
                break;
            case 3:
                if(init_done)
                {
                    printf("You need to create a stack first!\n");
                    break;
                }
                value0 = pop(&s1);
                if(value0 != INT_MAX)
                {
                    printf("The popped element is %d.\n", value0);
                }
                break;
            case 4:
                if(init_done)
                {
                    printf("You need to create a stack first!\n");
                    break;
                }
                value1 = peek(&s1);
                if(value1 != INT_MAX)
                {
                    printf("The stack top is %d.\n", value1);
                }
                break;
            case 5:
                if(init_done)
                {
                    printf("You need to create a stack first!\n");
                    break;
                }
                printf("Displaying the stack :");
                display(&s1);
                break;
            case 6:
                system("cls");
                break;
            case 7:
                system("clear");
                break;
            case 8:
                con = 0;
                printf("Bye\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }
    return 0;
}
void UI_Statements()
{
    printf("Choose from the following : \n");
    printf("1) Create a Stack : \n");
    printf("2) Push\n");
    printf("3) Pop\n");
    printf("4) Peek\n");
    printf("5) Display the Stack\n");
    printf("6) Clear Screen (For Windows)\n");
    printf("7) Clear Screen (For Linux)\n");
    printf("8) Exit\n");
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