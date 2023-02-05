#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long double fibfor(int);
long double myrec(int, long double *);
long double fibrec(int);
int main()
{
	int n;
	printf("Give Number:\n");
	scanf("%d", &n);
	long double formula, dp, answer;
	formula = fibfor(n);
	dp = fibrec(n);
	printf("After running the program following the formula given : \n");
	printf("The answer comes up as %Lf.\n", formula);
	printf("After running the program dynamically with memoization : \n");
	printf("The answer comes up as %Lf.\n", dp);
	answer = dp-formula;
	if(answer < 0)
	{
		answer = 0 - answer;
	}
	printf("The difference of answers between both of those approches is %Lf.\n", answer);
}
long double fibfor(int n)
{
	long double A, B, C;
	long double answer;
	A = 1/pow(5, 0.5);
	B = 1+pow(5, 0.5);
	C = 1-pow(5, 0.5);
	answer = A*((pow(B,n)-pow(C,n))/pow(2,n));
	return answer;
}
long double fibrec(int n)
{
	long double arr[n];
	long double answer;
	for(int i=0; i<n; i++)
	{
		arr[i] = 0;
	}
	answer = myrec(n, arr);
	return answer;
}
long double myrec(int f, long double arr[])
{
	if(f==0)
	{
		return 0;
	}
	else if(f==1)
	{
		return 1;
	}
	else
	{
		if(arr[f-1]==0)
		{
			arr[f-1] = myrec(f-1,arr)+myrec(f-2,arr);
		}
		return arr[f-1];
	}	
}