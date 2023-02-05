#include <stdio.h>
void reversed(char *, int);
int main()
{
	printf("Give Number:\n");
	char dummy[100];
	int size;
	int answer = 0;
	int gotnum = 1;
	for(int i = 0; i<100; i++)
	{
		dummy[i] = ' ';
	}
	scanf("%s", dummy);
	char number[100];
	int point = 0;
	for(int i=0; i<100; i++)
	{
		if(dummy[i] == 48 && gotnum)
		{
			continue;
		}
		else
		{
			number[point] = dummy[i];
			point = point + 1;
			gotnum = 0;
		}
	}
	if(gotnum)
	{
		number[0] = 48;
	}
	for(int i=0; i<100; i++)
	{
		if(number[i] == 32)
		{
			size = i-1;
			break;
		}
	}
	char duplicate[size-1];
	for(int i = 0; i<=size; i++)
	{
		duplicate[i] = number[i];
	}
	reversed(duplicate, size);
	for(int i=0; i<size; i++)
	{
		if(duplicate[i] != number[i])
		{
			answer = 1;
			break;
		}
	}
	char refined[100];
	gotnum = 1;
	point = 0;
	for(int i=0; i<100; i++)
	{
		if(duplicate[i] == 48 && gotnum)
		{
			continue;
		}
		else
		{
			refined[point] = duplicate[i];
			point = point + 1;
			gotnum = 0;
		}
	}
	if(answer)
	{
		printf("%s - The number is reversed and we got %s, thus not palindrome.\n", number, refined);
	}
	else
	{
		printf("%s - The number is reversed and we got %s, thus palindrome.\n", number, refined);
	}
	return 0;
}
void reversed(char number[], int size)
{
	char answer[size-1];
	int point = 0;
	for(int i=size-1; i >=0; i--)
	{
		answer[point] = number[i];
		point = point + 1;
	}
	for(int i = 0; i<size; i++)
	{
		number[i] = answer[i];
	}
}