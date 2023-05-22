#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Deque_Node
{
    int data;
    struct Deque_Node *next, *prev;
} Deque_Node;

typedef struct Deque
{
    Deque_Node *front, *rear;
} Deque;

void display(Deque q);
void init(Deque *q);
int Front(Deque q);
int Rear(Deque q);
int isEmpty(Deque q);
void enQueue(Deque *q, int value, int side);
int deQueue(Deque *q, int side);

int main()
{
    int sw, con = 1, element;
    Deque q1;
    init(&q1);
    while(con)
    {
        printf("\nChoose from the following : \n");
        printf("1) Enqueue at front\n");
        printf("2) Enqueue at rear\n");
        printf("3) Dequeue at front\n");
        printf("4) Dequeue at rear\n");
        printf("5) Front\n");
        printf("6) Rear\n");
        printf("7) Display the Queue\n");
        printf("8) Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                printf("Enter element to be enqueued at front : ");
                scanf("%d", &element);
                enQueue(&q1, element, 1);
                break;
            case 2:
                printf("Enter element to be enqueued at rear : ");
                scanf("%d", &element);
                enQueue(&q1, element, 0);
                break;
            case 3:
                element = deQueue(&q1, 1);
                if(element != INT_MAX)
                {
                    printf("The dequeued element from front is %d.\n", element);
                }
                break;
            case 4:
                element = deQueue(&q1, 0);
                if(element != INT_MAX)
                {
                    printf("The dequeued element from rear is %d.\n", element);
                }
                break;
            case 5:
                element = Front(q1);
                if(element != INT_MAX)
                {
                    printf("The Queue Front is %d.\n", element);
                }
                break;
            case 6:
                element = Rear(q1);
                if(element != INT_MAX)
                {
                    printf("The Queue Rear is %d.\n", element);
                }
                break;
            case 7:
                printf("Displaying the Queue : ");
                display(q1);
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
    return 0;
}

void display(Deque q)
{
    if(isEmpty(q))
    {
        printf("Queue Empty.\n");
        return;
    }
    while(q.front != NULL)
    {
        printf("%d|", q.front->data);
        q.front = q.front->next;
    }
}

void init(Deque *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int Front(Deque q)
{
    if(isEmpty(q))
    {
        printf("Queue Empty.\n");
        return INT_MAX;
    }
    return q.front->data;
}

int Rear(Deque q)
{
    if(isEmpty(q))
    {
        printf("Queue Empty.\n");
        return INT_MAX;
    }
    return q.rear->data;
}

void enQueue(Deque *q, int value, int side)
{
    Deque_Node *new = (Deque_Node*)malloc(sizeof(Deque_Node));
    new->data = value;

    if(isEmpty(*q))
    {
        new->next = NULL;
        new->prev = NULL;
        q->front = new;
        q->rear = new;
        return;
    }

    if(side == 0)
    {
        new->next = NULL;
        new->prev = q->rear;

        q->rear->next = new;

        q->rear = new; 
    }
    
else
{
new->prev=NULL; 
new->next=q->front; 
q->front->prev=new; 
q->front=new; 
}
}
int deQueue(Deque *q,int side) 
{ 
    if(isEmpty(*q)) 
    { 
        printf("Queue Empty.\n"); 
        return INT_MAX; 
    }
    if(side==0) 
    { 
        int value=q->rear->data; 
        if(q->front==q->rear) 
        { 
            free(q->rear); 
            init(q); 
            return value; 
        }
        else
        {
            Deque_Node *temp=q->rear; 
            q->rear=q->rear->prev; 
            free(temp); 
            return value; 
        }
    }
    else
    {
        int value=q->front->data; 
        if(q->front==q->rear) 
        { 
            free(q->front); 
            init(q); 
            return value; 
        }
        else
        {
            Deque_Node *temp=q->front; 
            q->front=q->front->next; 
            free(temp); 
            return value; 
        }
    }
}
int isEmpty(Deque q) 
{ 
    return (q.front==NULL && q.rear==NULL); 
}
