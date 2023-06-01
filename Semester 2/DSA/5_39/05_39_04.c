#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void createList(struct node *head, int size)
{
    struct node *newnode = head, *temp;
    for(int i=0; i<size; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int Bubble_Sort(struct node** head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
    {
        return 1;
    }
    int swapped;
    struct node* current;
    struct node* last = NULL;
    while (1)
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
                current->next = current->next->next;
                current->next->next = current;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
        if (!swapped)
        {
            break;
        }
    }
    return 0;
}
int Selection_Sort(struct node** head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
    {
        return 1;
    }
    struct node* current;
    struct node* min;
    struct node* prev;
    struct node* min_prev;
    current = *head_ref;
    while (current->next != NULL)
    {
        min = current;
        prev = current;
        min_prev = prev;
        struct node* temp = current->next;
        while (temp != NULL)
        {
            if(temp->data < min->data)
            {
                min = temp;
                min_prev = prev;
            }
            prev = temp;
            temp = temp->next;
        }
        if(current != min)
        {
            if(current == *head_ref)
            {
                *head_ref = min;
            }
            else
            {
                min_prev->next = current;
            }
            prev->next = current;
            struct node* temp_next = current->next;
            current->next = min->next;
            min->next = temp_next;
        }
        current = current->next;
    }
    return 0;
}
int Insertion_Sort(struct node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL)
    {
        return 1;
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
            while(temp->next != NULL && current->data >= temp->next->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head_ref = sorted;
    return 0;
}
int main()
{
    struct node *head = 0;
    int size, sw, status;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    createList(head, size);
    while (1)
    {
        printf("Choose from the following: \n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Display\n");
        perror("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                status = Bubble_Sort(&head);
                if (status != 0)
                {
                    printf("Error Occured!\n");
                }
                break;
            case 2:
                status = Insertion_Sort(&head);
                if (status != 0)
                {
                    printf("Error Occured!\n");
                }
                break;
            case 3:
                status = Selection_Sort(&head);
                if (status != 0)
                {
                    printf("Error Occured!\n");
                }
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                break;
        }
    }
}