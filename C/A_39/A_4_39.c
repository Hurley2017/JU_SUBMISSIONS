#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20
char *numberToWordsIN(int);
char *convertToWords(long long n, char *out);
char *numberToWords(int, char*, char*, int);
char *one[] = { "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ","Nine ", "Ten ", "Eleven ", "Twelve ","Thirteen ", "Fourteen ", "Fifteen ","Sixteen ", "Seventeen ", "Eighteen ","Nineteen " };
char *teens[] = {"","Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
char *tens[] = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
char *ones[] ={"","One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
char *ten[] = { "", "", "Twenty ", "Thirty ", "Forty ","Fifty ", "Sixty ", "Seventy ", "Eighty ","Ninety "};
char *places[] ={"Hundred ", "Thousand ", "Million ", "Billion "};
char *places2[] ={"Hundred ", "Thousand ", "Lakh ", "Crore "};
int main()
{
    long long number;
    char str[100] = {0};
    printf("Enter Number :\n");
    scanf("%lld", &number);
    if(number > 99999999)
    {
    		printf("Nor allowed.\n");
    		return 0;
    }
    printf("\nYour answer is %s in International format.\n", numberToWordsIN(number));
    if(number == 0)
    {
    		printf("\nYour answer is Zero in Indian format.\n");
    }
    else
    {	
    		printf("\nYour answer is %s in Indian format.\n", convertToWords(number, str));
    }
    return 0;
}
char *numberToWordsIN(int n)
{
    
    if(n == 0)
    {
        return "Zero";
    }
    int d = 0, d1 = 0, d2 =0, level = 0, isTeens = 0;
    char **storedBreaks = calloc (4, sizeof (char *));
    for(d = 0; d<4; d++)
    {
        storedBreaks[d] = calloc (50, sizeof(char));
    }
    while(n)
    {
        if(n % 100 < 20 && n % 100 > 10)
        {
            isTeens = 1;
        }  
        d = n%10;
        n = n/10;
        d1 = n%10;
        n = n/10;
        d2 = n%10;
        n = n/10;
        if(d2)
        {
            strcat(storedBreaks[level], ones[d2]);
            strcat(storedBreaks[level], places[0]);
        }
        if(isTeens)
        {
            isTeens = 0;
            strcat(storedBreaks[level], teens[d]);
            if(level)
            {
                strcat(storedBreaks[level], places[level]);
            }
            level ++;
            continue;
        }
        else
        {
            if(d1)
            {
                strcat(storedBreaks[level], tens[d1]);
            }    
            if(d)
            {
                strcat(storedBreaks[level], ones[d]); 
            }             
        }
        if(level && (d || d1 || d2))
        {
            strcat(storedBreaks[level], places[level]);
        }       
        level++;
    }
    char *retVal = calloc(200, sizeof(char));
    for(d = 3; d >= 0; d--)
    {
        strcat(retVal, storedBreaks[d]);
    }
    for(d = 0; d <3; d++)
    {
        free(storedBreaks[d]);
    }
    free(storedBreaks);
    if(retVal[strlen(retVal) - 1] == ' ')
    {
        retVal[strlen(retVal)-1] ='\0';
    }   
    return retVal;
}

char *numberToWords(int n, char* s, char *str, int len)
{
    memset(str,0,len);
    if(n > 19)
    {
        strcat(str,ten[n / 10]);
        strcat(str,one[n % 10]);
    }
    else
    {
        strcat(str,one[n]);
    }
    if(n)
    {
        strcat(str,s);
    }
    return str;
}
char *convertToWords(long long n, char *out)
{
    char str[SIZE] = {0};
    strcat(out, numberToWords((n / 10000000), "Crore ",str,SIZE));
    strcat(out, numberToWords(((n / 100000) % 100), "Lakh ",str,SIZE));
    strcat(out, numberToWords(((n / 1000) % 100), "Thousand ",str,SIZE));
    strcat(out, numberToWords(((n / 100) % 10), "Hundred ",str,SIZE));
    strcat(out, numberToWords((n % 100), "",str,SIZE));
    return out;
}
