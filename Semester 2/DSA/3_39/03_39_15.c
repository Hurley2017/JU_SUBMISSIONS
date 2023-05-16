#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
typedef struct Queue_Node
{
    int data;
    struct Queue_Node *next;
} Queue_Node;
typedef struct Queue
{
    Queue_Node *head, *front, *rear;
} Queue;
void display(Queue q);
void init(Queue *q);
int Front(Queue q);
int isEmpty(Queue q);
void enQueue(Queue *q, int value);
int deQueue(Queue *q);
void UI_Statements();
int main()
{
    int sw, con = 1, element, size, value0, value1, init_done = 1, e, x;
    Queue q1;
    init(&q1);
    while(con)
    {
        UI_Statements();
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                printf("Enter element to be pushed : ");
                scanf("%d", &element);
                enQueue(&q1, element);
                break;
            case 2:
                value0 = deQueue(&q1);
                if(value0 != INT_MAX)
                {
                    printf("The popped element is %d.\n", value0);
                }
                break;
            case 3:
                value1 = Front(q1);
                if(value1 != INT_MAX)
                {
                    printf("The Queue Front is %d.\n", value1);
                }
                break;
            case 4:
                printf("Displaying the Queue :");
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
    printf("1) Enque\n");
    printf("2) Deque\n");
    printf("3) Front\n");
    printf("4) Display the Queue\n");
    printf("5) Clear Screen (For Windows)\n");
    printf("6) Clear Screen (For Linux)\n");
    printf("7) Exit\n");
    printf("Enter your choice : ");
}
void display(Queue q)
{
    if(isEmpty(q))
    {
        printf("Queuee Empty.\n");
    }
    while(q.front->next != NULL)
    {
        printf("%d|", q.front->data);
        q.front = q.front->next;
    }
}
void init(Queue *q)
{
    q->head = (Queue_Node*)malloc(sizeof(Queue_Node));
    q->front = q->head;
    q->rear = q->head;
}
int Front(Queue q)
{
    if(isEmpty(q))
    {
        printf("Queuee Empty.\n");
        return INT_MAX;
    }
    return q.front->data;
}
void enQueue(Queue *q, int value)
{
    q->rear->data = value;
    Queue_Node *new = (Queue_Node*)malloc(sizeof(Queue_Node));
    q->rear->next = new;
    new->next = NULL;
    q->rear = new;
}
int deQueue(Queue *q)
{
    if(isEmpty(*q))
    {
        printf("Queue Empty.\n");
        return INT_MAX;
    }
    int value = q->front->data;
    q->front = q->front->next;
    return value;
}
int isEmpty(Queue q)
{
    return q.front == q.rear;
}