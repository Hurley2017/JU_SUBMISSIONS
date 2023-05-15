#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct
{
    int *data, en_point, de_point, size;
} Queue;
void display(Queue q);
void init(Queue *q, int size);
int isFull(Queue q);
int Front(Queue q);
int isEmpty(Queue q);
void enQueue(Queue *q, int value);
int deQueue(Queue *q);
void UI_Statements();
void takeinp(Queue *q1);
void reverse(Queue *q1);
int main()
{
    int sw, con = 1, element, size, value0, value1, init_done = 1;
    Queue q1, q2;
    while(con)
    {
        UI_Statements();
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                takeinp(&q1);
                init_done = 0;
                break;
            case 2:
                if(init_done)
                {
                    printf("You need to create a Queue first!\n");
                    break;
                }
                printf("Enter element to be pushed : ");
                scanf("%d", &element);
                enQueue(&q1, element);
                break;
            case 3:
                if(init_done)
                {
                    printf("You need to create a Queue first!\n");
                    break;
                }
                value0 = deQueue(&q1);
                if(value0 != INT_MAX)
                {
                    printf("The popped element is %d.\n", value0);
                }
                break;
            case 4:
                if(init_done)
                {
                    printf("You need to create a Queue first!\n");
                    break;
                }
                value1 = Front(q1);
                if(value1 != INT_MAX)
                {
                    printf("The Queue Front is %d.\n", value1);
                }
                break;
            case 5:
                if(init_done)
                {
                    printf("You need to create a Queue first!\n");
                    break;
                }
                printf("Displaying the Queue :");
                display(q1);
                break;
            case 6:
                if(init_done)
                {
                    printf("You need to create a Queue first!\n");
                    break;
                }
                reverse(&q1);
                printf("Successfully reversed the queue!\n");
                break;
            case 7:
                system("cls");
                break;
            case 8:
                system("clear");
                break;
            case 9:
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
    printf("Choose from the following : \n");
    printf("1) Create Queue : \n");
    printf("2) Enque\n");
    printf("3) Deque\n");
    printf("4) Front\n");
    printf("5) Display the Queue\n");
    printf("6) Reverse the Queue\n");
    printf("7) Clear Screen (For Windows)\n");
    printf("8) Clear Screen (For Linux)\n");
    printf("9) Exit\n");
    printf("Enter your choice : ");
}
void reverse(Queue *q1)
{
    for(int i=0; i<q1->size/2; i++)
    {
        int temp = *(q1->data+i+q1->de_point + 1);
        *(q1->data+i+q1->de_point + 1) = *(q1->data+(q1->en_point-i));
        *(q1->data+(q1->en_point-i)) = temp;
    }
}
void takeinp(Queue *q1)
{
    int size;
    printf("Taking input for Queue\n");
    printf("Enter the size of the Queue : ");
    scanf("%d", &size);
    init(q1, size);
}
void init(Queue *q, int size)
{
    q->data = (int*)malloc(size*sizeof(int));
    q->size = size;
    q->en_point = -1;
    q->de_point = -1;
}
int isFull(Queue q)
{
    return q.en_point == q.size-1;
}
int isEmpty(Queue q)
{
    return q.en_point == q.de_point;
}
int Front(Queue q)
{
    if(isEmpty(q))
    {
        printf("Queue Empty!\n");
        return INT_MAX;
    }
    else
    {
        return *(q.data + q.de_point + 1);
    }
}
void enQueue(Queue *q, int value)
{
    if(isFull(*q))
    {
        printf("Queue Full!\n");
    }
    else
    {
        *(q->data+(++q->en_point)) = value;
    }
}
int deQueue(Queue *q)
{
    if(isEmpty(*q))
    {
        printf("Queue Empty!\n");
        return INT_MAX;
    }
    else
    {
        return *(q->data + q->de_point++ +1);
    }
}
void display(Queue q)
{
    if(isEmpty(q))
    {
        printf("Queue Empty!\n");
    }
    else
    {
        for(int i = q.de_point+1; i<=q.en_point; i++)
        {
            printf("|%d", *(q.data+i));
        }
        printf("\n");
    }
}