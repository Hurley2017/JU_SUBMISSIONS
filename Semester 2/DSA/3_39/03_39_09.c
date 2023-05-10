#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Queue
{
    int *data, en_point, de_point, size;
} Queue;
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
    if(q->en_point == q->size-1)
    {
        printf("Queue Full!\n");
    }
    else
    {
        q->en_point++;
        *(q->data+q->en_point) = value;
    }
}
int deQueue(Queue *q, int value)
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
int main()
{
    
}