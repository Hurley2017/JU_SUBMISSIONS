#include <stdio.h>
#include <stdlib.h>
void takeinp(char*);
int checkup(char*, char*);
int main()
{
    int n1, n2, con;
    char *str1, *str2;
    printf("Enter the size of the first String.\n");
    scanf("%d", &n1);
    str1 = (char*)malloc(n1*sizeof(char));
    takeinp(str1);
    printf("Enter the size of the second String.\n");
    scanf("%d", &n1);
    str2 = (char*)malloc(n2*sizeof(char));
    takeinp(str2);
    con = checkup(str1, str2);
    free(str1);
    free(str2);
    printf("return %d\n", con);
}
void takeinp(char* str)
{
    printf("Enter String : ");
    scanf("%s", str);
}
int checkup(char* str1, char* str2)
{
    int pointer1 = 0, pointer2 = 0;
    back:
    while(*str2 != *(str1+pointer1))
    {
        pointer1 = pointer1 + 1;
        if(*(str1+pointer1) == '\0')
        {
            return 0;
        }
    }
    while(*(str1+pointer1+pointer2) == *(str2+pointer2))
    {
        pointer2 = pointer2 + 1;
        if(*(str2+pointer2) == '\0')
        {
            return pointer1;
        }
    }
    pointer1 = pointer1 + 1;
    goto back;
}
