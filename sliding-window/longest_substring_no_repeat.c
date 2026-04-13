#include <stdio.h>

/*
    Function: longestSubstringNoRepeat
    --------------------------------
    Return the length of the longest substring that contains
    NO repeating characters.

    Idea:

    Window represented by:
        [left ........ right]

    right  -> expands the window
    left   -> shrinks the window when duplicates appear

    We maintain a frequency table (seen[256]) to know
    whether a character already exists inside the window.

    Steps:

    1. Move right pointer to include a new character.
    2. If that character already exists in the window:
        shrink the window from the left
        until the duplicate disappears.
    3. Update the maximum window size.
*/
int longestSubstringNoRepeat(char* str) {
    /*
        ASCII frequency table.

        Index  = character value
        Value  = how many times this char appears in window

        We initialize with 0 so we don't read garbage memory.
        256 7it range dyal unsigned char 0 -> 255 y3ni 256 possible char values
        w bach nghati 7ta Extended ASCII
    */
    int seen[256] = {0};

    int left = 0;
    int right = 0;

	int windowSize;
	int maxSize = 0;

	while (str[right]) {
        /*
            If the current character already exists
            in the window we have a duplicate.

            Example:
                window = "abc"
                next char = 'a'

            We must shrink the window from the left
            until the duplicate 'a' disappears.
        */
        while (seen[(unsigned char)str[right]] == 1) {
            /*
                Remove the leftmost character
                from the window.

                Example:
                    window = "abca"
                    remove 'a'
                    move left forward
            */
            seen[(unsigned char)str[left]]--;
            left++;
        }
        
        /*
            Now the character is safe to add to the window.
            Mark current char as seen.
            Convert the letter to an index in hash table
        */
        seen[(unsigned char)str[right]] = 1;

        /*
            update max length
        */
        windowSize = right - left + 1;
        if (windowSize > maxSize) {
            maxSize = windowSize;
        }
        right++;

        /*
            sta3mlna unsigned char 7it range of char [-128 -> 127]
            but unsigned char [0 -> 255]    
            exampl:
            char c = 200; --> -56
            
            wla khdmt biha hka
            seen[c] == seen[-56] --> Undefined Behavior
        */
	}
	return (maxSize);
}

int main(void) {
	char s[] = "abcabcbb"; 
	
	int maxSum = longestSubstringNoRepeat(s);

	printf("The length of the longest substring is: %d\n", maxSum);
	return (0);
}
