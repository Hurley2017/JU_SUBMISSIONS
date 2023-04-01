#include <math.h>
#include <stdio.h>
int main()
{
	long double sum = 0, x;
	printf("Give Number : \n");
	scanf("%Lf", &x);
	for(int i=1; i<100000; i++)
	{
		if(i%2 == 0)
		{
			sum = sum - pow(x, i)/i;
		}
		else
		{
			sum = sum + pow(x, i)/i;
		}
	}
	printf("The answer would be : %Lf\n", sum);	
}
