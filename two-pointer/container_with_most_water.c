#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int area = 0, maxArea = 0;

    int i = 0;
    int j = heightSize - 1;

    while(i < j) {
        if(height[i] < height[j]) {     // height dyal water kayt7dad b smallest wall
            area = height[i] * (j - i); // area = height * width
            i++;
        } else {
            area = height[j] * (j - i);
            j--;
        }
        if(area > maxArea)
            maxArea = area;
    }
    return (maxArea);
}

int main(void) {
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxArea(arr, size));
    return (0);
}