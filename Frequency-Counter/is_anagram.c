#include <stdio.h>

/*
    Function:  is_anagram
    ---------------------------------------------------------------------------------------
    checks if two strings are anagrams.

    Two strings are anagrams if they contain the same characters with the same frequencies.
    (the same frequencies y3ni nafs tikrar characters)
    ---------------------------------------------------------------------------------------

*/
int is_anagram(char *s1, char *s2)
{
    int countChars[256] = {0};
    int i;

    /*
        STEP 1:
        Count how many times each character appears in s1
    */
    i = 0;
    while (s1[i])
    {
        // convert char to index and increment its counter
        countChars[(unsigned char)s1[i]]++;
        i++;
    }

    /*
        STEP 2:
        Compare with s2 by decreasing the counters
        if a character appears more times in s2 than s1 → not an anagram
    */
    i = 0;
    while (s2[i])
    {
        if (countChars[(unsigned char)s2[i]] <= 0)
            return (0);
        
        countChars[(unsigned char)s2[i]]--;
        i++;
    }

    /*
        STEP 3:
        ensure both strings have the same length
        if one finished earlier → not an anagram
    */
    if (s1[i] != '\0' || s2[i] != '\0')
        return (0);
    
    return (1);
}

int main(void)
{
    char s1[] = "silOents";
    char s2[] = "listesnO";

    if (is_anagram(s1, s2))
        printf("The two strings are anagrams\n");
    else
        printf("The two strings are NOT anagrams\n");

    return (0);
}