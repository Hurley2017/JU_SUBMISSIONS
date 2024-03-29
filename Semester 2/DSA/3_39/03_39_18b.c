#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct Queue_Node
{
    int data;
    int priority;
    struct Queue_Node *next;
} Queue_Node;
typedef struct Queue
{
    Queue_Node *front;
} Queue;
void display(Queue q);
void init(Queue *q);
int Front(Queue q);
int isEmpty(Queue q);
void enQueue(Queue *q, int data, int priority);
int deQueue(Queue *q);
void UI_Statements();
int main()
{
    int sw, con = 1, element, size, value0, value1, init_done = 1, e, x;
    Queue q1;
    init(&q1);
    while (con)
    {
        UI_Statements();
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &element, &x);
                enQueue(&q1, element, x);
                break;
            case 2:
                value0 = deQueue(&q1);
                if (value0 != INT_MAX)
                {
                    printf("The dequeued element is %d.\n", value0);
                }
                break;
            case 3:
                value1 = Front(q1);
                if (value1 != INT_MAX)
                {
                    printf("The queue front is %d.\n", value1);
                }
                break;
            case 4:
                printf("Displaying the queue :");
                display(q1);
                break;
            case 5:
                system("cls");
                break;
            case 6:
                system("clear");
                break;
            case 7:
                con = 0;
                printf("Ok\n");
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
    printf("\nChoose from the following : \n");
    printf("1) Enqueue\n");
    printf("2) Dequeue\n");
    printf("3) Front\n");
    printf("4) Display the queue\n");
    printf("5) Clear Screen (For Windows)\n");
    printf("6) Clear Screen (For Linux)\n");
    printf("7) Exit\n");
    printf("Enter your choice : ");
}
void display(Queue q)
{
    if (isEmpty(q))
     {
        printf("Queue empty.\n");
    }
    while (q.front != NULL)
    {
        printf("%d|", q.front->data);
        q.front = q.front->next;
    }
}
void init(Queue *q)
{
    q->front = NULL;
}
int Front(Queue q)
{
    if (isEmpty(q))
    {
        printf("Queue empty.\n");
        return INT_MAX;
    }
    return q.front->data;
}
void enQueue(Queue *q, int data, int priority)
{
    Queue_Node *new = (Queue_Node*)malloc(sizeof(Queue_Node));
    new->data = data;
    new->priority = priority;
    Queue_Node *prev = NULL;
    Queue_Node *curr = q->front;
    while (curr != NULL && curr->priority > priority)
    {
         prev = curr;
         curr = curr->next;
    }
    new->next = curr;     
    if (prev == NULL)
    {
        q->front = new;
    }
    else
    {
        prev->next = new;
    }
}
int deQueue(Queue *q)
{
    if(isEmpty(*q))
    {
        printf("Queue empty.\n");
        return INT_MAX;
    }
    int value = q->front->data;
    Queue_Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    return value;
}
int isEmpty(Queue q)
{
    return q.front == NULL;
}