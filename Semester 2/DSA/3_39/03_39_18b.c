#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node
{
    int data;
    int priority;
    struct node *next;
} Node;
typedef struct stack
{
    Node *head;
    int size;
} Stack;
void display(Stack *s);
void init(Stack *s);
void push(Stack *s, int value, int pri);
int pop(Stack *s);
int peek(Stack *s);
void pShort(Stack *s);
void UI_Statements();
int main()
{
    int sw, con = 1, element, priority, size, value0, value1;
    Stack s1;
    init(&s1);
    while (con)
    {
        UI_Statements();
        scanf("%d", &sw);
        switch (sw)
        {
        case 1:
            printf("Enter element to be pushed : ");
            scanf("%d", &element);
            printf("Enter element priority [Higher = better] : ");
            scanf("%d", &priority);
            push(&s1, element, priority);
            break;
        case 2:
            value0 = pop(&s1);
            if (value0 != INT_MAX)
            {
                printf("The popped element is %d.\n", value0);
            }
            break;
        case 3:
            value1 = peek(&s1);
            if (value1 != INT_MAX)
            {
                printf("The stack top is %d.\n", value1);
            }
            break;
        case 4:
            printf("Displaying the stack :");
            display(&s1);
            break;
        case 5:
            system("cls");
            break;
        case 6:
            system("clear");
            break;
        case 7:
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
    printf("1) Push\n");
    printf("2) Pop\n");
    printf("3) Peek\n");
    printf("4) Display the Stack\n");
    printf("5) Clear Screen (For Windows)\n");
    printf("6) Clear Screen (For Linux)\n");
    printf("7) Exit\n");
    printf("Enter your choice : ");
}
void pShort(Stack *s)
{
    Node *i, *j; 
    int temp_data, temp_priority; 
    for (i = s->head; i != NULL; i = i->next) 
    {
        for (j = i->next; j != NULL; j = j->next) 
        {
            if (i->priority < j->priority) 
            {
                temp_data = i->data;
                temp_priority = i->priority;
                i->data = j->data;
                i->priority = j->priority;
                j->data = temp_data;
                j->priority = temp_priority;
            }
        }
    }
}
void display(Stack *s)
{
    Node *temp; 
    if (s->head == NULL) 
    {
        printf("Stack Empty!\n");
        return;
    }
    for (temp = s->head; temp != NULL; temp = temp->next)
    {
        printf("<%d|%d>, ", temp->data, temp->priority); 
    }
    printf("\n");
}
void init(Stack *s)
{
    s->head = NULL; 
    s->size = 0; 
}
void push(Stack *s, int value, int pri)
{
    Node *new_node; 
    new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Stack Overflow!\n");
        return;
    }
    new_node->data = value;
    new_node->priority = pri;
    new_node->next = s->head;
    s->head = new_node;
    s->size++;
    pShort(s);  
}
int pop(Stack *s)
{
    Node *temp;
    int value;
    if (s->head == NULL) 
    {
        printf("Stack Underflow!\n");
        return INT_MAX;
    }
    temp = s->head;
    s->head = s->head->next;
    value = temp->data;
    free(temp);
    s->size--; 
    pShort(s); 
    return value;
}
int peek(Stack *s)
{
   if (s->head == NULL)
   {
       printf("Stack Empty!\n");
       return INT_MAX;
   }
   else 
   {
       return s->head->data;
   }
}
