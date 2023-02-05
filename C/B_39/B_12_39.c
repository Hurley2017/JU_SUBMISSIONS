#include <stdio.h>
#define f 1000
int inig(int ig[f], int element);
void initzero(int arr[f]);
int getlen(int val[f]);
void ins(int val[f]);
void del(int val[f], int ig[f]);
void print(int val[f], int ig[f]);
void search(int val[f], int ig[f]);
int main()
{
    int n, sw, val[f], ig[f];
    initzero(val);
    initzero(ig);
    printf("Enter the number of elements in the linked list.\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        if(i == 0)
        {
            printf("Enter Head : ");
            scanf("%d", &val[i]);
        }
        else
        {
            printf("Enter element after %d : ", val[i-1]);
            scanf("%d", &val[i]);
        }
    }
    restart:
    printf("1) Insert a new node\n2) Delete a node specified by the user\n3) Print the list\n4) Search and element in the list\n5) Exit\nEnter your choice : ");
    scanf("%d",&sw);
    switch (sw)
    {
        case 1:
            ins(val);
            goto restart;
        case 2:
            del(val, ig);
            goto restart;
            break;
        case 3:
            print(val, ig);
            goto restart;
        case 4:
            search(val, ig);
            goto restart;
        case 5:
            return 0;
        default:
            printf("Wrong selection\n");
            break;
    }
}
int inig(int ig[f], int element)
{
    for(int i = 0; i<getlen(ig); i++)
    {
        if(ig[i] == element)
        {
            return 1;
        }
    }
    return 0;
}
void initzero(int arr[f])
{
    for(int i=0; i<f; i++)
    {
        arr[i] = -69696969;
    }
}
int getlen(int val[f])
{
    int answer = 0;
    while(val[answer] != -69696969)
    {
        answer = answer + 1;
    }
    return answer;
}
void ins(int val[f])
{
    int element;
    printf("Enter element : ");
    scanf("%d", &element);
    val[getlen(val)] = element;
}
void del(int val[f], int ig[f])
{
    int element;
    int gotnum = 1;
    printf("Enter element to delete : ");
    scanf("%d", &element);
    for(int i = 0; i<getlen(val); i++)
    {
        if(val[i] == element)
        {
            gotnum = 0;
        }
    }
    if(gotnum)
    {
        printf("No such element to delete.\n");
    }
    else
    {
        ig[getlen(ig)] = element;
    }
}
void print(int val[f], int ig[f])
{
    for(int i=0; i<getlen(val); i++)
    {
        if(inig(ig, val[i]))
        {
            continue;
        }
        else
        {
            printf("%d, ", val[i]);
        }
    }
    printf("\n");
}
void search(int val[f], int ig[f])
{
    int element;
    int toskip = 0;
    int flag = 1;
    printf("Enter element to search : ");
    scanf("%d", &element);
    for(int i=0; i<getlen(val); i++)
    {
        if(inig(ig, val[i]))
        {
            toskip = toskip + 1; 
            continue;
        }
        else
        {
            if(val[i] == element)
            {
                flag = 0;
                printf("The element is : %d and found in position %d\n", val[i], (i-toskip));
            }
        }
    }
    if(flag)
    {
        printf("Element not found.\n");
    }
}