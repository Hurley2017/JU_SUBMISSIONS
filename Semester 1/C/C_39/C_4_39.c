#include <stdio.h>
#include <stdlib.h>
typedef struct dates
{
    int dd;
    int mm;
    int yy;
} Dates;
void takeinp(Dates *t);
void displayt(Dates t);
int cmptime(Dates t1, Dates t2);
int main()
{
    int flag = 0;
    Dates d1, d2;
    printf("Enter Date 1 : \n");
    takeinp(&d1);
    printf("You entered : ");
    displayt(d1);
    printf("\nEnter Date 2 : \n");
    takeinp(&d2);
    printf("You entered : ");
    displayt(d2);
    flag = cmptime(d1, d2);
    if (flag)
    {
        printf("Those dates are same!\n");
        return 0;
    }
    else
    {
        printf("Those dates are not same!\n");
        return 0;
    }
}
void takeinp(Dates *t)
{
    printf("Days : ");
    scanf("%d", &t->dd);
    printf("Months : ");
    scanf("%d", &t->mm);
    printf("Year : ");
    scanf("%d", &t->yy);
}
void displayt(Dates t)
{
    printf("%d/%d/%d\n", t.dd, t.mm, t.yy);
}
int cmptime(Dates t1, Dates t2)
{
    return (t1.dd == t2.dd) && (t1.mm == t2.mm) && (t1.yy == t2.yy);
}
