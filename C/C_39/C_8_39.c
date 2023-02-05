#include <stdio.h>
#include <stdlib.h>
void copy(FILE *t, FILE *d);
int main()
{
    FILE *file1, *file2;
    file1 = fopen("/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file1.txt", "r");
    file2 = fopen("/home/tusher/Desktop/Codes/MCA-Codes/C Programming/C_39/myfiles/file2.txt", "a");
    copy(file1, file2);
    fclose(file1);
    fclose(file2);
    return 0;
}
void copy(FILE *t, FILE *d)
{
    char temp;
    while(1)
    {
        temp = getc(t);
        if(temp != EOF)
        {
            putc(temp, d);
        }
        else
        {
            break;
        }  
    }
}