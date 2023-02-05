#include <stdio.h>
#define f 500
void dotranspose(int matx[f][f], int result[f][f], int n);
void readmax(int matx[f][f], int n);
void display(int matx[f][f], int n);
void matxmul(int matx[f][f], int transpose[f][f], int result[f][f], int n);
int checkortho(int result[f][f], int identity[f][f], int n);
void genidentity(int identity[f][f], int n);
int main()
{
	int m, n;
	printf("Enter the dimension of the matrix.\n");
	printf("Having NxN specification where N is : ");
	scanf("%d", &n);
	int matx[f][f], transpose[f][f], result[f][f], identity[f][f];
	readmax(matx, n);
	display(matx, n);
	printf("Showing transpose of that matrix.\n");
	dotranspose(matx, transpose, n);
	display(transpose, n);
	matxmul(matx, transpose, result, n);
	printf("Showing the multiplication of those matrix.\n");
	display(result, n);
	genidentity(identity, n);
	if(checkortho(result, identity, n))
	{
		printf("Yes, This matrix seems to be orthogonal.\n");
	}
	else
	{
		printf("This matrix is not orthogonal.\n");
	}
}
void readmax(int matx[f][f], int n)
{
	printf("Enter Values by corrospondence : \n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("Enter Value of matrix[%d][%d] : ", i+1, j+1);
			scanf("%d", &matx[i][j]);
		}
		printf("\n");
	}	
}
void display(int matx[f][f], int n)
{
	printf("Printing the matrix : \n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d\t",matx[i][j]);
		}
		printf("\n");
	}	
}
void dotranspose(int matx[f][f], int result[f][f], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			result[i][j] = matx[j][i];
		}
	}
}
void matxmul(int matx[f][f], int transpose[f][f], int result[f][f], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			result[i][j] = 0;
			for(int k=0; k<n; k++)
			{
				result[i][j] = result[i][j] + matx[i][k]*transpose[k][j];
			}
		}
	}
}
void genidentity(int identity[f][f], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j)
			{
				identity[i][j] = 1;
			}
			else
			{
				identity[i][j] = 0;
			}
		}
	}
}
int checkortho(int result[f][f], int identity[f][f], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(result[i][j] != identity[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}
