#include <stdio.h>

/*
    Function: maximumSumOfSubarray
    --------------------------------
    Returns the maximum sum of any contiguous subarray of size k.

    Idea:
    Use Sliding Window technique.

    1. Compute the sum of the first window of size k.
    2. Slide the window one step each time.
    3. Update the sum by removing the left element
       and adding the new right element.
    4. Track the maximum sum.
*/
int maximumSumOfSubrrary(int* nums, int numsSize, int k) {
	int sumOfWindow = 0;
	int maxSum;
	
	// Step 1: compute sum of first window	
	for(int i = 0; i < k; i++) {
		sumOfWindow += nums[i];
	}

	maxSum = sumOfWindow;
	
	// Step 2: slide the window
	for(int right = k; right < numsSize; right++) {
		int left = right - k;

		// remove element leaving the window
		sumOfWindow -= nums[left];

		// update maximum sum
		sumOfWindow += nums[right];
		if (sumOfWindow > maxSum) {
			maxSum = sumOfWindow;
		}
	}
	return (maxSum);
}

int main(void) {
	int arr[] = {2,1,5,1,3,2};
	int size = sizeof(arr) / sizeof(arr[0]); 
	
	int maxSum = maximumSumOfSubrrary(arr, size, 3);

	printf("Maximum Sum of Subrrary of Size K = %d\n", maxSum);
	return (0);
}
