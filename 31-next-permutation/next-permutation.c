void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    // Step 1: Find the first decreasing element from the end
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    // Step 2: Find the next greater element and swap
    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i])
            j--;

        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Step 3: Reverse the remaining suffix
    reverse(nums, i + 1, numsSize - 1);
}