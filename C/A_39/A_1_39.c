#include <stdio.h>
int main()
{
	float choice;
	float n;
	printf("Enter 1 to convert F to C or Enter 0 to convert C to F\n");
	scanf("%f", &choice);
	if(choice==1)
	{ 
		float answer;
		printf("Enter the Farenheit Value:\n");
		scanf("%f", &n);
		answer = (n-32)/1.8;
		printf("The converted Celcius value is %f deg C.\n", answer);
	}
	else if(choice==0)
	{
		float answer;
		printf("Enter the Celcius Value:\n");
		scanf("%f", &n);
		answer = (n*1.8)+32;
		printf("The converted Farenheit value is %f deg F.\n", answer);
	}
	else
	{
		printf("Enter a valid input.\n");	
	}
	return 0;
}