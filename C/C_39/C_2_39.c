#include <stdio.h>
#include <stdlib.h>
struct times
{
    int h;
    int m;
    int s;
};
void setzero(struct times *t);
void takeinp(struct times *t);
void displayt(struct times t);
void addtime(struct times t1, struct times t2, struct times *t3);
int main()
{
    struct times t1;
    struct times t2;
    struct times t3;
    setzero(&t1);
    setzero(&t2);
    setzero(&t3);
    printf("Enter Time 1 : \n");
    takeinp(&t1);
    printf("You entered : ");
    displayt(t1);
    printf("\nEnter Time 2 : \n");
    takeinp(&t2);
    printf("You entered : ");
    displayt(t2);
    addtime(t1, t2, &t3);
    printf("\nAfter addition time is : \n");
    displayt(t3);
}
void setzero(struct times *t)
{
    t->h = 0;
    t->m = 0;
    t->s = 0;
}
void takeinp(struct times *t)
{
    printf("Hours : ");
    scanf("%d", &t->h);
    printf("Minutes : ");
    scanf("%d", &t->m);
    printf("Seconds : ");
    scanf("%d", &t->s);
}
void displayt(struct times t)
{
    printf("%d:%d:%d\n", t.h, t.m, t.s);
}
void addtime(struct times t1, struct times t2, struct times *t3)
{
    if((t1.s+t2.s)>59)
    {
        t3->s = t3->s + t1.s + t2.s - 60;
        t3->m = t3->m + 1;
    }
    else
    {
        t3->s = t3->s + t1.s + t2.s;
    }
    if((t1.m+t2.m)>59)
    {
        t3->m = t3->m + t1.m + t2.m - 60;
        t3->h = t3->h + 1;
    }
    else
    {
        t3->m = t3->m + t1.m + t2.m;
    }
    t3->h = t3->h + t1.h + t2.h;
}
