#include <stdio.h>

int trap(int* height, int size) {
    if (size <= 2)
        return 0;

    int leftMax[size];
    int rightMax[size];

    leftMax[0] = height[0];
    for (int i = 1; i < size; i++) {
        leftMax[i] = (height[i] > leftMax[i - 1]) ? height[i] : leftMax[i - 1];
    }

    rightMax[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        rightMax[i] = (height[i] > rightMax[i + 1]) ? height[i] : rightMax[i + 1];
    }

    int water = 0;
    for (int i = 1; i < size - 1; i++) {
        int minHeight = (leftMax[i] < rightMax[i]) ? leftMax[i] : rightMax[i];
        if (minHeight > height[i]) {
            water += minHeight - height[i];
        }
    }

    return water;
}

int main() {
    int height1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size1 = sizeof(height1) / sizeof(height1[0]);
    int water1 = trap(height1, size1);
    printf("Water trapped: %d\n", water1);

    int height2[] = {4, 2, 0, 3, 2, 5};
    int size2 = sizeof(height2) / sizeof(height2[0]);
    int water2 = trap(height2, size2);
    printf("Water trapped: %d\n", water2);

    return 0;
}
