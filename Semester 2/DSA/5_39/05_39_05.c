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
void Quick_Sort(int *array, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = array[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[end];
    array[end] = temp;
    Quick_Sort(array, start, i);
    Quick_Sort(array, i + 2, end);
}
void Merge(int *array, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *leftArray = (int *)malloc(n1 * sizeof(int));
    int *rightArray = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        rightArray[j] = array[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
    free(leftArray);
    free(rightArray);
}
void Merge_Sort(int *array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        Merge_Sort(array, left, mid);
        Merge_Sort(array, mid + 1, right);
        Merge(array, left, mid, right);
    }
}
int main()
{
    int size, *array, sw, status;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));
    createArray(array, size);
    while (1)
    {
        printf("Enter the type of sort: \n");
        printf("1. Quick Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &sw);
        switch (sw)
        {
        case 1:
            printf("Quick Sort\n");
            Quick_Sort(array, 0, size - 1);
            printf("Done\n");
            break;
        case 2:
            printf("Merge Sort\n");
            Merge_Sort(array, 0, size - 1);
            printf("Done\n");
            break;
        case 3:
            printf("The array is : ");
            display(array, size);
            break;
        case 4:
            printf("Exiting...\n");
            free(array);
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }
}