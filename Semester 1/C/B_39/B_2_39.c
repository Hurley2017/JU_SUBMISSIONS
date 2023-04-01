#include <stdio.h>
#include <time.h>
#include <stdlib.h>
long randint(int, int);
void takeinp(int *, int);
void displayarr(int*, int);
int collectlow(int*, int*, int, int);
int collecthigh(int*, int*, int, int);
int main()
{
	srand(time(NULL));
	int n, s_low, s_high; 
	printf("How many element are going to be in that array?\n");
	scanf("%d", &n);
	int pickrandom = randint(0, n-1);
	int mainarr[n], lowarr[n], higharr[n];
	takeinp(mainarr, n);
	s_high = collecthigh(mainarr, higharr, n, pickrandom);
	s_low = collectlow(mainarr, lowarr, n, pickrandom);
	printf("\nPrinting the array:\n");
	displayarr(mainarr, n);
	printf("The randomly picked element is %d.\n\n", mainarr[pickrandom]);
	printf("All elements greater than element %d is :\n", mainarr[pickrandom]);
	displayarr(higharr, s_high);
	printf("All elements less than element %d is :\n", mainarr[pickrandom]);
	displayarr(lowarr, s_low);
}
long randint(int min, int max)
{
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
void displayarr(int arr[], int n)
{
	int pointer = 0;
	while(pointer < n)
	{
		printf("%d\t", arr[pointer]);
		pointer = pointer + 1;
	}
	printf("\n\n");
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
int collectlow(int mainarr[], int lowarr[], int n, int pickrandom)
{
	int low = 0;
	for(int i=0; i<n; i++)
	{
		if(mainarr[i]<mainarr[pickrandom])
		{
			lowarr[low] = mainarr[i];
			low = low + 1;
		}
	}
	return low;
}
int collecthigh(int mainarr[], int higharr[], int n, int pickrandom)
{
	int high = 0;
	for(int i=0; i<n; i++)
	{
		if(mainarr[i]>mainarr[pickrandom])
		{
			higharr[high] = mainarr[i];
			high = high + 1;
		}
	}
	return high;
}
