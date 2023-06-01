//Implement a menu driven program of Linear and binary search for an array of integers.
#include <stdio.h>
#include <stdlib.h>
void linear_search(int a[],int n,int key)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("Element found at position %d\n",i+1);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Element not found\n");
}
void binary_search(int a[],int n,int key)
{
    int i,flag=0,low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            printf("Element found at position %d\n",mid+1);
            flag=1;
            break;
        }
        else if(a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    if(flag==0)
        printf("Element not found\n");
}
int main()
{
    int n,i,key,choice;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    printf("Enter 1 for linear search and 2 for binary search\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: linear_search(a,n,key);
                break;
        case 2: binary_search(a,n,key);
                break;
        default: printf("Invalid choice\n");
    }
    return 0;
}