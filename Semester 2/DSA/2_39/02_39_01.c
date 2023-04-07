#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
void merge(struct Slist **head);
void concatenate(struct Slist **head);
int isequal(struct Slist **head);
void UI_Statements();
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
    int sw, size = INT_MIN, value, k;
    struct Slist *head;
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
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    printf("Sorting the list : ");
                    sort(&head);
                    newline();
                }
                break;
            case 17:
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
                    search((*head), value);
                    newline();
                }
                break;
            case 18:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    merge(&head);
                    newline();
                }
                break;
            case 19:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    concatenate(&head);
                    newline();
                }
                break;
            case 20:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is yet created! [ERROR].");
                    newline();
                }
                else
                {
                    if(isequal(&head))
                    {
                        printf("TRUE");
                    }
                    else
                    {
                        printf("FALSE");
                    }
                }
                break;
            case 21:
                system("cls");
                UI_Statements();
                break;
            case 22:
                system("clear");
                UI_Statements();
                break;
            case 23:
                return 0;
            default:
                break;
        }
    }
    return 0;
}
void UI_Statements()
{
    printf("A menu-driven program that performs the following on a single linked list.");
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
    printf("16. Sort the list.");
    newline();
    printf("17. Search a given element.");
    newline();
    printf("18. Merge two lists; those are in ascending order.");
    newline();
    printf("19. Concatenate two list.");
    newline();
    printf("20. Find if two lists are equal(Boolean output).");
    newline();
    printf("21. Clear Screen (For Windows).");
    newline();
    printf("22. Clear Screen (For Linux).");
    newline();
    printf("23. Exit.");
    newline();
    newline();
}
int isequal(struct Slist **head)
{
    int newsize;
    struct Slist *newlist;
    struct Slist *pointer = *head;
    printf("Enter the size of the new linked list.");
    scanf("%d", &newsize);
    newlist = init(newsize);
    if(pointer == NULL && newlist == NULL)
    {
        return 1;
    }
    else
    {
        while(pointer != NULL || newlist != NULL)
        {
            if((pointer != NULL && newlist == NULL) || (pointer == NULL && newlist != NULL))
            {
                return 0;
            }
            else
            {
                if(pointer->value != newlist->value)
                {
                    return 0;
                }
            }
            pointer = pointer->next;
            newlist = newlist->next;
        }
    }
    return 1;
}
void merge(struct Slist **head)
{
    int newsize;
    struct Slist *newlist;
    struct Slist *pointer = *head;
    printf("Enter the size of the new linked list.");
    scanf("%d", &newsize);
    newlist = init(newsize);
    while((*head)->next != NULL)
    {
        (*head) = (*head)->next;
    }
    (*head)->next = newlist;
    (*head) = pointer;
    sort(head);
}
void concatenate(struct Slist **head)
{
    int newsize;
    struct Slist *newlist;
    struct Slist *pointer = *head;
    printf("Enter the size of the new linked list.");
    scanf("%d", &newsize);
    newlist = init(newsize);
    while((*head)->next != NULL)
    {
        (*head) = (*head)->next;
    }
    (*head)->next = newlist;
    (*head) = pointer;
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