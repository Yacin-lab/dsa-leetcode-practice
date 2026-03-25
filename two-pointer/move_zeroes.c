#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int lastNumber = 0;
    int numberSearch = 0;

    while(numberSearch < numsSize) {
        if(nums[numberSearch] != 0) {
            nums[lastNumber] = nums[numberSearch];
            lastNumber++;
        }
        numberSearch++;
    }
    
    for(;lastNumber < numberSearch; lastNumber++)
        nums[lastNumber] = 0;
}

int main(void) {
    int arr[] = {0,1,0,3,12};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    moveZeroes(arr, size);

    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return (0);
}