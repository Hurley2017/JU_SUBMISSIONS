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
int linear_search(int *array, int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int binary_search(int *array, int size, int key)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == key)
        {
            return mid;
        }
        else if (array[mid] > key)
        {
            high = mid - 1;
        }
        else if (array[mid] < key)
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int size, *array, sw, key, status;
    printf("Enter the size of the array: ");
    scanf("%d", &size); 
    array = (int *)malloc(size * sizeof(int));
    createArray(array, size);
    while(1)
    {
        printf("Enter the type of search: \n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &sw);
        switch(sw)
        {
            case 1:
                printf("Linear Search\n");
                printf("Enter the key to be searched: ");
                scanf("%d", &key);
                status = linear_search(array, size, key);
                if(status == -1)
                    printf("Key not found\n");
                else
                    printf("Key found at index %d\n", status);
                break;
            case 2:
                printf("Binary Search\n");
                printf("Enter the key to be searched: ");
                scanf("%d", &key);
                status = binary_search(array, size, key);
                if(status == -1)
                    printf("Key not found\n");
                else
                    printf("Key found at index %d\n", status);
                break;
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