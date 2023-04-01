#include <stdio.h>
#include <stdlib.h>
void copyUpper(FILE *t, FILE *d);
char convertUpper(char c);
int main()
{
    FILE *file1, *file2;
    file1 = fopen("/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file1.txt", "r");
    file2 = fopen("/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file2.txt", "w");
    copyUpper(file1, file2);
    fclose(file1);
    fclose(file2);
    return 0;
}
void copyUpper(FILE *t, FILE *d)
{
    char temp;
    while(1)
    {
        temp = getc(t);
        if(temp != EOF)
        {
            if(temp >=97 && temp <=122)
            {
                putc(convertUpper(temp), d);
            }
            else
            {
                putc(temp, d);
            }
        }
        else
        {
            break;
        }  
    }
}
char convertUpper(char c)
{
    return (c-32);
}