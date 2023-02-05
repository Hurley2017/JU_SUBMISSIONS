#include <stdio.h>
#include <stdlib.h>
#define maxn 50
typedef struct
{
    long long acc_num, curr_bal;
    char fname[maxn], lname[maxn];
} Janata;
void target(long long *target_acc_num, long long *target_amount, int *choice);
void function1(Janata c[], int n);
void function2(Janata *c, long long target_amount, int choice);
void takeinp(Janata *c);
int main()
{
    int n, sw, choice, gotnum = 1;
    long long target_acc_num, target_amount;
    printf("Enter the number of customers.\n");
    scanf("%d", &n);
    Janata c[n];
    for(int i=0; i<n; i++)
    {
        printf("\n\nEnter the data of customer %d\n", i+1);
        takeinp(&c[i]);
    }
    system("clear");
    restart:
    printf("\n\n1)View all customers having less than 1000/- in their account.\n2)Transaction mode\n3)Clear Screen.\n4)Exit.\n\nEnter choice : ");
    scanf("%d", &sw);
    switch (sw)
    {
        case 1:
            printf("\nDisplaying all name of the customers with account balance less than 1000/- .\n");
            function1(c, n);
            goto restart;
            break;
        case 2:
            target(&target_acc_num, &target_amount, &choice);
            for(int i=0; i<n; i++)
            {
                if(c[i].acc_num == target_acc_num)
                {
                    gotnum = 0;
                    function2(&c[i], target_amount, choice);
                    break;
                }
            }
            if(gotnum == 1)
            {
                printf("Invalid account number.\n");
            }
            goto restart;
            break;
        case 3:
            system("clear");
            goto restart;
        case 4:
            return 0;
        default:
            printf("invalid input.\n");
            goto restart;
            break;
    }
    return 0;
}
void target(long long *target_acc_num, long long *target_amount, int *choice)
{
    printf("\nEnter account number : ");
    scanf("%lld", target_acc_num);
    printf("\nEnter amount : ");
    scanf("%lld", target_amount);
    printf("\nEnter choice-[0 for Withdrawal, 1 for Deposit] : ");
    scanf("%d", choice);
}
void function2(Janata *c, long long target_amount, int choice)
{
    printf("Hello %s!", c->fname);
    if(choice==0)
    {
        if(c->curr_bal >= target_amount)
        {
            c->curr_bal = c->curr_bal - target_amount;
            printf("\nTransaction Success!\nUpdated balance is %lld/-.", c->curr_bal);
        }
        else
        {
            printf("\nThe balance is insufficient for the specified withdrawal.\n");
        }
    }
    else if(choice == 1)
    {
        if(target_amount>=0)
        {
            c->curr_bal = c->curr_bal + target_amount;
            printf("\nTransaction Success!\nUpdated balance is %lld/-.", c->curr_bal);
        }
        else
        {
            printf("Deposit value cannot be negative.\n");
        }
    }
}
void function1(Janata c[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(c[i].curr_bal < 1000)
        {
            printf("%s %s\t", c[i].fname, c[i].lname);
        }
    }
}
void takeinp(Janata *c)
{
    printf("Account Holder : ");
    scanf("%s %s", c->fname, c->lname);
    printf("Account Number : ");
    scanf("%lld", &c->acc_num);
    printf("Account Balance : ");
    scanf("%lld", &c->curr_bal);
}