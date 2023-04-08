#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Dlist 
{
    int value;
    struct Dlist *prev, *next;
} Dlist;
struct Dlist *init(int size);
void newline();
void display(struct Dlist *head);
void reverse(struct Dlist **head);
void UI_Statements();
//Insert Functions
void finsert(struct Dlist **head, int value);
void einsert(struct Dlist **head, int value);
void kinsert(struct Dlist **head, int value, int k);
void insertk(struct Dlist **head, int value, int k);
void kvalinsert(struct Dlist **head, int value, int k);
void insertkval(struct Dlist **head, int value, int k);
//Delete Functions
void fdelete(struct Dlist **head);
void edelete(struct Dlist **head);
void kdelete(struct Dlist **head, int k);
void deletek(struct Dlist **head, int k);
void deleteknode(struct Dlist **head, int k);
void deletebyval(struct Dlist **head, int target);
int main()
{
    struct Dlist *head;
    int sw, size = INT_MIN, value, k;
    UI_Statements();
    while(1)
    {
        printf("Enter your choice : ");
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                newline();
                printf("Enter the size of the new list : ");
                scanf("%d", &size);
                if(size < 1)
                {
                    printf("List of size less than 1 could not be created. [ERROR].");
                    newline();
                }
                else
                {
                    head = init(size);
                    newline();
                    printf("Successfully created a list of size %d.", size);
                    newline();
                }
                break;
            case 2:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("The list is : ");
                    display(head);
                    newline();
                }
                break;
            case 3:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Enter the value of the new node : ");
                    scanf("%d", &value);
                    finsert(&head, value);
                    newline();
                }
                break;
            case 4:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Enter the value of the new node : ");
                    scanf("%d", &value);
                    einsert(&head, value);
                    newline();
                }
                break;
            case 5:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Enter the value of the new node : ");
                    scanf("%d", &value);
                    printf("Enter the value of k : ");
                    scanf("%d", &k);
                    kinsert(&head, value, k);
                    newline();
                }
                break;
            case 6:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Enter the value of the new node : ");
                    scanf("%d", &value);
                    printf("Enter the value of target node : ");
                    scanf("%d", &k);
                    kvalinsert(&head, value, k);
                    newline();
                }
                break;
            case 7:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Enter the value of the new node : ");
                    scanf("%d", &value);
                    printf("Enter the value of k : ");
                    scanf("%d", &k);
                    insertk(&head, value, k);
                    newline();
                }
                break;
            case 8:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Enter the value of the new node : ");
                    scanf("%d", &value);
                    printf("Enter the value of target node : ");
                    scanf("%d", &k);
                    insertkval(&head, value, k);
                    newline();
                }
                break;
            case 9:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Deleting the first node : ");
                    fdelete(&head);
                    newline();
                }
                break;
            case 10:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Deleting the last node : ");
                    edelete(&head);
                    newline();
                }
                break;
            case 11:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Enter the value of k : ");
                    scanf("%d", &k);
                    kdelete(&head, k);
                    newline();
                }
                break;
            case 12:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Enter the value of k : ");
                    scanf("%d", &k);
                    deletek(&head, k);
                    newline();
                }
                break;
            case 13:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Enter the value of k : ");
                    scanf("%d", &k);
                    deleteknode(&head, k);
                    newline();
                }
                break;
            case 14:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Enter the value of target node : ");
                    scanf("%d", &value);
                    deleteknode(&head, value);
                    newline();
                }
                break;
            case 15:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Reversing the list : ");
                    reverse(&head);
                    newline();
                }
                break;
            case 16:
                system("clear");
                UI_Statements();
                break;
            case 17:
                system("cls");
                UI_Statements();
                break;
            case 18:
                return 0;
            default:
                printf("Invalid choice.");
                newline();
                newline();
                break;
        }
    }
    return 0;
}
struct Dlist *init(int size)
{
    struct Dlist *head = NULL;
    struct Dlist *temp = NULL;
    struct Dlist *p = NULL;
    for (int i = 0; i < size; i++)
    {
        temp = (struct Dlist*)malloc(sizeof(struct Dlist));
        printf("Enter the value of node number %d: ", i);
        scanf("%d", &(temp->value));
        temp->prev = NULL;
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
            temp->prev = p;
        }
    }
    return head;
}
void UI_Statements()
{
    printf("A menu-driven program that performs the following on a doubly linked list.");
    newline();
    newline();
    printf("1. Create a linked list.");
    newline();
    printf("2. Print the content of the list.");
    newline();
    printf("3. Insert an element at the front of the list.");
    newline();
    printf("4. Insert an element at the end of the list.");
    newline();
    printf("5. Insert a node after the kth node.");
    newline();
    printf("6. Insert a node after the node (first from the start) containing a given value.");
    newline();
    printf("7. Insert a node before the kth node.");
    newline();
    printf("8. Insert a node before the node (first from the start) containing a given value.");
    newline();
    printf("9. Delete the first node.");
    newline();
    printf("10. Delete the last node.");
    newline();
    printf("11. Delete a node after the kth node.");
    newline();
    printf("12. Delete a node before the kth node.");
    newline();
    printf("13. Delete the kth node.");
    newline();
    printf("14. Delete the node(first from the start) containing a specified value.");
    newline();
    printf("15. Find the reverse of a list(not just printing in reverse).");
    newline();
    printf("16. Clear Screen (For Linix).");
    newline();
    printf("17. Clear Screen (For Windows).");
    newline();
    printf("18. Exit.");
    newline();
    newline();
}
void reverse(struct Dlist **head)
{
    int *temparr, count = 0;
    temparr = (int*)malloc(sizeof(int));
    struct Dlist *pointer = *head;
    struct Dlist *update = *head;
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
void fdelete(struct Dlist **head)
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
void edelete(struct Dlist **head)
{
    if(head == NULL)
    {
        printf("List is empty [ERROR].");
    }
    else
    {
        struct Dlist *temp = *head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}
void kdelete(struct Dlist **head, int k)
{
    struct Dlist *temp = *head;
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
void deletek(struct Dlist **head, int k)
{
    struct Dlist *temp = *head;
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
            struct Dlist* next = temp->next->next;
            temp->next = next;
        }
    }
    
}
void deletebyval(struct Dlist **head, int target)
{
    struct Dlist *temp = *head;
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
void deleteknode(struct Dlist **head, int k)
{
    struct Dlist *temp = *head;
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
            struct Dlist* next = temp->next->next;
            temp->next = next;
        }
    }
}
void finsert(struct Dlist **head, int value)
{
    struct Dlist *fNode = (struct Dlist*)malloc(sizeof(struct Dlist));
    fNode->value = value;
    fNode->next = *head;
    *head = fNode;
}
void einsert(struct Dlist **head, int value)
{
    struct Dlist *eNode = (struct Dlist*)malloc(sizeof(struct Dlist));
    eNode->value = value;
    eNode->next = NULL;
    if (*head == NULL)
    {
        *head = eNode;
    }
    else
    {
        struct Dlist *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = eNode;
    }
}
void insertk(struct Dlist **head, int value, int k)
{
    k++;
    struct Dlist *kNode = (struct Dlist*)malloc(sizeof(struct Dlist));
    kNode->value = value;
    kNode->next = NULL;
    if (*head == NULL || k == 1)
    {
        kNode->next = *head;
        *head = kNode;
        return;
    }
    struct Dlist *temp = *head;
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
void kinsert(struct Dlist **head, int value, int k)
{
    struct Dlist *kNode = (struct Dlist*)malloc(sizeof(struct Dlist));
    kNode->value = value;
    kNode->next = NULL;
    if (*head == NULL)
    {
        *head = kNode;
        return;
    }
    struct Dlist *temp = *head;
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
void kvalinsert(struct Dlist **head, int value, int k)
{
    int flag = 0;
    struct Dlist *kNode = (struct Dlist*)malloc(sizeof(struct Dlist));
    kNode->value = value;
    kNode->next = NULL;
    struct Dlist *temp = *head;
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
void insertkval(struct Dlist **head, int value, int k)
{
    struct Dlist *kNode = (struct Dlist*)malloc(sizeof(struct Dlist));
    kNode->value = value;
    kNode->next = NULL;
    if (*head == NULL || (*head)->value == k)
    {
        kNode->next = *head;
        *head = kNode;
        return;
    }
    struct Dlist *temp = *head;
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
void display(struct Dlist *head)
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