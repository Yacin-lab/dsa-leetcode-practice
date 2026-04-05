#include <stdio.h>
/*
    Function: maximumNumberOfVowels
    -------------------------------
    Returns the maximum number of vowels in any substring
    of lenght k

    Idea:
    Use Sliding Window technique.

    1. Compute the maximum nbr of vowels in the first window
    2. 
*/
int maximumNumberOfVowels(char* s, int k) {
    int count = 0;
    int index;

    for(int i = 0; i < k; i++) {
        if(s[i] == 'a' || s[i] == 'u' 
        || s[i] == 'o' || s[i] == 'e' 
        || s[i] == 'i')
            count++;
    }

    int maxCount = count;
    count = 0;
    int left = 0;
    int right = k;
    while(s[right] != '\0') { 
        count = 0;
        for(int i = left; i < right; i++) {
            if(s[i] == 'a' || s[i] == 'u' 
            || s[i] == 'o' || s[i] == 'e' 
            || s[i] == 'i')
                count++;
            // track maixumum
        }
        left++;
        right++;
    }
}

int main(void) {
    char arr[] = "abciiidef";
	int k = 3;

	maximumNumberOfVowels(arr, k);

    return (0);
}