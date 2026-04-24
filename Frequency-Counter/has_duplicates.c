#include <stdio.h>

/*
    Function:  has_duplicates
    ---------------------------------------------------------------------------------------
    Check if a string contains any duplicated character.

    Return:
    1 → if duplicate exists
    0 → if all characters are unique
    ---------------------------------------------------------------------------------------

*/
int has_duplicates(char *s)
{
    /*
        Frequency table for all ASCII characters (including Extended ASCII Table)
        Each index represents a character
        Example: index 97 -> 'a'
        min index 0 , max index 255 -> 256 values 
    */
    int countDuplic[256] = {0};
    int index;
    
    for (int i = 0; s[i] != '\0'; i++)
    {
        /*
            Convert character to ASCII index
            unsigned char avoids negative indexes
        */
        index = (unsigned char)s[i];
        // Increase the frequency of this character
        countDuplic[index]++;

        /*
            If frequency becomes greater than 1
            it means this character appeared before
        */
        if (countDuplic[index] > 1)
        {
            return (1);
        }
    }
    
    // If loop finishes, no duplicates exist
    return (0);
}

int main(int argc, char **argv)
{
    int returnValue = -1;

    if (argc == 2)
        returnValue = has_duplicates(argv[1]);
    else if (argc > 2) {
        printf("put just one string\n");
        return (0);
    }

    if (returnValue == 0)
        printf("duplicate exists\n");
    else if (returnValue == 1)
        printf("all characters are unique\n");

    return (0);
}