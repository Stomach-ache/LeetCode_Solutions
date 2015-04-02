/*
 * median A[] n = case n&1 of 0 => A[n/2]
 *                            1 => (A[n/2] + A[n/2-1]) / 2
 */

class Solution {
public:

    /* find the Kth element of two sorted arrays */
    double findKthSortedArrays(int A[], int m, int B[], int n, int K) {
        if (n <= 0 && m <= 0) return 0;
        if (n <= 0) {
            return A[K];
        }
        if (m <= 0) {
            return B[K];
        }

        int mid1 = m / 2;
        int mid2 = n / 2;

        if (A[mid1] >= B[mid2]) {
            if (mid1 + mid2 + 1 > K) {
                // target should not be in range [mid1, m) of array $A.
                return findKthSortedArrays(A, mid1, B, n, K);
            } else {
                // target should not be in range [0, mid2] of array $B.
                // update $K at the same time.
                return findKthSortedArrays(A, m, B+mid2+1, n-mid2-1, K-mid2-1);
            }
        } else {
            if (mid1 + mid2 + 1 > K) {
                // target should not be in range [mid2 n) of array $B.
                return findKthSortedArrays(A, m, B, mid2, K);
            } else {
                // target should not be in range [0, mid1] of array $A.
                // update $K at the same time.
                return findKthSortedArrays(A+mid1+1, m-mid1-1, B, n, K-mid1-1);
            }
        }
    }

    /* find the median of two sorted arrays. */
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // total amount of numbers in $A and $B.
        int all = m + n;

        int mid = all / 2;
        double ans = findKthSortedArrays(A, m, B, n, mid);

        // if $all is even.
        if (0 == (all % 2)) {
            mid = all / 2 - 1;
            ans = (ans + findKthSortedArrays(A, m, B, n, mid)) * 0.5;
        }

        return ans;
    }
};
