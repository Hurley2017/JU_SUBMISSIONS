#include <stdio.h>
#include <math.h>
long double cosrec(int, long double);
int main()
{
    int n;
	long double x;
	printf("Enter the value : ");
	scanf("%Lf", &x);
	printf("Enter the number of iterations : ");
	scanf("%d", &n);
    printf("After %d iterations we get the value : cos(%Lf) = %Lf\n", n, x, cosrec(n, x));
    return 0;
}
long double cosrec(int n, long double x)
{
    if (n == 0)
	{
        return 1;
	}
	else
	{
		return 1 - (pow(x, 2)/(2*n*(n + 1)))*cosrec(n - 1, x);
	}
}
