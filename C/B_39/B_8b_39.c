#include <stdio.h>
#include <math.h>
long long factgcd(long long, long long, long long);
int main()
{
	long long a, b, t = 1;
	printf("Enter the first value :\n");
	scanf("%lld", &a);
	printf("Enter the second value :\n");
	scanf("%lld", &b);
	long long answer;
	if(a == 0 && b == 0)
	{
		printf("Infinity.\n");
		return 0;
	}
	printf("\nThe answer will be - \n");
	answer = factgcd(a, b, t);
	printf("\nThe GCD is : %lld\n", answer);
}
long long factgcd(long long a, long long b, long long t)
{
	if(a==0)
	{
		return b;
	}
	if(b==0)
	{
		return a;
	}
	long long pointer = 2;
	long long min = fmin(a, b);
	while(pointer <= min)
	{
		if(a%pointer == 0 && b%pointer == 0)
		{
			printf("\n%lld | %lld, %lld\n", pointer, a, b);
			a = a/pointer;
			b = b/pointer;
			t = t*pointer;
			return factgcd(a, b, t);	
		}
		pointer = pointer + 1;
	}
	printf("\n%d | %lld, %lld\n", 1, a, b);
	printf("\n");
	return t;
}
long long euclidgcd(long long a, long long b)
{
	if(a==0)
	{
		printf("\n%lld - %lld\n", a, b);
		return b;
	}
	else
	{
		printf("\n%lld - %lld\n", a, b);
		return euclidgcd(b%a, a);
	}
}
