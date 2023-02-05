#include <stdio.h>
int main()
{
	float x;
	int y;
	int pointx = 0;
	int pointy = 0;
	float answer = 1;
	printf("First Number:\n");
	scanf("%f", &x);
	printf("Second Number:\n");
	scanf("%d", &y);
	if(x == 0 && y < 0)
	{
		printf("Answer is undefined");
		return 0;	
	}
	if(y%2!=0 && x < 0)
	{
		x = 0 - x;
		pointx = 1;
	}
	if(y < 0)
	{
		y = 0 - y;
		pointy= pointy + 1;
	}
	for(int i=1; i<=y; i++)
	{
		answer = answer*x;
	}
	if(pointx == 1)
	{
		answer = 0-answer;
	}
	if(pointy == 1)
	{
		answer = 1/answer;
	}
	
	printf("Answer is %f\n", answer);
	return 0;
}