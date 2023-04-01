#include <stdio.h>
#define d 100
int dectospec(char arr[], long long n, long long f, long long p);
int dectospecf(char arr[], long double f, long long b, long long p, int limit);
void copyarr(char arr[], char copy[], int p);
int main()
{
	long long intn, b, p = 0, s = 0;
	long double n, floatn;
	char arr[d], copy[d], farr[d];
	printf("Enter the Decimal number.\n");
	scanf("%Lf", &n);
	intn = n;
	floatn = n - intn;
	printf("Enter the base you are going to convert your number to: \n");
	scanf("%lld", &b);
	if(b < 2)
	{
		printf("The answer is : 0.0\n");
		return 0;
	}
	p = dectospec(arr, intn, b, p);
	s = dectospecf(farr, floatn, b, s, 10);
	copyarr(arr, copy, p);
	printf("The answer is : %s.%s\n", copy, farr);
	return 0;
}
int dectospecf(char arr[], long double f, long long b, long long p, int limit)
{
	if(f*b == 0.0 || limit < 1)
	{
		arr[p] = 48;
		return p;
	}
	else
	{
		int tempint = f*b;
		long double tempfloat = f*b - tempint;
		if(tempint > 9)
		{
			arr[p] = 55 + tempint;
		}
		else
		{
			arr[p] = 48 + tempint;
		}
		p = dectospecf(arr, tempfloat, b, p+1, limit - 1);
		return p;
	}
}
void copyarr(char arr[], char copy[], int p)
{
	int pointer = p;
	for(int i=0; i<=p; i++)
	{
		copy[i] = arr[pointer];
		pointer = pointer - 1;
	}
}
int dectospec(char arr[], long long n, long long b, long long p)
{
	if(n<b)
	{
		if(n > 9)
		{
			arr[p] = 55 + n;
		}
		else
		{
			arr[p] = 48 + n;
		}
		return p;
	}
	else
	{
		if(n%b > 9)
		{
			arr[p] = 55 + n%b;
		}
		else
		{
			arr[p] = 48 + n%b;
		}
		p = dectospec(arr, n/b, b, p+1);
		return p;
	}
}
