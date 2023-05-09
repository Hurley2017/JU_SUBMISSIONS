#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Clist
{
    int value;
    struct Clist *next;
} Clist;
typedef struct ClistDual
{
    int value;
    struct ClistDual *previous;
    struct ClistDual *next;
} ClistDual;
void createCirclular(struct Clist *head,  int size);
void display(struct Clist *head, int size);
void createCirclularDual(struct ClistDual *head,  int size);
void displayDual(struct ClistDual *head, int size);
int  *getDim(int size);
int** create2Darray(int row, int coloumn);
void displayArr(int **array2d, int row, int coloumn);
void UI_Statements();
int main()
{
    int people, count = 0, sw, con = 1;
    int *dim, **array2d;
    Clist *head1 = (Clist*)malloc(sizeof(Clist));
    ClistDual *head2 = (ClistDual*)malloc(sizeof(ClistDual));
    printf("Enter the number of people : ");
    scanf("%d", &people);
    while(con)
    {
        UI_Statements();
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                printf("Configuring 2D Array Specification : ");
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                con = 0;
                break;
            default:
                break;
        }
    }
    // dim = getDim(people);
    // printf("%d x %d\n", *(dim), *(dim+1));
    // array2d = create2Darray(*(dim), *(dim+1));
    // displayArr(array2d, *(dim), *(dim+1));
    // createCirclular(head1, people);
    // display(head1, people);
    // createCirclularDual(head2, people);
    // displayDual(head2, people);
    // free(dim);
    return 0;
}
void UI_Statements()
{
    printf("Choose the data structure to use : \n");
    printf("1) 2D Array\n");
    printf("2) A Circular Linked-List\n");
    printf("3) A Circular Doubly Linked-List\n");
    printf("4) Clear Screen (For Windows)");
    printf("5) Clear Screen (For Linux)");
    printf("6) Exit");
    printf("Enter Choice : ");
}
void displayArr(int **array2d, int row, int coloumn)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<coloumn; j++)
        {
            printf("%d\t", array2d[i][j]);
        }
        printf("\n");
    }
}
int** create2Darray(int row, int coloumn)
{
    int **array2d;
    int naming = 1;
    array2d = (int**)malloc(row*sizeof(int*));
    for(int i=0; i<row; i++)
    {
        *(array2d+i) = (int*)malloc(coloumn*sizeof(int));
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<coloumn; j++)
        {
            array2d[i][j] = naming;
            naming++;
        }
    }
    return array2d;
}
int *getDim(int size)
{
    int *dim = (int*)malloc(sizeof(int)*2);
    for(int i=1; i<sqrt(size)+1; i++)
    {
        if(size%i == 0)
        {
            *(dim) = i;
            *(dim+1) = size/i;
        }
    }
    return dim;
}
void display(struct Clist *head, int size)
{
    Clist *temp = head;
    while(size-- > 0)
    {
        if(size == 0)
        {
            printf("%d\n", head->value);
        }
        else
        {
            printf("%d->", head->value);
        }
        head = head->next;
    }
    head = temp;
}
void createCirclular(struct Clist *head, int size)
{
    int naming = 1;
    head->value = naming;
    naming++;
    Clist *temp = head;
    for(int i=0; i<size-1; i++)
    {
        Clist *new = (Clist*)malloc(sizeof(Clist));
        temp->next = new;
        temp = temp->next;
        temp->value = naming;
        naming++;
    }
    temp->next = head;
}
void createCirclularDual(struct ClistDual *head, int size)
{
    int naming = 1;
    head->value = naming;
    naming++;
    ClistDual *temp = head;
    for(int i=0; i<size-1; i++)
    {
        ClistDual *prev;
        ClistDual *new = (ClistDual*)malloc(sizeof(ClistDual));
        temp->next = new;
        prev = temp;
        temp = temp->next;
        temp->previous = prev;
        temp->value = naming;
        naming++;
    }
    temp->next = head;
    head->previous = temp;
}
void displayDual(struct ClistDual *head, int size)
{
    ClistDual *temp = head;
    while(size-- > 0)
    {
        if(size == 0)
        {
            printf("%d\n", head->value);
        }
        else
        {
            printf("%d->", head->value);
        }
        head = head->next;
    }
    head = temp;
}