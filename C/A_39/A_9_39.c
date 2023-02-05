 #include <stdio.h>
 #include <math.h>
 int isprime(int);
 int main()
 {
 	int n;
 	printf("Give Number:\n");
 	scanf("%d", &n);
 	if(n<=2)
 	{
 		printf("No prime numbers found.\n");
 		return 0;
 	}
 	printf("All prime number between 1 to %d is : \n", n);
 	for(int i=2; i<n; i++)
 	{
 		if(isprime(i))
 		{
 			printf("%d\n", i);
 		}
 	}
 	printf("\n");
 	return 0;
 
 }
 int isprime(int x)
 {
 	for(int i=2; i<sqrt(x); i++)
 	{
 		if(x%i == 0)
 		{
 			return 0;
 		}
 	}
 	return 1;
 }
