#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createList(int size)
{
    struct node *head = 0, *newnode, *temp;
    for (int i = 0; i < size; i++)
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
    return head;
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
int Bubble_Sort(struct node *head)
{
    struct node *temp = head;
    int i, j, size = 0, temp_data;
    while (temp != 0)
    {
        size++;
        temp = temp->next;
    }
    for (i = 0; i < size - 1; i++)
    {
        temp = head;
        for (j = 0; j < (size - 1) - i; j++)
        {
            if (temp->data > temp->next->data)
            {
                temp_data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp_data;
            }
            temp = temp->next;
        }
    }
    return 0;
}
int Selection_Sort(struct node *head)
{
    struct node *temp = head;
    int i, j, size = 0, temp_data, min;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    for (i = 0; i < size - 1; i++)
    {
        temp = head;
        min = i;   
        for (j = i + 1; j < size; j++)
        {
            if (temp->data > temp->next->data)
            {
                min = j;
            }
            temp = temp->next;
        }
        temp = head;
        for (j = 0; j < min; j++)
        {
            temp = temp->next;
        }
        temp_data = head->data;
        head->data = temp->data;
        temp->data = temp_data;
        head = head->next;
    }
    return 0;
}
int Insertion_Sort(struct node *head)
{
    struct node *temp = head;
    int i, j, size = 0, temp_data;
    while (temp != 0)
    {
        size++;
        temp = temp->next;
    }
    for (i = 1; i < size; i++)
    {
        temp = head;
        for (j = 0; j < i; j++)
        {
            if (temp->data > temp->next->data)
            {
                temp_data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp_data;
            }
            temp = temp->next;
        }
    }
    return 0;
}
int main()
{
    int size, sw, status;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    struct node *head = createList(size);
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
                status = Bubble_Sort(head);
                if (status != 0)
                {
                    printf("Error Occured!\n");
                }
                break;
            case 2:
                status = Insertion_Sort(head);
                if (status != 0)
                {
                    printf("Error Occured!\n");
                }
                break;
            case 3:
                status = Selection_Sort(head);
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