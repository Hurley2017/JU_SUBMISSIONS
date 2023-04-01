#include <stdio.h>  
#include <stdlib.h>
#define maxn 50
#define maxs 5
typedef struct
{
    char fname[maxn], lname[maxn];
    int Roll_Number;
    float total, Sub[maxs], avg;
} Student;
void displayOrder(Student s[], int *roll, int n);
void odolbodol(float* total, int *roll, int i, int j);
void driverInp(Student s[], int *roll, float *total, int n);
void driverPrint(int *roll, float *total, int n);
void driverDisplay(Student s[], int n);
void takeinp(Student *s);
void disp(Student s);
void driverSort(int *roll, float *total, int n);
int main()
{
    int n, *roll;
    float *total;
    printf("Number of Students : ");
    scanf("%d", &n);
    roll = (int *)malloc(sizeof(int)*n);
    total = (float *)malloc(sizeof(float)*n);
    Student s[n];
    printf("Taking input of %d students one by one!\n", n);
    for(int i=0; i<n; i++)
    {
        printf("\nReceiving data of Student Number %d", i+1);
        takeinp(&s[i]);
    }
    driverInp(s, roll, total, n);
    printf("\nDisplaying output of %d students one by one!\n", n);
    driverDisplay(s, n);
    driverSort(roll, total, n);
    printf("\nDisplaying Students names considering their total marks in descending order!\n");
    displayOrder(s, roll, n);
    return 0;
}
void displayOrder(Student s[], int *roll, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(s[j].Roll_Number == *(roll+i))
            {
                printf("%s %s\t", s[j].fname, s[j].lname);
                break;
            }
        }
    }
    printf("\n");
}
void driverSort(int *roll, float *total, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(*(total+i)<*(total+j))
            {
                odolbodol(total, roll, i, j);
            }
        }
    }
}
void odolbodol(float* total, int *roll, int i, int j)
{
    int temp1 = *(roll + i);
    *(roll + i) = *(roll + j);
    *(roll + j) = temp1;
    float temp2 = *(total + i);
    *(total + i) = *(total + j);
    *(total + j) = temp2;
}
void driverInp(Student s[], int *roll, float *total, int n)
{
    for(int i=0; i<n; i++)
    {
        *(roll+i) = s[i].Roll_Number;
        *(total+i) = s[i].total;
    }
}
void driverPrint(int *roll, float *total, int n)
{
    printf("\nRoll Numbers - ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", *(roll + i));
    }
    printf("\nTotal Numbers - ");
    for(int i=0; i<n; i++)
    {
        printf("%f ", *(total + i));
    }
}
void driverDisplay(Student s[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\nStudent Number %d - ", i+1);
        disp(s[i]);
    }
}
void disp(Student s)
{
    printf("\nFull Name : %s %s", s.fname, s.lname);
    printf("\nRoll : %d\n", s.Roll_Number);
    printf("Average marks : %f\n", s.avg);
    printf("Total marks : %f\n", s.total);
}
void takeinp(Student *s)
{
    s->total = 0;
    printf("\nEnter full name : ");
    scanf("%s %s", s->fname, s->lname);
    printf("Enter Roll Number : ");
    scanf("%d", &s->Roll_Number);
    for(int i=0; i<5; i++)
    {
        printf("Enter marks %i : ", i+1);
        scanf("%f", &s->Sub[i]);
        s->total = s->total + s->Sub[i];
    }
    s->avg = s->total/5.0;
}
