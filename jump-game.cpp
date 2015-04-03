class Solution {
public:
    bool canJump(int A[], int n) {
        // $pre holds the nestest position from where I can jump to the last index.
        int pre = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (A[i] + i >= pre) {
                pre = i;
            }
        }
        return pre == 0;
    }
};
