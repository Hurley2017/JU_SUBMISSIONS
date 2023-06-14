#include <stdio.h>
#include <stdlib.h>
typedef struct Slist
{
    int coefficient;
    int power;
    struct Slist *next;
} Slist;
struct Slist *init(int size);
void display(struct Slist *head);
void newline();
void UI_Statements();
struct Slist *paddition(struct Slist *poly1, struct Slist *poly2);
struct Slist *psubtraction(struct Slist *poly1, struct Slist *poly2);
struct Slist *pmultiplication(struct Slist *poly1, struct Slist *poly2);
int getSize(struct Slist *head);
struct Slist *StaticInit(int size);
int max(int A, int B);
int main()
{
    int size1, size2, sw;
    Slist *poly1, *poly2;
    Slist *addition, *subtraction, *multiplication;
    printf("Taking input for polynomial 1: ");
    newline();
    printf("Enter the degree : ");
    scanf("%d", &size1);
    poly1 = init((size1+1));
    newline();
    printf("Displaying polynomial 1 : ");
    display(poly1);
    newline();
    newline();
    printf("Taking input for polynomial 2: ");
    newline();
    printf("Enter the degree : ");
    scanf("%d", &size2);
    poly2 = init((size2+1));
    newline();
    printf("Displaying polynomial 2 : ");
    display(poly2);
    newline();
    newline();
    UI_Statements();
    while(1)
    {
        printf("Enter choice : ");
        scanf("%d", &sw);
        switch(sw)
        {
            case 1:
                newline();
                addition = paddition(poly1, poly2);
                newline();
                display(addition);
                newline();
                newline();
                break;
            case 2:
                newline();
                subtraction = psubtraction(poly1, poly2);
                newline();
                display(subtraction);
                newline();
                newline();
                break;
            case 3:
                newline();
                multiplication = pmultiplication(poly1, poly2);
                newline();
                display(multiplication);
                newline();
                newline();
                break;
            case 4:
                newline();
                system("cls");
                break;
            case 5:
                newline();
                system("clear");
                break;
            case 6:
                newline();
                return 0;
            default:
                printf("Invalid choice :");
                newline();
                newline();
                break;
        }
    }
    return 0;
}
int max(int A, int B)
{
    if(A >= B)
    {
        return A;
    }
    else
    {
        return B;
    }
}
struct Slist *pmultiplication(struct Slist *poly1, struct Slist *poly2)
{
    Slist *multiplication = StaticInit(getSize(poly1)+getSize(poly2)-1);
    Slist *Mpointer, *pointer1, *pointer2;
    pointer1 = poly1;
    pointer2 = poly2;
    Mpointer = multiplication;
    while(pointer1 != NULL)
    {
        while(Mpointer->power != pointer1->power+pointer2->power)
        {
            Mpointer = Mpointer->next;
        }
        while(pointer2 != NULL)
        {
            Mpointer->coefficient = Mpointer->coefficient + pointer1->coefficient*pointer2->coefficient;
            pointer2 = pointer2->next;
            Mpointer = Mpointer->next;
        }
        pointer2 = poly2;
        Mpointer = multiplication;
        pointer1 = pointer1->next;
    }
    return multiplication;
}
struct Slist *paddition(struct Slist *poly1, struct Slist *poly2)
{
    int newSize = max(getSize(poly1), getSize(poly2));
    int pCount = 0;
    Slist *addition = StaticInit(newSize);
    Slist *Apointer, *pointer1, *pointer2;
    Apointer = addition;
    pointer1 = poly1;
    pointer2 = poly2;
    while(Apointer != NULL)
    {
        if(poly1 != NULL && poly2 != NULL)
        {
            Apointer->coefficient = poly1->coefficient + poly2->coefficient;
            Apointer = Apointer->next;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1 == NULL && poly2 != NULL)
        {
            Apointer->coefficient = poly2->coefficient;
            Apointer = Apointer->next;
            poly2 = poly2->next;
        }
        else if(poly1 != NULL && poly2 == NULL)
        {
            Apointer->coefficient = poly1->coefficient;
            Apointer = Apointer->next;
            poly1 = poly1->next;
        }
        else if(poly2 == NULL && poly1 == NULL)
        {
            Apointer = NULL;
        }
        pCount++;
    }
    poly1 = pointer1;
    poly2 = pointer2;
    return addition;
}
struct Slist *psubtraction(struct Slist *poly1, struct Slist *poly2)
{
    int newSize = max(getSize(poly1), getSize(poly2));
    int pCount = 0;
    Slist *subtraction = StaticInit(newSize);
    Slist *Spointer, *pointer1, *pointer2;
    Spointer = subtraction;
    pointer1 = poly1;
    pointer2 = poly2;
    while(Spointer != NULL)
    {
        if(poly1 != NULL && poly2 != NULL)
        {
            Spointer->coefficient = poly1->coefficient - poly2->coefficient;
            Spointer = Spointer->next;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1 == NULL && poly2 != NULL)
        {
            Spointer->coefficient = -poly2->coefficient;
            Spointer = Spointer->next;
            poly2 = poly2->next;
        }
        else if(poly1 != NULL && poly2 == NULL)
        {
            Spointer->coefficient = -poly1->coefficient;
            Spointer = Spointer->next;
            poly1 = poly1->next;
        }
        else if(poly2 == NULL && poly1 == NULL)
        {
            Spointer = NULL;
        }
        pCount++;
    }
    poly1 = pointer1;
    poly2 = pointer2;
    return subtraction;
}
int getSize(struct Slist *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
void UI_Statements()
{
    printf("For the above polynomials, choose from the below : ");
    newline();
    printf("1. Addition");
    newline();
    printf("2. Subtraction");
    newline();
    printf("3. Multiplication");
    newline();
    printf("4. Clear Screen (For Windows)");
    newline();
    printf("5. Clear Screen (For Linux)");
    newline();
    printf("6. Exit");
    newline();
}
struct Slist *init(int size)
{
    struct Slist *head = NULL;
    struct Slist *temp = NULL;
    struct Slist *p = NULL;
    for (int i = 0; i < size; i++)
    {
        temp = (struct Slist*)malloc(sizeof(struct Slist));
        printf("Enter the coefficient of term x^%d: ", i);
        scanf("%d", &(temp->coefficient));
        temp->power = i;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}
struct Slist *StaticInit(int size)
{
    struct Slist *head = NULL;
    struct Slist *temp = NULL;
    struct Slist *p = NULL;
    for (int i = 0; i < size; i++)
    {
        temp = (struct Slist*)malloc(sizeof(struct Slist));
        temp->coefficient = 0;
        temp->power = i;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}
void display(struct Slist *head)
{
    while (head != NULL)
    {
        if(head->next == NULL)
        {
            printf("%dx^%d", head->coefficient, head->power);
        }
        else
        {
            printf("%dx^%d + ", head->coefficient, head->power);
        }
        head = head->next;
    }
}
void newline()
{
    printf("\n");
}