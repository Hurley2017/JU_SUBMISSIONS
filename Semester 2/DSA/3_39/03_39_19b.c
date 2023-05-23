#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// a structure to represent an element in the priority queue
typedef struct Queue_Node {
    int data; // the data value
    int priority; // the priority value
    struct Queue_Node *next; // the pointer to the next node
} Queue_Node;

// a structure to represent the priority queue
typedef struct Queue {
    Queue_Node *front; // the pointer to the front node
} Queue;

void display(Queue q);
void init(Queue *q);
int Front(Queue q);
int isEmpty(Queue q);
void enQueue(Queue *q, int data, int priority);
int deQueue(Queue *q);
void UI_Statements();

int main() {
    int sw, con = 1, element, size, value0, value1, init_done = 1, e, x;
    Queue q1;
    init(&q1);
    while (con) {
        UI_Statements();
        scanf("%d", &sw);
        switch (sw) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &element, &x);
                enQueue(&q1, element, x);
                break;
            case 2:
                value0 = deQueue(&q1);
                if (value0 != INT_MAX) {
                    printf("The dequeued element is %d.\n", value0);
                }
                break;
            case 3:
                value1 = Front(q1);
                if (value1 != INT_MAX) {
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

void UI_Statements() {
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

void display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue empty.\n");
    }
    while (q.front != NULL) {
        printf("%d|", q.front->data);
        q.front = q.front->next;
    }
}

void init(Queue *q) {
    q->front = NULL;
}

int Front(Queue q) {
    if (isEmpty(q)) {
        printf("Queue empty.\n");
        return INT_MAX;
    }
    return q.front->data;
}

void enQueue(Queue *q, int data, int priority) {
    // create a new node with given data and priority
    Queue_Node *new = (Queue_Node*)malloc(sizeof(Queue_Node));
    new->data = data;
    new->priority = priority;
    
     // find the position to insert the node based on its priority
     Queue_Node *prev = NULL; // the previous node
     Queue_Node *curr = q->front; // the current node
     
     while (curr != NULL && curr->priority > priority) {
         // move to the next node with higher priority
         prev = curr;
         curr = curr->next;
     }
     
     // insert the node at the correct position
     new->next = curr; // link the new node to the next node
     
     if (prev == NULL) {
         // insert at the front of the queue
         q->front = new;
     } else {
         // insert after the previous node
         prev->next = new;
     }
}

int deQueue(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue empty.\n");
        return INT_MAX;
    }
    
     // store the data of the front node
     int value = q->front->data;
     
     // remove the front node from the queue and free its memory
     Queue_Node *temp = q->front; // temporary pointer to the front node
     q->front = q->front->next; // move the front pointer to the next node
     free(temp); // free the memory allocated for the removed node
     
     // return the data of the removed node
     return value;
}

int isEmpty(Queue q) {
    return q.front == NULL;
}
