#include <stdio.h>
long myfunc(long n, long prefix, long suffix)
{
    if(n==1)
	{
		return n;
    }
    for(long i=1; i <= n; i++)
	{
		if(prefix==suffix)
		{
			return i;
		}
        prefix += i;
		suffix -= (i + 1);
		
	}
    return -1;
}
long calcsum(long low, long up)
{
	long sum = 0;
	for(long i=low; i <= up; i++)
	{
		sum = sum + i;
	}
	return sum;
}
int main()
{
	long n;
	long left = 0;
	printf("Enter total rooms:\n");
	scanf("%ld", &n);
	long right = calcsum(2, n);
    long hotel = myfunc(n, left, right);
    if(hotel == -1)
    {
        printf("Does not exist\n");
    }
    else
    {
        printf("Hotel room no: %ld\n", hotel);
    }
	return 0;
}
