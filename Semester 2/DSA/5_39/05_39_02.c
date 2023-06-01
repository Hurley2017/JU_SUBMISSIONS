// Write a menu-driven program to implement the following sorting
// techniques using an array
// (a) Bubble sort (b) Insertion sort (c) Selection sort
#include <stdio.h>
#include <stdlib.h>
void createArray(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("Done\n");
}
void display(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int Selection_Sort(int *array, int size)
{
    int i, j, temp, min;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
    return 0;
}
int Bubble_Sort(int *array, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < (size - 1) - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
    return 0;
}
int Insertion_Sort(int *array, int size)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
    return 0;
}
int main()
{
    int size, *array, sw, key, status;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));
    createArray(array, size);
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
                status = Bubble_Sort(array, size);
                if (status != 0)
                {
                    printf("Error Occured!\n");
                }
                break;
            case 2:
                status = Insertion_Sort(array, size);
                if (status != 0)
                {
                    printf("Error Occured!\n");
                }
                break;
            case 3:
                status = Selection_Sort(array, size);
                if (status != 0)
                {
                    printf("Error Occured!\n");
                }
                break;
            case 4:
                display(array, size);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                break;
        }
    }
}