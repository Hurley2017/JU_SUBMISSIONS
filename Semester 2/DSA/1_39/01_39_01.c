/*
Latest version of the code is always find-able at 'https://github.com/Hurley2017/JU_SUBMISSIONS.git'
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void newline();
void UI_Statements();
void input(int *head, int size);
int *create(int size);
void display(int *head, int size);
void reverse(int *head, int size);
void indexofelement(int target, int *head, int size);
int search(int target, int *head, int size);
void sort(int *head, int size);
void merge(int *head, int *size, int target);
void split(int *head, int size, int index);
void insert(int *head, int *size, int index, int target);
void delete(int *head, int *size, int index);
int main()
{
    int size = INT_MIN, sw, *head, target, special;
    while(1)
    {
        UI_Statements();
        printf("Enter Choice : ");
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                newline();
                printf("Enter size of the list: ");
                scanf("%d", &size);
                newline();
                if(size > 0)
                {
                    head = create(size);
                    input(head, size);
                    newline();
                    printf("Successfully created a list with size %d.", size);
                    newline();
                    newline();
                }
                else
                {
                    printf("Size cannot be less than 1. Creation of list is failed!");
                    newline();
                    newline();
                }
                break;
            case 2:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'Display' operation failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("The list is : ");
                    newline();
                    display(head, size);
                    newline();
                    newline();
                }
                break;
            case 3:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'Count' operation failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("The number of element is : %d", size);
                    newline();
                    newline();
                }
                break;
            case 4:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'Reverse' operation failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("Reversing the list - ");
                    newline();
                    reverse(head, size);
                    display(head, size);
                    newline();
                    newline();
                }
                break;
            case 5:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'All-Index-Search' operation failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("Enter the element : ");
                    scanf("%d", &target);
                    newline();
                    if(search(target, head, size) == -1)
                    {
                        printf("Element is not found in the list.");
                        newline();
                        newline();
                    }
                    else
                    {
                        indexofelement(target, head, size);
                        newline();
                        newline();
                    }
                }
                break;
            case 6:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'Indexed element' operation failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("Enter index : ");
                    scanf("%d", &target);
                    newline();
                    if(target < 0 || target > size-1)
                    {
                        printf("Enter a valid index.");
                        newline();
                        newline();
                    }
                    else
                    {
                        printf("The value at index %d is %d.", target, *(head+target));
                        newline();
                        newline();
                    }
                }
                break;
            case 7:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'Insert' operation failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("Enter the index to insert at : ");
                    scanf("%d", &target);
                    if(target < 0 || target > size-1)
                    {
                        printf("Enter a valid index.");
                        newline();
                        newline();
                    }
                    else
                    {
                        newline();
                        printf("Enter the value to be inserted : ");
                        scanf("%d", &special);
                        newline();
                        insert(head, &size, target, special);
                        newline();
                        newline();
                    }
                }
                break;
            case 8:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'Delete' operation failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("Enter the index to delete at : ");
                    scanf("%d", &target);
                    if(target < 0 || target > size-1)
                    {
                        printf("Enter a valid index.");
                        newline();
                        newline();
                    }
                    else
                    {
                        newline();
                        delete(head, &size, target+1);
                        newline();
                        newline();
                    }
                }
                break;
            case 9:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'Merge' operation failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("Performing Merge operation - ");
                    newline();
                    printf("Enter the size of the new array: ");
                    scanf("%d", &target);
                    if(target >= 1)
                    {
                        merge(head, &size, target);
                        newline();
                        newline();
                    }
                    else
                    {
                        printf("new array size cannot be less than 1.");
                        newline();
                        newline();
                    }
                }
                break;
            case 10:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'Split' operation failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("Enter the index to split from : ");
                    scanf("%d", &target);
                    if(target < 0 || target > size-1)
                    {
                        printf("Enter a valid index.");
                        newline();
                        newline();
                    }
                    else
                    {
                        split(head, size, target);
                        newline();
                        newline();
                    } 
                }
                break;
            case 11:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'Sort' query failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("Performing sort operation - ");
                    newline();
                    sort(head, size);
                    display(head, size);
                    newline();
                    newline();
                }
                break;
            case 12:
                newline();
                if(size == INT_MIN)
                {
                    printf("No list is created yet. 'Search' query failed.");
                    newline();
                    newline();
                }
                else
                {
                    printf("Enter the element : ");
                    scanf("%d", &target);
                    newline();
                    int search_val = search(target, head, size);
                    if(search_val == -1)
                    {
                        printf("Element is not found in the list.");
                        newline();
                        newline();
                    }
                    else
                    {
                        printf("Element found at index - %d", search_val);
                        newline();
                        newline();
                    }
                }
                break;
            case 13:
                printf("Bye!");
                newline();
                return 0;
            case 14:
                system("clear");
                break;
            case 15:
                system("cls");
                break;
            default:
                newline();
                printf("Invalid Choice");
                newline();
                newline();
                break;
        }
    }
}
void newline()
{
    printf("\n");
}
void UI_Statements()
{
    printf("Choose from the following - ");
    newline();
    printf("1) Create ");
    newline();
    printf("2) Display the entire list ");
    newline();
    printf("3) Count (total number of elements in the list) ");
    newline();
    printf("4) Reverse the list (reversed list should be stored in the same array) ");
    newline();
    printf("5) Index of a given element (all indices if there are duplicate entries) ");
    newline();
    printf("6) Indexed element ");
    newline();
    printf("7) Insert ");
    newline();
    printf("8) Delete ");
    newline();
    printf("9) Merge ");
    newline();
    printf("10) Split ");
    newline();
    printf("11) Sort ");
    newline();
    printf("12) Search ");
    newline();
    printf("13) Exit ");
    newline();
    printf("14) Clear Screen (For Linux)");
    newline();
    printf("15) Clear Screen (For Windows)");
    newline();
}
void delete(int *head, int *size, int index)
{
    int *temp1 = (int *)malloc(index*sizeof(int));
    int *temp2 = (int *)malloc((*(size)-index)*sizeof(int));
    for(int i=0; i<index; i++)
    {
        *(temp1+i) = *(head+i);
    }
    for(int i=0; i<(*(size)-index); i++)
    {
        *(temp2+i) = *(head+i+index);
    }
    temp1 = realloc(temp1, (--index)*sizeof(int));
    for(int i = 0; i < index; i++)
    {
        *(head+i) = *(temp1+i);
    }
    for(int i=0; i<(*(size)-index)-1; i++)
    {
        *(head+i+index) = *(temp2+i);
    }
    *(size) = *(size)-1;
    head = realloc(head, (*size)*sizeof(int));
    display(head, *size);
}
void insert(int *head, int *size, int index, int target)
{
    int *temp1 = (int *)malloc(index*sizeof(int));
    int *temp2 = (int *)malloc((*(size)-index)*sizeof(int));
    for(int i=0; i<index; i++)
    {
        *(temp1+i) = *(head+i);
    }
    for(int i=0; i<(*(size)-index); i++)
    {
        *(temp2+i) = *(head+i+index);
    }
    *(size) = *(size)+1;
    temp1 = realloc(temp1, (++index)*sizeof(int));
    head = realloc(head, (*size)*sizeof(int));
    *(temp1+index-1) = target;
    for(int i = 0; i < index; i++)
    {
        *(head+i) = *(temp1+i);
    }
    for(int i=0; i<(*(size)-index); i++)
    {
        *(head+i+index) = *(temp2+i);
    }
    newline();
    display(head, *size);
    newline();
    newline();
}
void split(int *head, int size, int index)
{
    int *temp1 = (int *)malloc(index*sizeof(int));
    int *temp2 = (int *)malloc((size-index)*sizeof(int));
    for(int i=0; i<index; i++)
    {
        *(temp1+i) = *(head+i);
    }
    for(int i=0; i<(size-index); i++)
    {
        *(temp2+i) = *(head+i+index);
    }
    display(temp1, index);
    newline();
    display(temp2, size-index);
}
void merge(int *head, int *size, int target)
{
    int temp_size = target;
    int *temp = create(temp_size);
    newline();
    input(temp, temp_size);
    head = realloc(head, (temp_size+*(size))*sizeof(int));
    for(int i=0; i<temp_size; i++)
    {
        *(head+i+*(size)) = *(temp+i);
    }
    *(size) = *(size)+temp_size;
    newline();
    printf("Displaying the merged list - ");
    display(head, *size);
}
void sort(int *head, int size)
{
	for(int i=0; i<size-1; i++)
	{
		for(int j=i; j<size; j++)
		{
			if(*(head+i)>*(head+j))
			{
				int temp = *(head+i);
				*(head+i) = *(head+j);
				*(head+j) = temp;
			}
		}
	}
}
int search(int target, int *head, int size)
{
	for(int i=0; i<size; i++)
	{
		if(*(head+i) == target)
		{
			return i;
		}
	}
	return -1;
}
void indexofelement(int target, int *head, int size)
{
    printf("Element found at index(es) - ");
    for(int i=0; i<size; i++)
    {
        if(*(head+i) == target)
        {
           printf("%d,\t", i);
        }
    }
}
void reverse(int *head, int size)
{
    for(int i=0; i<size/2; i++)
    {
        int temp = *(head+i);
        *(head+i) = *(head+size-i-1);
        *(head+size-i-1) = temp;
    }   
}
void display(int *head, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d,", *(head+i));
    }
}
void input(int *head, int size)
{
    for(int i=0; i<size; i++)
    {
    	printf("Enter value of %d index : ", i);
        scanf("%d", (head+i));
    }
}
int *create(int size)
{
    int *head = (int*)malloc(size*sizeof(int));
    return head; 
}