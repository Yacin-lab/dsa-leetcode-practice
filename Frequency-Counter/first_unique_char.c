#include <stdio.h>

/*
    Function:  first_unique_char
    ---------------------------------------------------------------------------------------
    Return the index of the first character that appears only once.

    If none exists return -1.
    ---------------------------------------------------------------------------------------

*/
int first_unique_char(char *s)
{
    int FrequencyTable[256] = {0};
    unsigned char index;
    int i;

    i = 0;
    while (s[i])
    {   
        index = (unsigned char)s[i];
        FrequencyTable[index]++;
        i++;
    }

    i = 0;
    while (s[i])
    {
        index = (unsigned char)s[i];
        if (FrequencyTable[index] == 1)
        {
            return (i);
        }
        i++;
    }
    return(-1);
}

int main(int argc, char **argv)
{
    // char *s = "leetcolcodd";
    int returnValue = -1;

    if (argc == 2)
        returnValue = first_unique_char(argv[1]);
    else if (argc > 2) {
        printf("put just one string\n");
        return (0);
    }

    if (returnValue != -1)
        printf("index of the first character that appears only once is: %d\n", returnValue);
    else
        printf("none exists!\n");

    return (0);
}