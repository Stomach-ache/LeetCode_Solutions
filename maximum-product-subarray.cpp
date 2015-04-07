class Solution {
public:
    int maxProduct(int A[], int n) {
        // answer to return.
        int ans = A[n-1];
        // $preMax keeps the largest  product start from the current number.
        // $preMin keeps the smallest product start from the current number.
        int preMax = A[n-1], preMin = A[n-1];

        for (int i = n-2; i >= 0; --i) {
            if (A[i] > 0) {
                preMax = max(A[i], preMax * A[i]);
                preMin = min(A[i], preMin * A[i]);
                // update answer
                ans = max(ans, preMax);
            } else {
                int tmpMax = preMax;
                preMax = max(A[i], preMin*A[i]);
                preMin = min(A[i], tmpMax*A[i]);
                // update answer
                ans = max(ans, preMax);
            }
        }
        return ans;
    }
};
