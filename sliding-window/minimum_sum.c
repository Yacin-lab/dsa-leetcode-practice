#include <stdio.h>
#include <limits.h>

/*
    Function: minimumSizeSubarraySum
    --------------------------------
    Technique: Sliding Window (Dynamic Window)

    Idea:

    We maintain a window between two pointers:
        left  -> start of window
        right -> end of window

    Steps:

    1. Expand the window by moving right and adding elements to sum.
    2. When sum >= target → the window is valid.
    3. Record the window length.
    4. Shrink the window from the left to try to find a smaller valid window.
*/

int minimumSizeSubarraySum(int* arr, int numSize, int target) {

    int left = 0;
    int right = 0;
    int sum = 0;

	int len;
	int minLen = INT_MAX;    // max minimum len is INT_MAX
    

	while (right < numSize) {
        /*
            STEP 1 — Expand window

            Add the element at 'right' to the window sum.
        */
        sum += arr[right];

        /*
            STEP 2 — Check if window satisfies condition

            If sum >= target we found a valid subarray.
            Now we try to shrink the window from the left
            to find the smallest possible valid window.
        */
        while (sum >= target) {

            len = right - left + 1;     // Current window length
            if (len < minLen) {
                minLen = len;
            }

            /*
                STEP 3 — Shrink window

                Remove the left element from the sum
                and move left pointer forward.
            */
            sum -= arr[left];
            left++;
        }
        right++;        // Move right pointer to expand window
	}
    
    // If none exists return 0 bucase minLen = INT_MAX
    if (minLen == INT_MAX) {
        return (0);
    }
	return (minLen);
}

int main(void) {
	int arr[] = {2,3,1,2,4,3}; 
	int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

	int maxSum = minimumSizeSubarraySum(arr, size, target);

	printf (
        "The length of the minimum subarray equal or biger then %d is: %d\n",
        target, maxSum);
	return (0);
}
