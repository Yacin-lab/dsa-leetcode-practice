#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
void selection_sort(int *arr, int size) {
    int i, j, temp, min_idx;

    i = 0;
    while(i < size-1) {
        min_idx = i;
        j = i + 1;
        // Find the minimum element
        while(j < size) {
            if(arr[min_idx] > arr[j]) {
                min_idx = j;
            }
            j++;
        }
        // Swap minimum with the first element ...
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

        i++;
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    int sum = 0;
    int capacity = 10;
    int **result = malloc(capacity * sizeof(int *));
    if (!result)
        return (NULL);
    // *returnColumnSize == arr (in main)
    *returnColumnSizes = malloc(capacity * sizeof(int));
    if (!*returnColumnSizes)
        return (NULL);

    // sort array first (required for two pointers)
    selection_sort(nums, numsSize);
    // for(int i = 0; i < numsSize; i++)
    //     printf("%d ", nums[i]);
    
    int i = 0;
    while(i < numsSize - 2) {
        // skip Repeated numbers at the beginning
        while(i > 0 && i < numsSize - 2 && nums[i] == nums[i - 1]) {
            i++;
        }
        int left = i + 1;
        int right = numsSize - 1;
        // two pointer search
        while(left < right) {
            sum = nums[i] + nums[left] + nums[right];
            // if sum == 0 move left++ and right--
            if (sum == 0) {
                // Increase buffer size if needed
                if (*returnSize == capacity) {
                    capacity *= 2;
                    result = realloc(result, capacity * sizeof(int *));
                    if (!result)    return (NULL);
                    *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                    if (!*returnColumnSizes)    return (NULL);
                }
                // allocate memory for one triplet
                result[*returnSize] = malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                // *returnColumnSize == arr (in main)
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                // Fa9at 7tal9a triplet = 0 3ad:
                // move both pointers to skip duplicate triplet
                // skip duplicates on left
                left++;
                while(left < right && nums[left] == nums[left - 1])
                    left++;
                // skip duplicates on right
                right--;
                while(right > left && nums[right] == nums[right + 1])
                    right--;
            }
            // if sum < 0 move left++ (We need larger sum ⬆️​)
            else if (sum < 0) {
                left++;
            }
            // else, move right-- (We need smaller sum ⬇️​)
            else {
                right--;
            }
        }
        i++;
    }
    return (result);
}

int main(void) {
    int arr[] = {-1,0,1,2,-1,-4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int returnSize;
    int *returnColumnSizes;

    int **res = threeSum(arr, size, &returnSize, &returnColumnSizes);
    for(int i = 0; i < returnSize; i++) {
        for(int j = 0; j < *returnColumnSizes; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return (0);
}