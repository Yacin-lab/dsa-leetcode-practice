#include <stdio.h>

void print_frequency(char *s)
{
    int freq[256] = {0};
    int maxChar;
    int maxCount;
    int i;

    /* build frequency table */
    for (int c = 0; s[c]; c++)
        freq[(unsigned char)s[c]]++;

    while (1)
    {
        i = 0;
        maxCount = 0;
        /* search maxCount frequency */
        while (i < 256)
        {
            if (freq[i] > maxCount)
            {
                maxCount = freq[i];
                maxChar = i;
            }
            i++;
        }
        if (maxCount == 0)
            break;
        
        printf("%c : %d\n", maxChar, maxCount);

        /* remove it so next max appears */
        freq[maxChar] = 0;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        print_frequency(argv[1]);
    }
    else
    {
        printf("put one argement!\n");
    }

    return (0);
}