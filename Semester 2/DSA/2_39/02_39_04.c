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
int killcamArr(int **array2d, int row, int coloumn);
int killcam(struct Clist *head, int size);
int killcamDual(struct ClistDual *head, int size);
void UI_Statements();
void execute2darray(int **array2d, int row, int coloumn, int start,  int skip);
void executeClist(struct Clist *head, int size, int start,  int skip);
int main()
{
    int people, count = 0, sw, con = 1, skip, start, survivor;
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
                printf("Configuring 2D Array Specification : \n");
                dim = getDim(people);
                printf("The specified number of people can be fitted into a 2D Array with %d x %d specification\n", *(dim), *(dim+1));
                printf("Creating 2D Array of such . . .\n");
                array2d = create2Darray(*(dim), *(dim+1));
                printf("Displaying the 2D Array : \n");
                displayArr(array2d, *(dim), *(dim+1));
                printf("Enter the starting point of execution : ");
                scanf("%d", &start);
                printf("Skip people : ");
                scanf("%d", &skip);
                execute2darray(array2d, *(dim), *(dim+1), start, skip);
                printf("After all the execution the 2D array looks like this : \n");
                survivor = killcamArr(array2d, *(dim), *(dim+1));
                printf("%d survives.\n", survivor);
                free(dim);
                break;
            case 2:
                createCirclular(head1, people);
                printf("Successfully created Circular Linked-List of such . . .\n");
                printf("Displaying the Linked-List\n");
                display(head1, people);
                printf("Enter the starting point of execution : ");
                scanf("%d", &start);
                printf("Skip people : ");
                scanf("%d", &skip);
                executeClist(head1, people, start, skip);
                survivor = killcam(head1, people);
                printf("%d survives.\n", survivor);
                break;
            case 3:
                createCirclularDual(head2, people);
                printf("Successfully created Circular Linked-List of such . . .\n");
                printf("Displaying the Linked-List\n");
                displayDual(head2, people);
                break;
            case 4:
                system("cls");
                break;
            case 5:
                system("clear");
                break;
            case 6:
                con = 0;
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}
void UI_Statements()
{
    printf("Choose the data structure to use : \n");
    printf("1) 2D Array\n");
    printf("2) A Circular Linked-List\n");
    printf("3) A Circular Doubly Linked-List\n");
    printf("4) Clear Screen (For Windows)\n");
    printf("5) Clear Screen (For Linux)\n");
    printf("6) Exit\n");
    printf("Enter Choice : ");
}
void executeClist(struct Clist *head, int size, int start,  int skip)
{
    int people_alive = size;
    int dynamic_skip = start+skip;
    while(people_alive>1)
    {
        if(head->value != 0)
        {
            if(dynamic_skip == 0)
            {
                printf("[%d]-executed\n", head->value);
                head->value = 0;
                people_alive--;
                dynamic_skip = skip;
            }
            else
            {
                dynamic_skip--;
            }
        }
        head = head->next;
    }
}
void execute2darray(int **array2d, int row, int coloumn, int start, int skip)
{
    int people_alive = row*coloumn;
    int dynamic_skip = start+skip;
    while(people_alive>1)
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<coloumn; j++)
            {
                if(dynamic_skip == 0 && array2d[i][j]!=0)
                {
                    printf("[%d]-executed\n", array2d[i][j]);
                    array2d[i][j] = 0;
                    dynamic_skip = skip;
                    people_alive--;
                }
                if(array2d[i][j] != 0)
                {
                    dynamic_skip--;
                }
            }
        }
    }
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
int killcamArr(int **array2d, int row, int coloumn)
{
    int ret;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<coloumn; j++)
        {
            if(array2d[i][j])
            {
                printf("%d\t", array2d[i][j]);
                ret = array2d[i][j];
            }
            else
            {
                printf("F\t");
            }
        }
        printf("\n");
    }
    return ret;
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
int killcam(struct Clist *head, int size)
{
    int ret;
    Clist *temp = head;
    while(size-- > 0)
    {
        if(size == 0)
        {
            if(head->value == 0)
            {
                printf("F\n");
            }
            else
            {
                ret = head->value;
                printf("%d\n", head->value);
            }
        }
        else
        {
            if(head->value == 0)
            {
                printf("F->");
            }
            else
            {
                ret = head->value;
                printf("%d->", head->value);
            }
        }
        head = head->next;
    }
    head = temp;
    return ret;
}
int killcamDual(struct ClistDual *head, int size)
{
    int ret;
    ClistDual *temp = head;
    while(size-- > 0)
    {
        if(size == 0)
        {
            if(head->value == 0)
            {
                printf("F\n");
            }
            else
            {
                ret = head->value;
                printf("%d\n", head->value);
            }
        }
        else
        {
            if(head->value == 0)
            {
                printf("F-><-");
            }
            else
            {
                ret = head->value;
                printf("%d-><-", head->value);
            }
        }
        head = head->next;
    }
    head = temp;
    return ret;
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
            printf("%d-><-", head->value);
        }
        head = head->next;
    }
    head = temp;
}