#include <stdio.h>
#include <stdlib.h>
typedef struct Stack
{
    int data;
    struct Stack *next;
} Stack;
void display(Stack *s);
Stack* push(Stack **s, int value);
int pop(Stack **s);
int peek(Stack *s);
int main()
{
    Stack *head = (Stack *)malloc(sizeof(Stack));
    head = push(&head, 5);
    head = push(&head, 5);
    head = push(&head, 5);
    head = push(&head, 5);
    head = push(&head, 5);
    display(head);
    printf("%d\n", pop(&head));
    printf("%d\n", pop(&head));
    // printf("%d", pop(&head));
    // printf("%d", pop(&head));
    // printf("%d", pop(&head));
    // printf("%d", pop(&head));
    // printf("%d", pop(&head));
    // printf("%d", pop(&head));
    // printf("%d", pop(&head));
    // printf("%d", pop(&head));
    display(head);
    printf("%d\n", peek(head));
    display(head);
    return 0;
}
void display(Stack *s)
{
    Stack *point = s;
    while(s->next != NULL)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    s = point;
    printf("\n");
}
Stack* push(Stack **s, int value)
{
    Stack *new_head = (Stack*)malloc(sizeof(Stack));
    new_head->data = value;
    new_head->next = *s;
    return new_head;
}
int pop(Stack **s)
{
    if((*s)->next == NULL)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        int value = (*s)->data;
        (*s) = (*s)->next;
        return value;
    }
}
int peek(Stack *s)
{
    if(s->next == NULL)
    {
        printf("Stack Empty!\n");
    }
    else
    {
        int value = s->data;
        return value;
    }
}