#include <stdio.h>
#include <stdlib.h>

/*
    Function: averageSubarrays
    ---------------------------
    Returns an array containing the average of every
    contiguous subarray of size k.

    Sliding Window idea:
    1. Compute the sum of the first window.
    2. Store its average.
    3. Slide the window:
        remove left element
        add right element
    4. Store each new average.
*/
float* avreageSubarrays(int* nums, int numsSize, int k) {
	float sum = 0;

	// number of resulting subarrays
	int resultSize = (numsSize - k + 1);
	// allocate memory for result
	float* result = malloc(resultSize * sizeof(float));
	if (!result)
		return (NULL);
	
	int index = 0;

	// first window
	for(int i = 0; i < k; i++) {
		sum += nums[i];
	}

	result[index++] = sum / k;
	// slide window
	for(int right = k; right < numsSize; right++) {
		
		sum -= nums[right - k];	// element leaving
		sum += nums[right];		// element entering
		
		result[index++] = sum / k;
	}
	return (result);
}

int main(void) {
	int arr[] = {1,3,2,6,-1,4,1,8,2};
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 5;
	int resultSize = size - k + 1;

	float* average = avreageSubarrays(arr, size, k);
	for(int i = 0; i < resultSize; i++) {
		printf("%.1f,  ", average[i]);
	}
	
	free(average);
	return (0);
}
