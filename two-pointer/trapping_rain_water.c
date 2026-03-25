#include <stdio.h>

int trap(int* height, int heightSize) {
    int WaterSize = 0;

    int left = 0;
    int right = heightSize - 1;

    int maxLeft = 0;
    int maxRight = 0;
    
    while(left < right) {

        if (height[left] < height[right]) {
            // ila l9it wall >= maxWall li l9it 9bal
            // ya3ni water = 0 (7it a3la 9imma 3la lyasar <= l9imma l7alya)
            if(height[left] >= maxLeft)
                maxLeft = height[left];
            // ila l9it wall > maxWall li 9bal
            // ya3ni 3ndi water (deference mabin corrent wall w maxWall)
            else
                WaterSize += maxLeft - height[left];
            left++;
        } else {
            if(height[right] >= maxRight)
                maxRight = height[right];
            else
                WaterSize += maxRight - height[right];
            right--;
        }
    }
    return (WaterSize);
}

int main(void) {

    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};

    printf("%d\n", trap(arr, 12));

    return (0);
}