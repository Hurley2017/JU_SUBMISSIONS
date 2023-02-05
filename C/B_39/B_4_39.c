#include <stdio.h>
#include <string.h>
void displayarr(char*, int);
void nonrecrev(char *, char *, int);
int recrev(char *, int);
int main()
{
	int n;
	printf("Enter length.\n");
	scanf("%d", &n);
	char inp[n], str1[n];
	printf("Enter the string: \n");
	scanf("%s", inp);
	printf("Using non-recursive version:\n");
	nonrecrev(inp, str1, n);
	displayarr(str1, n);
	printf("Using recursive version:\n");
	recrev(inp, n);
	printf("\n");
}
void nonrecrev(char inp[], char str[], int n)
{
	int pointer = n-1;
	for(int i=0; i<n; i++)
	{
		str[pointer] = inp[i];
		pointer = pointer - 1;
	}
}
void displayarr(char arr[], int n)
{
	int pointer = 0;
	while(pointer < n)
	{
		printf("%c", arr[pointer]);
		pointer = pointer + 1;
	}
	printf("\n");
}
int recrev(char inp[], int n)
{
	if(n == 0)
	{
		return 0;
	}
	else
	{
		printf("%c", inp[n-1]);
	}
	recrev(inp, n-1);
}

