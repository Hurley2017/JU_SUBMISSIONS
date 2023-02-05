#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int takeinp(char* country[100], char temp[100][100]);
void sort(char* country[100], int n);
int cmp(char*, char*);
int main()
{
    int n;
    char *country[100];
    char temp[100][100];
    n = takeinp(country, temp);
    sort(country, n);
    printf("The countries are sorted and displayed as : - ");
    for(int i=0; i<n; i++)
    {
        printf("\n%d) %s ", i+1, country[i]);
    }
    printf("\n");
    return 0;
}
int cmp(char* t1, char* t2)
{
    int inc = 0;
    while(*(t1+inc) != '\0' || *(t2+inc) != '\0')
    {
        if(*(t1+inc) != *(t2+inc))
        {
            if(*(t1+inc) > *(t2+inc))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        inc = inc + 1;
    }
}
int takeinp(char* country[100], char temp[100][100])
{
    int n;
    printf("Enter the number of countries : ");
    scanf("%d", &n);
    printf("Enter countries by corrospondance.\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter country %d : ", i+1);
        scanf("%s", temp[i]);
        country[i] = temp[i];
    }
    return n;
}
void sort(char* country[100], int n)
{
    int hello;
    char *temp;
    for(int i=0; i<n-1; i++)
    {
        for(int k=0; k<n-i-1; k++)
        {
            hello = cmp(country[k], country[k+1]);
            if(hello)
            {
                temp = country[k];
                country[k] = country[k+1];
                country[k+1] = temp;
            }
        }
    }
    
}

