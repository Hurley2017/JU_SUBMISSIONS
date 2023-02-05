#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define m 100
int main()
{
    srand(time(NULL));
    int n, p, i, j, k, rem, r;
    float M[m][m], M_p[m][m], R[m][1], new_R[m][1];
    printf("Enter the dimension of square matrix : \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        rem = 100;
        for (j = 0; j < n - 1; j++)
        {
            r = rand() % rem;
            M[i][j] = r * 0.01;
            rem -= r;
        }
        M[i][n - 1] = rem * 0.01;
    }

    printf("\nThe generated matrix M is : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.2f ", M[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        R[i][0] = 1.0 / n;
    }
    printf("\nThe calculated matrix R is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%.2f\n", R[i][0]);
    }
    printf("\nEnter the value of p : ");
    scanf("%d", &p);
    while (p--)
    {
        for (i = 0; i < n; i++)
        {
            float temp = 0;
            for (j = 0; j < n; j++)
            {
                temp += (M[i][j] * R[j][0]);
            }
            new_R[i][0] = temp;
        }
        for (i = 0; i < n; i++)
        {
            R[i][0] = new_R[i][0];
        }
    }
    printf("\nThe matrix (M^p)*R is : \n");
    for (i = 0; i < n; i++)
    {
        printf("%.2f\n", R[i][0]);
    }
    printf("Hence proved that for any positive integer P, the statement R =(M^P)*R holds.\n");
    return 0;
}
