#include <stdio.h>
long long calcsum(long long n, long long sum);
int main()
{
	long long sum = 0, n;
	printf("Enter the number.\n");
	scanf("%lld", &n);
	sum = calcsum(n, sum);
	printf("The sum of all the digits are : %lld.\n", sum);
	return 0;
}
long long calcsum(long long n, long long sum)
{
	sum = sum + n%10;
	if(n/10==0)
	{
		return sum;
	}
	else
	{
		n = n/10;
		calcsum(n, sum);
	}
}
