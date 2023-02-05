#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long double myrec(int, long double *);
long double fibrec(int);
int main()
{
	int n;
	printf("This program is to calculate the Nth Fibonacci number where N is :\n");
	scanf("%d", &n);
	long double formula, dp, answer;
	dp = fibrec(n);
	printf("The answer comes up as %Lf.\n", dp);
}
void display(long double arr[], int n)
{
	printf("Printing the numbers.\n");
	for(int i=0; i<n; i++)
	{
		printf("%Lf, ",arr[i]);
	}
	printf("Done!\n");
}
long double fibrec(int n)
{
	long double arr[n];
	long double answer;
	for(int i=0; i<n; i++)
	{
		arr[i] = 0;
	}
	answer = myrec(n, arr);
	display(arr, n);
	return answer;
}
long double myrec(int f, long double arr[])
{
	if(f==0)
	{
		return 0;
	}
	else if(f==1)
	{
		return 1;
	}
	else
	{
		if(arr[f-1]==0)
		{
			arr[f-1] = myrec(f-1,arr)+myrec(f-2,arr);
		}
		return arr[f-1];
	}	
}
