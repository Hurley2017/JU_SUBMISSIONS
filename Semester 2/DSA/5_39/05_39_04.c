//before running the program make sure you are on latest gcc or mingw compiler, 
//the sortedInsert throws a message of incompatible pointer type, but it works fine on latest compiler


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createList(int size);
void display(struct node* head);
void Bubble_Sort(struct node* head);
void Insertion_Sort(struct node* head);
void sortedInsert(struct node** head_ref, struct node* newnode);
void Selection_Sort(struct node* head);
void UI_Statements();

int main()
{
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    struct node* head = createList(size);
    printf("The list is: ");
    display(head);
    int choice;
    while(1)
    {
        UI_Statements();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Bubble_Sort(head);
            printf("The sorted list is: ");
            display(head);
            break;
        case 2:
            Insertion_Sort(head);
            printf("The sorted list is: ");
            display(head);
            break;
        case 3:
            Selection_Sort(head);
            printf("The sorted list is: ");
            display(head);
            break;
        case 4:
            printf("Bye\n");
            exit(0);
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    }
    return 0;
}

void UI_Statements()
{
    printf("Choose from the following: \n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Exit\n");
}

struct node* createList(int size)
{
    struct node* head = NULL;
    struct node* newnode, *temp;
    for (int i = 0; i < size; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node* head)
{
    struct node* temp = head;

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }

    printf("\n");
}


void Bubble_Sort(struct node* head)
{
    int swapped;
    struct node* ptr;
    struct node* lptr = NULL;
    if (head == NULL)
    {
        return;
    }
    do
    {
        swapped = 0;
        ptr = head;
        while (ptr->next != lptr)
        {
            if (ptr->data > ptr->next->data)
            {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

void Insertion_Sort(struct node* head)
{
    struct node* sorted = NULL;
    struct node* current = head;
    while (current != NULL)
    {
        struct node* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    head = sorted;
}

void sortedInsert(struct node** head_ref, struct node* newnode)
{
    struct node* current;
    if (*head_ref == NULL || (*head_ref)->data >= newnode->data)
    {
        newnode->next = *head_ref;
        *head_ref = newnode;
    }
    else
    {
        current = *head_ref;
        while (current->next != NULL && current->next->data < newnode->data)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void Selection_Sort(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        struct node* min = temp;
        struct node* r = temp->next;
        while (r != NULL)
        {
            if (min->data > r->data)
            {
                min = r;
            }
            r = r->next;
        }
        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
}