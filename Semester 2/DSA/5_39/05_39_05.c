// Write a menu-driven program to implement the following sorting
// techniques using an array (recursive functions)
// (a) Quick sort (b) Merge sort
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
void Quick_Sort(int *array, int size)
{
    int pivot = array[size - 1], i = -1, j, temp;
    if (size == 1)
    {
        return;
    }
    for (j = 0; j < size - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[size - 1];
    array[size - 1] = temp;
    Quick_Sort(array, i + 1);
    Quick_Sort(array + i + 2, size - i - 2);
}
void Merge_Sort(int *array, int size)
{
    int i, j, k, mid = size / 2, *temp = (int *)malloc(size * sizeof(int));
    if (size == 1)
    {
        return;
    }
    Merge_Sort(array, mid);
    Merge_Sort(array + mid, size - mid);
    for (i = 0, j = mid, k = 0; i < mid && j < size;)
    {
        if (array[i] < array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
    }
    while (i < mid)
    {
        temp[k++] = array[i++];
    }
    while (j < size)
    {
        temp[k++] = array[j++];
    }
    for (i = 0; i < size; i++)
    {
        array[i] = temp[i];
    }
    free(temp);
}
int main()
{
    int size, *array, sw, status;
    printf("Enter the size of the array: ");
    scanf("%d", &size); 
    array = (int *)malloc(size * sizeof(int));
    createArray(array, size);
    while(1)
    {
        printf("Enter the type of search: \n");
        printf("1. Quick_Sort\n");
        printf("2. Merge_Sort\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &sw);
        switch(sw)
        {
            case 1:
                printf("Quick Sort\n");
                Quick_Sort(array, size);
                printf("Done\n");
                break;
            case 2:
                printf("Merge Sort\n");
                Merge_Sort(array, size);
                printf("Done\n");
            case 3:
                display(array, size);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                break;
        }
    }
}