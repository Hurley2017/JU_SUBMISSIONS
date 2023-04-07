#include <stdio.h>
#include <stdlib.h>
typedef struct Slist
{
    int value;
    struct Slist *next;
} Slist;
//Miscelaneous Functions
void newline();
struct Slist *init(int size);
void display(struct Slist *head);
void reverse(struct Slist **head);
void sort(struct Slist **head);
void search(struct Slist head, int target);
//Insert Functions
void finsert(struct Slist **head, int value);
void einsert(struct Slist **head, int value);
void kinsert(struct Slist **head, int value, int k);
void insertk(struct Slist **head, int value, int k);
void kvalinsert(struct Slist **head, int value, int k);
void insertkval(struct Slist **head, int value, int k);
//Delete Functions
void fdelete(struct Slist **head);
void edelete(struct Slist **head);
void kdelete(struct Slist **head, int k);
void deletek(struct Slist **head, int k);
void deleteknode(struct Slist **head, int k);
void deletebyval(struct Slist **head, int target);
int main()
{
    int dummy = 69;
    struct Slist *head;
    head = init(4);
    newline();
    display(head);
    sort(&head);
    newline();
    display(head);
    newline();
    search((*head), 3);
    return 0;
}
void search(struct Slist head, int target)
{
    newline();
    int index = 0;
    int flag = 0;
    while(head.next != NULL)
    {
        if(head.value == target)
        {
            printf("Value found at index %d.", index);
            flag = 1;
            break;
        }
        index++;
        head = *(head.next);
    }
    if(!flag)
    {
        printf("Valus is not found in the list.");
    }
    newline();
}
void reverse(struct Slist **head)
{
    int *temparr, count = 0;
    temparr = (int*)malloc(sizeof(int));
    struct Slist *pointer = *head;
    struct Slist *update = *head;
    while(pointer != NULL)
    {
        temparr = (int *)realloc(temparr, (count+1)*sizeof(int));
        *(temparr+count) = pointer->value;
        count++;
        pointer = pointer->next;
    }
    for(int i=0; i<count/2; i++)
    {
        int temp = *(temparr + i);
        *(temparr + i) = *(temparr + count - 1 - i);
        *(temparr + count -1 - i) = temp;
    }
    for(int i=0; i<count; i++)
    {
        (*head)->value = *(temparr+i);
        (*head) = (*head)->next;
    }
    (*head) = update;
}
void sort(struct Slist **head)
{
    int *temparr, count = 0;
    temparr = (int*)malloc(sizeof(int));
    struct Slist *pointer = *head;
    struct Slist *update = *head;
    while(pointer != NULL)
    {
        temparr = (int *)realloc(temparr, (count+1)*sizeof(int));
        *(temparr+count) = pointer->value;
        count++;
        pointer = pointer->next;
    }
    for(int i=0; i<count-1; i++)
    {
        for(int j=i; j<count; j++)
        {
            if(*(temparr+i) > *(temparr + j))
            {
                int temp = *(temparr + i);
                *(temparr + i) = *(temparr + j);
                *(temparr + j) = temp;
            }
        }
    }
    for(int i=0; i<count; i++)
    {
        (*head)->value = *(temparr+i);
        (*head) = (*head)->next;
    }
    (*head) = update;
}
void fdelete(struct Slist **head)
{
    if(head == NULL)
    {
        printf("List is empty [ERROR].");
    }
    else
    {
        (*head) = (*head)->next;
    }
}
void edelete(struct Slist **head)
{
    if(head == NULL)
    {
        printf("List is empty [ERROR].");
    }
    else
    {
        struct Slist *temp = *head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}
void kdelete(struct Slist **head, int k)
{
    struct Slist *temp = *head;
    int i = 0;
    while((*head) != NULL)
    {
        if(i == k)
        {
            (*head)->next = (*head)->next->next;
            break;
        }
        else
        {
            (*head) = (*head)->next;
        }
        i++;
    }
    (*head) = temp;
}
void deletek(struct Slist **head, int k)
{
    struct Slist *temp = *head;
    if (k == 1)
    {
        *head = temp->next;
    }
    else
    {
        for(int i = 1; temp != NULL && i < k - 1; i++)
        {
            temp = temp->next;
        }
        if(temp == NULL || temp->next == NULL)
        {
            printf("ERROR");
        }
        else
        {
            struct Slist* next = temp->next->next;
            temp->next = next;
        }
    }
    
}
void deletebyval(struct Slist **head, int target)
{
    struct Slist *temp = *head;
    if((*head)->value == target)
    {
        
        (*head) = (*head)->next;
    }
    else
    {
        while((*head)->next->value != target)
        {
            (*head) = (*head)->next;
        }
        (*head)->next = (*head)->next->next;
        *head = temp;
    }
}
void deleteknode(struct Slist **head, int k)
{
    struct Slist *temp = *head;
    if (k == 0)
    {
        *head = temp->next;
    }
    else
    {
        for(int i = 1; temp != NULL && i < k; i++)
        {
            temp = temp->next;
        }
        if(temp == NULL || temp->next == NULL)
        {
            printf("ERROR");
        }
        else
        {
            struct Slist* next = temp->next->next;
            temp->next = next;
        }
    }
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