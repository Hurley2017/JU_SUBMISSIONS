#include <stdio.h>
#include <math.h>
int main()
{
	int size_a, size_b;
	printf("Enter the size of the first sorted list :\n");
	scanf("%d", &size_a);
	int a[size_a];
	printf("\nEnter the elements :\n");
	for(int i=0; i<size_a; i++)
	{
		printf("Number %d : ", i+1);
		scanf("%d", &a[i]);
	}
	printf("Printing the first sorted list.\n");
	for(int i=0; i<size_a; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n\nEnter the size of the second sorted list :\n");
	scanf("%d", &size_b);
	int b[size_b];
	printf("\nEnter the elements :\n");
	for(int i=0; i<size_b; i++)
	{
		printf("Number %d : ", i+1);
		scanf("%d", &b[i]);
	}
	printf("\nPrinting the second sorted list.\n");
	for(int i=0; i<size_b; i++)
	{
		printf("%d\t", b[i]);
	}
	printf("\n");
	int size_c;
	size_c = size_a+size_b;
	int c[size_c];
	int point_a = 0, point_b = 0, point_c=0;
	while(point_c < size_c)
	{
		if(point_a < size_a && point_b < size_b)
		{
			if(a[point_a] > b[point_b])
			{
				c[point_c] = b[point_b];
				point_b = point_b + 1;
			}
			else
			{
				c[point_c] = a[point_a];
				point_a = point_a + 1;
			}
		}
		else if(point_b < size_b)
		{
			c[point_c] = b[point_b];
			point_b = point_b + 1;
		}
		else if(point_a < size_a)
		{
			c[point_c] = a[point_a];
			point_a = point_a + 1;
		}
		
		point_c = point_c + 1;
	}
	printf("\nThe resultant sorted list is : \n");
	for(int i=0; i<size_c; i++)
	{
		printf("%d\t", c[i]);
	}
	printf("\n");
	return 0;
}