#include <stdio.h>
#include <stdlib.h>
#define f 100
#define s 400
void gendimention(int dim[], int flag);
void readmax(int matx[f][f], int m, int n);
int pushinarr(int matx[f][f], int arr[], int m, int n, int flag);
void display(int matx[f][f], int m, int n);
void pushinmax(int matx[f][f], int m, int n, int arr[]);
void sortarr(int allarr[], int flag);
int immediatemin(int arr[], int n);
int main()
{
	int m1, n1, m2, n2, dim3[2], matx1[f][f], matx2[f][f], matx3[f][f], allarr[s], flag = 0;
	flag = 0;
	printf("\nEnter the dimention of the First 2D array : \n");
	printf("\nAssuming the dimention as MxN where,\nM = ");
	scanf("%d", &m1);
	printf("N = ");
	scanf("%d", &n1);
	printf("\nEnter the dimention of the Second 2D array : \n");
	printf("\nAssuming the dimention as MxN where, \nM = ");
	scanf("%d", &m2);
	printf("N = ");
	scanf("%d", &n2);
	printf("\nTaking input of First 2D array : \n");
	readmax(matx1, m1, n1);
	printf("\n");
	display(matx1, m1, n1);
	printf("\nTaking input of Second 2D array : \n");
	readmax(matx2, m2, n2);
	printf("\n");
	display(matx2, m2, n2);
	flag = pushinarr(matx1, allarr, m1, n1, flag);
	flag = pushinarr(matx2, allarr, m2, n2, flag);
	gendimention(dim3, flag);
	sortarr(allarr, flag);
	pushinmax(matx3, dim3[0], dim3[1], allarr);
	printf("\nThe new 2D array dimension as MxN is : %dx%d\n", dim3[0], dim3[1]);
	display(matx3, dim3[0], dim3[1]);
	return 0;
}
void sortarr(int allarr[], int flag)
{
	int temp[flag];
	for(int i=0; i<flag; i++)
	{
		temp[i] = allarr[i];
	}
	for(int i=0; i<flag; i++)
	{
		allarr[i] = immediatemin(temp, flag);
	}
}
int immediatemin(int arr[], int n)
{
	int i_min = 0, t;
	for(int i = 0; i<n; i++)
	{
		if(arr[i]<=arr[i_min])
		{
			i_min = i;
		}
	}
	t = arr[i_min];
	arr[i_min] = +12345678;
	return t;
}
void display(int matx[f][f], int m, int n)
{
	printf("Printing the 2D array : \n");
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d\t",matx[i][j]);
		}
		printf("\n");
	}	
}
void pushinmax(int matx[f][f], int m, int n, int arr[])
{
	int pointer = 0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			matx[i][j] = arr[pointer];
			pointer = pointer + 1;
		}
	}
}
void gendimention(int dim[], int flag)
{
	int temp = 12345678;
	for(int i=1; i<=flag; i++)
	{
		if(flag%i == 0)
		{
			if(abs(i - flag/i) < temp)
			{
				temp = abs(i - flag/i);
				dim[1] = flag/i;
				dim[0] = i;
			}
		}
	}
}
int pushinarr(int matx[f][f], int arr[], int m, int n, int flag)
{
	for(int i = 0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[flag] = matx[i][j];
			flag = flag + 1;
		}
	}
	return flag;
}
void readmax(int matx[f][f], int m, int n)
{
	printf("Enter Values by corrospondence : \n");
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("Enter Value of Array[%d][%d] : ", i+1, j+1);
			scanf("%d", &matx[i][j]);
		}
		printf("\n");
	}	
}
