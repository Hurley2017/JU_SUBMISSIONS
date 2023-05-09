#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct
{
    int *data;
    int top, size;
    void init(int s)
    {
        data = (int*)malloc(sizeof(int)*size);
        top = 0;
        size = s;
    }
    void push(int element)
    {
        if(!isFull())
        {
            *(data + top++) = element;
        }
        else
        {
            printf("Stack Overflow!\n");
        }
    }
    int peek()
    {
        if(!isEmpty())
        {
            return *(data+top-1);
        }
        printf("Stack Underflow!\n");
        return INT_MAX;
    }
    int pop()
    {
        if(!isEmpty())
        {
            return *(data+--top);
        }
        printf("Stack Underflow!\n");
        return INT_MAX;
    }
    int isFull()
    {
        return top==size;
    }
    int isEmpty()
    {
        return top==0;
    }
} Stack;
void display(Stack s);
void UI_Statements();
int main()
{
    int sw, con = 1, element, size;
    Stack s1;
    while(con)
    {
        UI_Statements();
        scanf("%d", &sw);
        switch (sw)
        {
            case 1:
                printf("Enter the size of the Stack : ");
                scanf("%d", &size);
                s1.init(size);
                break;
            case 2:
                printf("Enter element to be pushed : ");
                scanf("%d", &element);
                s1.push(element);
                break;
            case 3:
                printf("The popped element is %d.\n", s1.pop());
                break;
            case 4:
                printf("The stack top is %d.\n", s1.peek());
                break;
            case 5:
                printf("Displaying the stack :");
                display(s1);
                break;
            case 6:
                system("cls");
                break;
            case 7:
                system("clear");
                break;
            case 8:
                con = 0;
                printf("Bye\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }
    return 0;
}
void UI_Statements()
{
    printf("Choose from the following : \n");
    printf("1) Create a Stack : \n");
    printf("2) Push\n");
    printf("3) Pop\n");
    printf("4) Peek\n");
    printf("5) Display the Stack\n");
    printf("6) Clear Screen (For Windows)\n");
    printf("7) Clear Screen (For Linux)\n");
    printf("8) Exit\n");
    printf("Enter your choice : ");
}
void display(Stack s)
{
    for(int i=0; i<s.top; i++)
    {
        printf("%d\t", *(s.data+i));
    }
    printf("\n");
}