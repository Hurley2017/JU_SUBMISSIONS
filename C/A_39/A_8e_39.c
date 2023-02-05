#include <stdio.h>
int isprime(int);
int main()
{
 	long n, sum = 0, first = 0, second = 0, pointer = 0, i = 2;
 	printf("Give Number :\n");
 	scanf("%ld", &n);
 	while(pointer < n)
 	{
 		if(first != 0 && second != 0)
 		{
 			sum = sum + first*second;
 			first = second;
 			second = 0;
 			pointer = pointer + 1;
 		}
 		else if(isprime(i))
 		{
 			if(first == 0)
 			{
 				first = i;
 			}
 			else
 			{
 				second = i;
 			}
 		}
 		i++;
 	}
 	printf("The answer would be : %ld\n", sum);
 	return 0;
}
int isprime(int n)
{
	for(int i = 1; i <= n/2; i++)
	{
		if(n%i==0 && i != 1)
		{
			return 0;
		}
	}
	return 1;
}