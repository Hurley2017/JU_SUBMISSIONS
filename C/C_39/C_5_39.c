#include <stdio.h>
#include <stdlib.h>
#define ms 100
#define maxsize 1000
void fixstd();
typedef struct
{
    float price, acc_num, issued;
    char title[ms], author[ms];
} Library;
void disptit(Library b[maxsize], int n);
void disinp(Library b);
void takeinp(Library *b);
void sortbyauth(Library b[maxsize], int n, char* auth);
void sortbyacc(Library b[maxsize], int n);
int chechsim(char*, char*);
int main()
{
    int n, ex = 0, sw;
    char auth[ms];
    Library b[maxsize];
    printf("Enter number of books : ");
    scanf("%d", &n);
    fixstd();
    if(n != 0)
    {
        printf("\n\nReceiving inputs of %d books.\n", n);
        for(int i = 0; i<n; i++)
        {
            printf("\nBook : %d\n", i+1);
            takeinp(&b[i]);
        }
    }
    system("clear");
    restart:
    printf("\n1)Add book information.\n2)Display book information\n3)List books from the same author.\n4)List specified titles of the books.\n5)List the count of books in the library.\n6)List the books in order of accession number.\n7)Exit.\n\nEnter your choice : ");
    scanf("%d", &sw);
    fixstd();
    switch(sw)
    {
        case 1:
            printf("\nBook %d\n", n+ex+1);
            takeinp(&b[n+ex]);
            ex++;
            printf("\n");
            goto restart;
        case 2:
            printf("\nPrinting book information.\n");
            for(int i=0; i<n+ex; i++)
            {
                printf("\nBook : %d\n", i+1);
                disinp(b[i]);
                printf("\n");
            }
            goto restart;
        case 3:
            printf("\nAuthor Name : ");
            fgets(auth, ms, stdin);
            printf("\n");
            sortbyauth(b, n+ex, auth);
            goto restart;
        case 4:
            printf("\nPrinting all the titles of the books.\n");
            disptit(b, n+ex);
            printf("\n");
            goto restart;
        case 5:
            printf("\nThere are total of %d books in the library.\n\n", n+ex);
            goto restart;
        case 6:
            printf("\n");
            sortbyacc(b, n+ex);
            printf("\n");
            goto restart;
        case 7:
            return 0;
        default:
            printf("\nInvalid input - Restarting.\n");
            goto restart;
    }
    return 0;
}
void sortbyacc(Library b[maxsize], int n)
{
    int accs[n];
    for(int i=0; i<n; i++)
    {
        accs[i] = b[i].acc_num;
    }
    for(int i = 0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(accs[i] > accs[j])
            {
                int temp = accs[i];
                accs[i] = accs[j];
                accs[j] = temp;
            }
        }
    }
    for(int i = 0; i<n; i++)
    {
        printf("Book %d - \n", i+1);
        for(int j=0; i<n; j++)
        {
            if(accs[i] == b[j].acc_num)
            {
                disinp(b[j]);
                break;
            } 

        }
    }
}
void disptit(Library b[maxsize], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Book No %d Title : %s", i+1, b[i].title);
    }
}
int chechsim(char* a, char* b)
{
    int i = 0;
    while(*(a+i) != '\0' && *(b+i) != '\0')
    {
        if(*(a+i) != *(b+i))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void sortbyauth(Library b[maxsize], int n, char* auth)
{
    for(int i=0; i<n; i++)
    {
        if(chechsim(b[i].author, auth))
        {
            printf("Book : %d\n", i+1);
            disinp(b[i]);
            printf("\n");
        }
    }
}
void disinp(Library b)
{
    printf("Author : %s", b.author);
    printf("Title : %s", b.title);
    printf("Price : %f\n", b.price);
    printf("Accession Number : %f\n", b.acc_num);
    printf("Issued['0'-> Yes and '1'-> No] : %f\n", b.issued);
}
void fixstd()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}
void takeinp(Library *b)
{
    printf("Author : ");
    fgets(b->author, ms, stdin);
    printf("Title : ");
    fgets(b->title, ms, stdin);
    printf("Price : ");
    scanf("%f", &b->price);
    fixstd();
    printf("Accession Number : ");
    scanf("%f", &b->acc_num);
    fixstd();
    printf("Issued?['0'-> Yes and '1'-> No] : ");
    scanf("%f", &b->issued);
    fixstd();
}