#include <stdio.h>
#include <stdlib.h>

void UI_Statements();
int* createArray(int size);
void Quick_Sort(int arr[], int low, int high);
int Partition(int arr[], int low, int high);
void Merge_Sort(int arr[], int low, int high);
void Merge(int arr[], int low, int mid, int high);
void display(int arr[], int size);

int main()
{
    int *arr, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    arr = createArray(size);
    int choice;
    while(1)
    {
        UI_Statements();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Quick_Sort(arr, 0, size - 1);
            printf("The sorted array is: ");
            display(arr, size);
            break;
        case 2:
            Merge_Sort(arr, 0, size - 1);
            printf("The sorted array is: ");
            display(arr, size);
            break;
        case 3:
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
    printf("\n1. Quick Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Exit\n");
}

int* createArray(int size)
{
    int *arr;
    arr = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++)
    {
        printf("Enter the elements : ");
        scanf("%d", &arr[i]);   
    }
    return arr;
}   

void Quick_Sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = Partition(arr, low, high);
        Quick_Sort(arr, low, pivot - 1);
        Quick_Sort(arr, pivot + 1, high);
    }
}

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while(1)
    {
        while(arr[i] <= pivot && i <= high)
            i++;
        while(arr[j] > pivot && j >= low)
            j--;
        if(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
            arr[low] = arr[j];
            arr[j] = pivot;
            return j;
        }
    }
}

void Merge_Sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        Merge_Sort(arr, low, mid);
        Merge_Sort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

void Merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[high + 1];
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= high)
        temp[k++] = arr[j++];
    for(int i = low; i <= high; i++)
        arr[i] = temp[i];
}

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
