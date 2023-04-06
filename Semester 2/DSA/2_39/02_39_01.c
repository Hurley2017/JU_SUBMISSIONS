#include <stdio.h>
#include <stdlib.h>
typedef struct Slist
{
    int value;
    struct Slist *next;
} Slist;
void newline();
struct Slist *init(int size);
void display(struct Slist *head);
void finsert(struct Slist **head, int value);
void einsert(struct Slist **head, int value);
void kinsert(struct Slist **head, int value, int k);
int main()
{
    int dummy = 69;
    struct Slist *head;
    head = init(3);
    newline();
    display(head);
    newline();
    finsert(&head, dummy);
    display(head);
    newline();
    einsert(&head, dummy);
    display(head);
    newline();
    kinsert(&head, dummy, 2);
    newline();
    display(head);
    return 0;
}
void finsert(struct Slist **head, int value)
{
    struct Slist *fNode = (struct Slist*)malloc(sizeof(struct Slist));
    fNode->value = value;
    fNode->next = *head;
    *head = fNode;
}
void einsert(struct Slist **head, int value)
{
    struct Slist *eNode = (struct Slist*)malloc(sizeof(struct Slist));
    eNode->value = value;
    eNode->next = NULL;
    if (*head == NULL)
    {
        *head = eNode;
    }
    else
    {
        struct Slist *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = eNode;
    }
}
void kinsert(struct Slist **head, int value, int k)
{
    struct Slist *kNode = (struct Slist*)malloc(sizeof(struct Slist));
    kNode->value = value;
    kNode->next = NULL;
    struct Slist *temp = *head;
    while(--k != 0)
    {
        if(temp->next == NULL)
        {
            printf("There is no kth node [ERROR].");    
        }
        else
        {
            temp = temp->next;
        }
    }
    kNode->next = temp->next;
    temp->next = kNode;
}
struct Slist *init(int size)
{
    struct Slist *head = NULL;
    struct Slist *temp = NULL;
    struct Slist *p = NULL;
    for (int i = 0; i < size; i++)
    {
        temp = (struct Slist*)malloc(sizeof(struct Slist));
        printf("Enter the value of node %d: ", i + 1);
        scanf("%d", &(temp->value));
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}
void display(struct Slist *head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
}
void newline()
{
    printf("\n");
}