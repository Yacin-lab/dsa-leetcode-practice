#include <stdio.h>

/*
    Function: maximumNumberOfVowels
    -------------------------------
    Returns the maximum number of vowels in any substring
    of lenght k

    Idea:
    Use Sliding Window technique.

    1. Compute the maximum nbr of vowels in the first window
    2. Check leaving and entering element:
        if entering == vowels -> increment +1
        if leaving == vowels -> decrement -1
    3. Update maxCount
*/

int isVowels(char c) {
    return (c == 'a' || c == 'u' || 
            c == 'o' || c == 'e' || 
            c == 'i');
}

int maximumNumberOfVowels(char* s, int k) {
    int left;
    int right;
    int countVowels = 0;

    // first window
    for(int i = 0; i < k; i++) {
        if(isVowels(s[i]))
            countVowels++;
    }

    int maxCount = countVowels;
    
    // Fixed slide window
    right = k;
    while(s[right] != '\0') {

        // jouj elements li kayhmoni --> li 3ad khrej w 3ad dkhl lwindow
        // ila kan li khrej vowles --> n9as mn CountVowels -1
        left = right - k;
        if (isVowels(s[left]))
            countVowels--;

        // ila kan li dkhel vowles zid l CountVowels +1
        if (isVowels(s[right]))
            countVowels++;

        // update maxCount
        if (countVowels > maxCount)
            maxCount = countVowels;

        right++;
    }
    return (maxCount);
}

int main(void) {
    char arr[] = "abciiidef";
	int k = 3;

	printf("%d\n", maximumNumberOfVowels(arr, k));

    return (0);
}