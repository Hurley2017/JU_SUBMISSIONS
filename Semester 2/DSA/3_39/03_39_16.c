#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct CircularQueue{
    int *data, front, rear, count, size;
} CircularQueue;
void init(CircularQueue* q, int size);
int isEmpty(CircularQueue* q);
int isFull(CircularQueue* q);
void enQueue(CircularQueue *q, int value);
int deQueue(CircularQueue* q);
void display(CircularQueue q);
void UI_Statements();
int main()
{
    int sw, con = 1, element, size, value0, value1, init_done = 1, e, x;
    CircularQueue q1;
    printf("Enter the size of the Circular Queue : ");
    scanf("%d", &size);
    init(&q1, size);
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
                printf("Displaying the Queue :");
                display(q1);
                break;
            case 4:
                system("cls");
                break;
            case 5:
                system("clear");
                break;
            case 6:
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
    printf("3) Display the Queue\n");
    printf("4) Clear Screen (For Windows)\n");
    printf("5) Clear Screen (For Linux)\n");
    printf("6) Exit\n");
    printf("Enter your choice : ");
}
void init(CircularQueue* q, int size)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    q->size = size;
}
int isEmpty(CircularQueue* q)
{
    return q->count == 0;
}
int isFull(CircularQueue* q)
{
    return q->count == q->size;
}
void enQueue(CircularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue Full.\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = value;
    q->count++;
}
int deQueue(CircularQueue* q)
{
    if (isEmpty(q))
    {
        printf("Queue Empty.\n");
        return INT_MAX;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    q->count--;   
    return value;
}
void display(CircularQueue q)
{
    if (isEmpty(&q))
    {
        printf("Queue Empty.\n");
    }
    else
    {
        int i;
        printf("Circular Queue: ");
        for (i = 0; i < q.count; i++)
        {
            int index = (q.front + i) % q.size;
            printf("%d ", q.data[index]);
        }
    }
    printf("\n");
}
