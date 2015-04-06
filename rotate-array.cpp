class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (k >= n) k %= n;
        vector<int> tmp;
        for (int i = n-k; i < n; i++) tmp.push_back(nums[i]);
        for (int i = n-k-1; i >= 0; i--) nums[i+k] = nums[i];
        for (int i = 0; i < k; i++) nums[i] = tmp[i];
    }
};
