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
void insertk(struct Slist **head, int value, int k);
void kvalinsert(struct Slist **head, int value, int k);
void insertkval(struct Slist **head, int value, int k);
int main()
{
    int dummy = 69;
    struct Slist *head;
    head = init(3);
    newline();
    display(head);
    newline();
    kinsert(&head, dummy, 2);
    display(head);
    newline();
    insertk(&head, dummy, 2);
    display(head);
    kvalinsert(&head, dummy, 3);
    newline();
    display(head);
    insertkval(&head, dummy, 3);
    newline();
    display(head);
    newline();
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
void insertk(struct Slist **head, int value, int k)
{
    k++;
    struct Slist *kNode = (struct Slist*)malloc(sizeof(struct Slist));
    kNode->value = value;
    kNode->next = NULL;
    if (*head == NULL || k == 1)
    {
        kNode->next = *head;
        *head = kNode;
        return;
    }
    struct Slist *temp = *head;
    for (int i = 0; i < k - 2 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("The linked list has less than %d nodes.\n", k - 1);
        return;
    }
    kNode->next = temp->next;
    temp->next = kNode;
}
void kinsert(struct Slist **head, int value, int k)
{
    struct Slist *kNode = (struct Slist*)malloc(sizeof(struct Slist));
    kNode->value = value;
    kNode->next = NULL;
    if (*head == NULL)
    {
        *head = kNode;
        return;
    }
    struct Slist *temp = *head;
    for (int i = 0; i < k && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("The linked list has less than %d nodes.\n", k);
        return;
    }
    kNode->next = temp->next;
    temp->next = kNode;
}
void kvalinsert(struct Slist **head, int value, int k)
{
    int flag = 0;
    struct Slist *kNode = (struct Slist*)malloc(sizeof(struct Slist));
    kNode->value = value;
    kNode->next = NULL;
    struct Slist *temp = *head;
    while(temp != NULL)
    {
        if(temp->value == k)
        {
            kNode->next = temp->next;
            temp->next = kNode;
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag == 0)
    {
        printf("Node is not found by the particular value.");
        newline();
    }
}
void insertkval(struct Slist **head, int value, int k)
{
    struct Slist *kNode = (struct Slist*)malloc(sizeof(struct Slist));
    kNode->value = value;
    kNode->next = NULL;
    if (*head == NULL || (*head)->value == k)
    {
        kNode->next = *head;
        *head = kNode;
        return;
    }
    struct Slist *temp = *head;
    while (temp->next != NULL && temp->next->value != k) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("The linked list does not contain the value %d.\n", value);
        return;
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