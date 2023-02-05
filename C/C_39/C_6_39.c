#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define space " "
#define nline "\n"
#define read "r"
#define write "w"
#define append "a" 
#define extension ".bin"
#define rlocation "/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file3.txt"
#define wlocation "/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file4.txt"
int celement(FILE *rf);
int cnewline(FILE *rf);
void storematx(FILE **rf, int *matx);
void viewmatx(int *matx, int element);
void buildmax(int max[][2], int *matx, int element);
void viewmax(int max[][2], int newline);
void saveinfile(int max[][2], int newline);
int main()
{
    FILE *rf;
    int element, newline, *matx;
    rf = fopen(rlocation, read);
    element = celement(rf);
    rewind(rf);
    newline = cnewline(rf);
    rewind(rf);
    printf("%d %d\n", element, newline);
    matx = (int *)malloc(sizeof(int)*element);
    storematx(&rf, matx);
    printf("Printing the dynamic array : \n");
    viewmatx(matx, element);
    printf("\n");
    fclose(rf);
    int max[newline+1][2];
    buildmax(max, matx, element);
    printf("Printing the blueprint of output file  : \n");
    viewmax(max, newline+1);
    saveinfile(max, newline+1);
    printf("File Saved Successfully!\n");
    return 0;
}
void saveinfile(int max[][2], int newline)
{
    FILE *sf;
    sf = fopen(wlocation, write);
    for(int i=0; i<newline; i++)
    {
        for(int j=0; j<2; j++)
        {
            fprintf(sf, "%d", max[i][j]);
            fprintf(sf, "%s", space);
        }
        fprintf(sf, "%s", nline);
    }
    printf("\n");

}
void buildmax(int max[][2], int *matx, int element)
{
    int p = 0, sum = 0, row = 0, f = 0;  
    while(f < element)
    {
        if(*(matx+p)!=10)
        {
            sum = sum + *(matx+p) - 48;         
        }
        else
        {
            max[row][0] = row;
            max[row][1] = sum;
            row++;
            sum = 0;
        }
        p++;
        f++;
    }
    max[row][0] = row;
    max[row][1] = sum;   
}
void viewmax(int max[][2], int newline)
{
    for(int i=0; i<newline; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("%d\t", max[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void viewmatx(int *matx, int element)
{
    int pointer = 0;
    while(pointer < element)
    {
        if(*(matx + pointer) != 10)
        {
            printf("%d\t", *(matx + pointer)-48);
        }
        pointer++;  
    }
}
void storematx(FILE **rf, int *matx)
{
    int n, p = 0;
    n = getc(*rf);
    while(n != EOF)
    {
        *(matx+p) = n;
        n = getc(*rf);
        p++;
    }
}
int cnewline(FILE *rf)
{
    int n, nl = 0;
    n = getc(rf);
    while(n != EOF)
    {
        if(n == 10)
        {
            nl++;
        }
        n = getc(rf);
    }
    return nl;
}
int celement(FILE *rf)
{
    int n, element = 0;
    n = getc(rf);
    while(n != EOF)
    {
        element++;
        n = getc(rf);
    }
    return element;
}