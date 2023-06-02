#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
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
        printf("%d ", temp->data);
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
                // Swap nodes
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
void Selection_Sort(struct node* head)
{
    struct node* start = head;
    while (start != NULL)
    {
        struct node* minNode = start;
        struct node* ptr = start->next;
        while (ptr != NULL)
        {
            if (ptr->data < minNode->data)
            {
                minNode = ptr;
            }
            ptr = ptr->next;
        }
        int temp = start->data;
        start->data = minNode->data;
        minNode->data = temp;
        start = start->next;
    }
}
//does not work
void Insertion_Sort(struct node* head)
{
    struct node* sorted = NULL;
    struct node* current = head;
    while (current != NULL)
    {
        struct node* nextNode = current->next;
        if (sorted == NULL || sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            struct node* ptr = sorted;
            while (ptr->next != NULL && ptr->next->data < current->data)
            {
                ptr = ptr->next;
            }
            current->next = ptr->next;
            ptr->next = current;
        }
        current = nextNode;
    }
    head = sorted;
}
int main()
{
    int size, sw, status;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    struct node* head = createList(size);
    while (1)
    {
        printf("\nChoose from the following: \n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                Bubble_Sort(head);
                break;
            case 2:
                Insertion_Sort(head);
                break;
            case 3:
                Selection_Sort(head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}