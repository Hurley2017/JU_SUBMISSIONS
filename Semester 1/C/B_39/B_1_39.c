#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int genericmax(int*, int, int);
void takeinp(int*, int);
void copyarr(int* , int*, int);
int immediatemax(int*, int);
int main()
{
	int n, mid;
	printf("How many elements will be in the array?\n");
	scanf("%d", &n);
	int arr[n], t_temp[n], f_temp[n];
	takeinp(arr, n);
	copyarr(t_temp, arr, n);
	copyarr(f_temp, arr, n);
	//copyarr(m_temp, arr, n);
	printf("The third maximum element is %d.\n", genericmax(t_temp, n, 3));
	printf("The fifth minimum element is %d.\n", genericmax(f_temp, n, n-5+1));
	if(n%2==0)
	{
		printf("The middle element of the array is %d and %d.\n", arr[n/2-1], arr[n/2]);
	}
	else
	{
		printf("The middle element of the array is %d.\n", arr[n/2]);
	}
	return 0;
	
}
void takeinp(int arr[], int n)
{
	printf("Taking inputs one by one.\n");
	for(int i=0; i<n; i++)
	{
		printf("Enter element %d:",i+1);
		scanf("%d", &arr[i]);
	}
	printf("\n");
}
void copyarr(int temp[], int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		temp[i] = arr[i];
	}
}
int genericmax(int arr[], int n, int point)
{
	int min;
	for(int i=0; i<point; i++)
	{
		min = immediatemax(arr, n);	
	}
	return min;
}
int immediatemax(int arr[], int n)
{
	int i_max = 0, temp;
	for(int i = 0; i<n; i++)
	{
		if(arr[i]>arr[i_max])
		{
			i_max = i;
		}
	}
	temp = arr[i_max];
	arr[i_max] = INT_MIN;
	return temp;
}
