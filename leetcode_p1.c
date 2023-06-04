#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int* returnArray = (int*)malloc(2 * sizeof(int));

    printf("function started");

    if (returnSize != NULL) {
        *returnSize = 2;
    }
    
    int firstSelected;
    for (int i=0; i<numsSize-1; i++) {
        firstSelected = nums[i];
        for (int j=i+1; j<numsSize; j++) {
            if (firstSelected + nums[j] == target) {
                returnArray[0] = i;
                returnArray[1] = j;
            }
        }
    }

    return returnArray;
}



int main()
{
    int numsSize = 4;
    int* nums = (int*)malloc(numsSize * sizeof(int));
    nums[0] = 20;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 2;

    int target = 9;
    int* returnSize = (int*)malloc(sizeof(int));
    *returnSize = 0;

    int* result = twoSum(nums, numsSize, target, returnSize);
    printf("\nthe return size is: %d", *returnSize);
    for (int i=0; i<*returnSize; i++) {
        printf("\n%d ", result[i]);
    }
}


