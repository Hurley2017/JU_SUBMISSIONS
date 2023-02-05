#include <stdio.h>
#include <math.h>
long long lcm(long long, long long);
int main()
{
	int n;
	printf("Enter the number of integers:\n");
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		printf("Number %d : ", i);
		scanf("%d", &arr[i]);
		if(arr[i] == 0)
		{
			printf("\nCannot be calculated!\n");
			return 0;
		}
	}
	printf("\n");
	long long answer = arr[0];
	int pointer = 0;
	while(pointer<n)
	{
		answer = lcm(answer, arr[pointer]);
		pointer = pointer + 1;
	}
	printf("The answer is %lld\n.", answer);
	return 0;
}
long long lcm(long long a, long long b)
{
	long long l = 1;
	long long max = fmax(a, b);
	int pointer = 1;
	while(1)
	{
		if((max*pointer)%b == 0 && (max*pointer)%a == 0)
		{
			l = max*pointer;
			return l;
		}
		pointer = pointer + 1;
		
	}
	return l;
}