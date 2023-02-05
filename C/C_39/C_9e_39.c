#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define rb "rb"
#define wb "wb"
#define ab "ab"
#define space " "
#define slash "/"
#define maxs 200
#define maxrecords 1000
#define maxn 50
#define empty ""
#define nl "\n"
#define wlocation "myfiles/filex.bin"
typedef struct
{
    char fname[maxn], lname[maxn];
    int Roll_Number, bday, bmonth, byear, dump;
    float marks;
} Student;
void takeinp(Student *s);
void gracify(Student *s);
void storeData(FILE *loc, Student s[], int n);
void store(FILE *loc, Student s);
void dumpify(Student *s);
void fixstd();
int main()
{
    int n, sw, ex = 0, ign, rm, df = 1;
    FILE *loc; 
    printf("Number of Students.\n");
    scanf("%d", &n);
    fixstd();
    Student s[maxrecords];
    if(n != 0)
    {
        printf("Taking input of %d students one by one!\n", n);
        for(int i=0; i<n; i++)
        {
            printf("\nReceiving data of Student Number %d\n", i+1);
            takeinp(&s[i]);
        }
        for(int i=0; i<n; i++)
        {
            if(s[i].marks <50 && s[i].marks > 40)
            {
                gracify(&s[i]);
            }
        }
        printf("Hi");
    }
    loc = fopen(wlocation, wb);
    storeData(loc, s, n);
    fclose(loc);
    system("clear");
    restart:
    printf("\nChoose from the following\n1) Add a new record\n2) Delete a record.\n3) Exit.\n\nEnter choice : ");
    scanf("%d", &sw);
    switch(sw)
    {
        case 1:
            printf("\n");
            printf(" ----------------- New record -----------------\n");
            loc = fopen(wlocation, ab);
            takeinp(&s[n+ex]);
            if(s[n+ex].marks <50 && s[n+ex].marks > 40)
            {
                gracify(&s[n+ex]);
            }
            store(loc, s[n+ex]);
            fclose(loc);
            ex++;
            goto restart;
        case 2:
            printf("\n");
            printf(" ----------------- Delete record ----------------- \n");
            printf("Roll number : ");
            scanf("%d", &rm);
            for(int i=0; i<n+ex; i++)
            {
                if(s[i].Roll_Number == rm && s[i].dump == 0)
                {
                    df = 0;
                    dumpify(&s[i]);
                    break;
                }
            }
            if(df == 1)
            {
                printf("Record not found!\n");
            }
            else
            {
                loc = fopen(wlocation, wb);
                storeData(loc, s, n+ex);
                fclose(loc);
                printf("Record deleted successfully!\n");
                df = 1;
            }
            goto restart;
        case 3:
            return 0;   
        default:
            printf("Invalid input.\nRestarting.\n");
            goto restart;
    }
    return 0;
}
void fixstd()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void dumpify(Student *s)
{
    s->dump = 1;
}
void storeData(FILE *loc, Student s[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(s[i].dump != 1)
        {
            store(loc, s[i]);
        }
    }
}
void store(FILE *loc, Student s)
{
    char tempc[maxn];
    char statement[maxs];
    sprintf(statement, "%d", s.Roll_Number);
    strcat(statement, space);
    strcat(statement, s.fname);
    strcat(statement, space);
    strcat(statement, s.lname);
    strcat(statement, space);
    sprintf(tempc, "%d", s.bday);
    strcat(statement, tempc);
    strcat(statement, slash);
    sprintf(tempc, "%d", s.bmonth);
    strcat(statement, tempc);
    strcat(statement, slash);
    sprintf(tempc, "%d", s.byear);
    strcat(statement, tempc);
    strcat(statement, space);
    sprintf(tempc, "%f", s.marks);
    strcat(statement, tempc);
    strcat(statement, nl);
    fprintf(loc, "%s", statement);
    strcpy(statement, empty);
    strcpy(tempc, empty);
}
void gracify(Student *s)
{
    s->marks = s->marks + 10;
}
void takeinp(Student *s)
{
    printf("Enter full name : ");
    scanf("%s %s", s->fname, s->lname);
    printf("Enter Roll Number : ");
    scanf("%d", &s->Roll_Number);
    printf("Enter birthday : ");
    scanf("%d %d %d", &s->bday, &s->bmonth, &s->byear);
    printf("Enter marks : ");
    scanf("%f", &s->marks);
    s->dump = 0;
}