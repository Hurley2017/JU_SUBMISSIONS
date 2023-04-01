#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define g 1000
void Start_Strlen();
void Start_Strcpy();
void Start_Strcat();
void Start_Strrev();
void Start_Strcmp();
void takeinp(char* f);
void copy(char* f, char* s);
void add(char*, char*);
int len(char* f);
void rev(char*);
int cmp(char*, char*);
int main()
{
	int choice;
	restart:
	printf("You can choose from the following.\n1. Strlen()\n2. Strcpy()\n3. Strcat()\n4. Strrev()\n5. Strcmp().\n6. Exit the program.\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			Start_Strlen();
			printf("\n\n");
			goto restart;
		case 2:
			Start_Strcpy();
			printf("\n\n");
			goto restart;
		case 3:
			Start_Strcat();
			printf("\n\n");
			goto restart;
		case 4:
			Start_Strrev();
			printf("\n\n");
			goto restart;
		case 5:
			Start_Strcmp();
			printf("\n\n");
			goto restart;
		case 6:
			printf("Exiting the program.\n");
			break;
		default:
			printf("Wrong selection.\n");
			printf("\n\n");
			goto restart;
	}
	return 0;
}
void takeinp(char* f)
{
	printf("Enter the string : \n");
	scanf("%s", f);
}
//DRIVER CODES
void Start_Strlen()
{
	system("clear");
	printf("Calling the Strlen() function.\n");
	char *f, arr[g];
	f = arr;
	takeinp(f);
	printf("Answer is : %d\n", len(f));
}
void Start_Strcpy()
{
	system("clear");
	printf("Calling the Strcpy() function.\n");
	char *f, *s,  arr1[g], arr2[g];
	takeinp(arr1);
	f = arr1;
	s = arr2;
	copy(f, s);
	printf("Answer is %s", arr2);
}
void Start_Strcat()
{
	system("clear");
	printf("Calling the Strcat() function.\n");
	char *f, *s, arr1[g], arr2[g];
	printf("String 1 - \n");
	takeinp(arr1);
	printf("String 2 - \n");
	takeinp(arr2);
	f = arr1;
	s = arr2;
	add(f, s);
	printf("Answer is %s\n", f);
}
void Start_Strrev()
{
	system("clear");
	printf("Calling the Strrev() function.\n");
	char *f, arr1[g];
	f = arr1;
	takeinp(f);
	rev(f);
	printf("Answer is : %s\n", f);
}
void Start_Strcmp()
{
	system("clear");
	printf("Calling the Strcmp() function.\n");
	char *f, *s, arr1[g], arr2[g];
	f = arr1;
	s = arr2;
	takeinp(f);
	takeinp(s);
	int answer = cmp(f, s);
	if(answer)
	{
		printf("Returns 1\n");
	}
	else
	{
		printf("Returns 0\n");
	}
}
//MAIN CORE FUNCTIONS
int cmp(char* f, char* s)
{
	int fl = len(f);
	int sl = len(s);
	if(fl!=sl)
	{
		return 1;
	}
	else
	{
		for(int i=0; i<fl; i++)
		{
			if(*(f+i)!=*(s+i))
			{
				return 1;
			}
		}
	}
	return 0;
}
void rev(char* f)
{
	int l = len(f);
	int c = l;
	char temp[l], *pf;
	pf = f;
	while(*f!='\0')
	{
		temp[l-1] = *f;
		f = f + 1;
		l = l - 1;
	}
	f = pf;
	for(int i=0; i<c; i++)
	{
		*(f+i) = temp[i];
	}
	*(f+c) = '\0';
}
void copy(char* f, char* s)
{
    while (*f != '\0')
    {
        *s = *f;
        s = s + 1;
        f = f + 1;
    }
    *s = '\0';
}
void add(char* f, char* s)
{
	while(*f != '\0')
	{
		f = f + 1;
	}
	*f = *s;
	s = s + 1;
	while(*s != '\0')
	{
		f = f + 1;
		*f = *s;
		s = s + 1;
	}
	f = f + 1;
	*f = '\0';
}
int len(char* f)
{
	int c = 0;
	while(*f != '\0')
	{
		c = c + 1;
		f = f + 1;
	}
	f = f - c + 1;
	return c;
}