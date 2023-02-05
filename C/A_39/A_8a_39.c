#include <stdio.h>
int main()
{
	long double n, hold = 1, sum = 0;
	printf("Give bound to the series.\n");
	scanf("%Lf", &n);
	for(int i = 1; i<=n; i++)
	{
		hold = hold * i;
		sum = sum + (i/hold);
	}
	printf("\n%Lf\n", sum);
	
}