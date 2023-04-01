#include <stdio.h>
#include <math.h>
#define py 3.142
int main()
{
	float x; 
	long long hold = 1, s = 1; 
	long double sum = 0;
	printf("To Calculate Sin(x), Enter x = ");
	scanf("%f", &x);
	x = x*(180/py);
    while(x>=360)
    {
        x = x - 360;
    }
	x = x*(py/180);
	for(int i = 0; i <= 10; i++)
	{
		if(i%2==0)
		{
			sum = sum + (pow(x, s)/hold);
		}
		else
		{
			sum = sum - (pow(x, s)/hold);
		}
		s = s + 2;
		hold = hold*s*(s-1);
	}
	printf("The answer will be %Lf\n", sum);
	return 0;
}
