class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // find the first position whose value is not less than $target.
        // the initial range of answer is (-1, n].
        int lb = -1, ub = n;
        while (ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if (A[mid] < target) {
                lb = mid; // answer is in range (mid, ub].
            } else {
                ub = mid; // answer is in range (lb, mid].
            }
        }

        // find the first position whose value is greater than $target.
        // the initial range of answer is (-1, n].
        int lb2 = -1, ub2 = n;
        while (ub2 - lb2 > 1) {
            int mid = (lb2 + ub2) / 2;
            if (A[mid] <= target) {
                lb2 = mid; // answer is in range (mid, ub2].
            } else {
                ub2 = mid; // answer is in range (lb2, mid].
            }
        }

        vector<int> ans;
        // set $ub to -1 if $ub equals to $n or $A[ub] not equals to $target.
        if (ub == n || A[ub] != target) ub = -1;
        // set $ub2 to -1 if $ub2 greater than 0 and $A[ub2-1] not equals to $target.
        if (ub2 && A[ub2-1] != target) ub2 = -1;
        else --ub2;
        ans.push_back(ub);
        ans.push_back(ub2);

        return ans;
    }
};
