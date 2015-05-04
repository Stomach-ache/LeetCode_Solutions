class Solution {
public:
    int search(vector<int>& nums, int target) {
        // size of $nums
        int sz = nums.size();
        if (sz == 0) return -1;

        // the answer is in range [l, r)
        int l = 0, r = sz;
        while (r - l > 1) {
            // middle position
            int m = (l + r) / 2;
            if (nums[m] > target) {
                if (nums[m] >= nums[0]) {
                    if (target >= nums[0]) r = m;
                    else l = m + 1;
                } else {
                    r = m;
                }
            } else if (nums[m] < target) {
                if (nums[m] >= nums[0]) l = m + 1;
                else if (target <= nums[sz - 1]) l = m + 1;
                else r = m;
            } else {
                return m;
            }
        }
        if (nums[l] == target) return l;
        else return -1;
    }
};
