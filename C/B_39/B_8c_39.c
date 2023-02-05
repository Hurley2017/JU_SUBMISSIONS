#include <stdio.h>
#include <stdlib.h>
void odolbodol(int*, int*);
void recper(int*, int, int);
void takeinp(int*, int);
int main()
{
  int n;
  printf("Enter number of elements : ");
  scanf("%d", &n);
  int arr[n];
  takeinp(&arr[0], n);
  recper(arr, 0, n - 1);
  return 0;
}
void takeinp(int* p, int n)
{
	int pointer = 0;
	while(pointer<n)
	{
		printf("Enter element %d: ", pointer+1);
		scanf("%d", p+pointer);
		pointer = pointer + 1;
	}
}
void odolbodol(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void recper(int *arr, int start, int end) 
{
  if (start == end) 
  {
    for (int i = 0; i <= end; i++) 
	{
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
  else
  {
    for (int i = start; i <= end; i++)
	{
      odolbodol(&arr[start], &arr[i]);
      recper(arr, start + 1, end);
      odolbodol(&arr[start], &arr[i]);
    }
  }
}