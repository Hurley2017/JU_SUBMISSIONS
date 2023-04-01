#include <stdio.h>
void takeinp(char*);
void countandcount(char*, int*);
int main()
{
    int json[2];
    json[0] = 0;
    json[1] = 0;
    char *inp, input[10000];
    inp = input;
    takeinp(inp);
    countandcount(inp, json);
    printf("Number of articles ( a, an the, A, An, The ) is : %d\n", json[1]);
    printf("Number of words whose initial characters are in uppercase letter is : %d\n", json[0]);
}
void takeinp(char* inp)
{
    printf("Enter your paragraph:\n");
    gets(inp);
}
void countandcount(char* inp, int json[2])
{
    int pointer = 1;
    char *ch, replica[10000];
    ch = replica;
    for(int i=0; *(inp+i)!='\0' ; i++)
    {
        *(ch+i) = *(inp+i);
        *(ch+i+1) = '\0';
    }
    //Checking capital letters before loop
    if((replica[0] > 64 && replica[0] < 91))
    {
        json[0]++;
    }
    //Checking 'A' and variations before loop
    if(replica[0] == 65 || replica[0] == 97)
    {
        if(replica[1] == 32 || replica[1] == '\0')
        {
            json[1]++;
        }
    }
    //Checkign the 'An' variation before loop
    if(replica[0] == 65 || replica[0] == 97)
    {
        if(replica[1] == 78 || replica[1] == 110)
        {
            if(replica[2] == 32 || replica[2] == '\0')
            {
                json[1]++;
            }
        }
    }
    //Checking the 'The' variation before loop
    if(replica[0] == 84 || replica[0] == 116)
    {
        if(replica[1] == 72 || replica[1] == 104)
        {
            if(replica[2] == 69 || replica[2] == 101)
            {
                if(replica[3] == 32 || replica[3] == '\0')
                {
                    json[1]++;
                }
            }
        }
    }
    while(replica[pointer] != '\0')
    {
        if(replica[pointer] == 35)
        {
            break;
        }
        else
        {
            //Checking if there is any capital initial words. 
            if((replica[pointer] > 64 && replica[pointer] < 91 && (replica[pointer - 1] == 32 || replica[pointer-1] == 40)))
            {
                json[0]++;
            }
            //Checking 'A' or 'a'
            if(replica[pointer] == 65 || replica[pointer] == 97)
            {
                if((replica[pointer - 1] == 40 || replica[pointer-1] == 32) && (replica[pointer+1] == 32 || replica[pointer+1] == '\0'))
                {
                    json[1]++;
                }
            }
            //Checking 'An' and variation
            if(replica[pointer] == 65 || replica[pointer] == 97)
            {
                if(replica[pointer+1] == 78 || replica[pointer+1] == 110)
                {
                    if(replica[pointer - 1] == 32 || replica[pointer - 1] == 40)
                    {
                        if(replica[pointer+2] == 32 || replica[pointer+2] == '\0')
                        {
                            json[1]++;
                        }

                    }
                }
            }
            //Checking 'The' and variation
            if(replica[pointer] == 84 || replica[pointer] == 116)
            {
                if(replica[pointer + 1] == 72 || replica[pointer + 1] == 104)
                {
                    if(replica[pointer + 2] == 69 || replica[pointer + 2] == 101)
                    {
                        if(replica[pointer-1] == 32 || replica[pointer - 1] == 40)
                        {
                            if(replica[pointer + 3] == 32 || replica[pointer + 3] == '\0')
                            {
                                json[1]++;
                            }
                        }
                    }
                }
            }
        }
        pointer = pointer + 1;
    }
}