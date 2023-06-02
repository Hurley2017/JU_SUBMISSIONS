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
    struct node* newnode;
    struct node* temp;
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
void Bubble_Sort(struct node** head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
    {
        return;
    }
    int swapped;
    struct node* current;
    struct node* last = NULL;
    do
    {
        swapped = 0;
        current = *head_ref;
        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                if (current == *head_ref)
                {
                    *head_ref = current->next;
                }
                else
                {
                    struct node* prev = *head_ref;
                    while (prev->next != current)
                    {
                        prev = prev->next;
                    }
                    prev->next = current->next;
                }
                struct node* nextNode = current->next->next;
                current->next->next = current;
                current->next = nextNode;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    }
    while (swapped);
}
void Selection_Sort(struct node** head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
    {
        return;
    }
    struct node* current = *head_ref;
    while (current != NULL)
    {
        struct node* min = current;
        struct node* temp = current->next;
        while (temp != NULL)
        {
            if (temp->data < min->data)
            {
                min = temp;
            }
            temp = temp->next;
        }
        if (min != current) 
        {
            int tempData = current->data;
            current->data = min->data;
            min->data = tempData;
        }
        current = current->next;
    }
}
void Insertion_Sort(struct node** head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
    {
        return;
    }
    struct node* sorted = NULL;
    struct node* current = *head_ref;
    while (current != NULL)
    {
        struct node* next = current->next;
        if (sorted == NULL || current->data < sorted->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            struct node* temp = sorted;
            while (temp->next != NULL && current->data >= temp->next->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head_ref = sorted;
}
int main()
{
    int size, sw, status;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    struct node* head = createList(size);
    while (1)
    {
        printf("Choose from the following: \n");
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
                printf("Bubble Sort : \n");
                Bubble_Sort(&head);
                printf("Done\n");
                break;
            case 2:
                printf("Insertion Sort : \n");
                Insertion_Sort(&head);
                printf("Done\n");
                break;
            case 3:
                printf("Selection Sort : \n");
                Selection_Sort(&head);
                printf("Done\n");
                break;
            case 4:
                printf("The list is: ");
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