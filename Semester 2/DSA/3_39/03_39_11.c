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
void UI_Statements(int occ);
void takeinp(Queue *q1, int occ);
void merge(Queue *q1, Queue *q2);
int main()
{
    int sw, con = 1, element, size, value0, value1, init_done = 1;
    Queue q1, q2;
    while(con)
    {
        UI_Statements(1);
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                takeinp(&q1, 1);
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
                enQueue(&q1, element);
                break;
            case 3:
                if(init_done)
                {
                    printf("You need to create a stack first!\n");
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
                    printf("You need to create a stack first!\n");
                    break;
                }
                value1 = Front(q1);
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
                display(q1);
                break;
            case 6:
                system("cls");
                break;
            case 7:
                system("clear");
                break;
            case 8:
                con = 0;
                printf("Ok\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }
    con = 1;
    while(con)
    {
        UI_Statements(2);
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                takeinp(&q2, 2);
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
                enQueue(&q2, element);
                break;
            case 3:
                if(init_done)
                {
                    printf("You need to create a stack first!\n");
                    break;
                }
                value0 = deQueue(&q2);
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
                value1 = Front(q2);
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
                display(q1);
                break;
            case 6:
                system("cls");
                break;
            case 7:
                system("clear");
                break;
            case 8:
                con = 0;
                printf("Ok\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }
    merge(&q1, &q2);
    printf("New Queue is : ");
    display(q1);
    printf("\n");
    return 0;
}
void merge(Queue *q1, Queue *q2)
{
    q1->data = realloc(q1->data, q2->size+q1->size);
    q1->size = q1->size+q2->size;
    for(int i=0; i<q2->size; i++)
    {
        enQueue(q1, deQueue(q2));
    }
}
void UI_Statements(int occ)
{
    printf("Choose from the following : \n");
    printf("1) Create Queue %d : \n", occ);
    printf("2) Enque\n");
    printf("3) Deque\n");
    printf("4) Front\n");
    printf("5) Display the Queue\n");
    printf("6) Clear Screen (For Windows)\n");
    printf("7) Clear Screen (For Linux)\n");
    printf("8) Exit\n");
    printf("Enter your choice : ");
}
void takeinp(Queue *q1, int occ)
{
    int size;
    printf("Taking input for Queue %d\n", occ);
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
        return *(q.data + q.de_point +1);
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
        q->en_point++;
        *(q->data+q->en_point) = value;
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