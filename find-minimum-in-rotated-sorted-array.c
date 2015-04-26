int findMin(int* nums, int numsSize) {
    // only one element in the array
    if (numsSize == 1) return nums[0];
    // the array is already sorted
    if (nums[numsSize - 1] > nums[0]) return nums[0];

    int l = 0, r = numsSize;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (nums[m] >= nums[0]) l = m;
        else r = m;
    }

    return nums[r];
}
