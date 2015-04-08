class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        // binary search
        int lb = 0, ub = num.size()-1;

        while (ub >= lb) {
            if (lb == ub) return lb;

            int mid = (lb + ub) >> 1;
            // there must be a peek in range [lb, mid]
            if (num[mid] > num[mid+1]) {
                ub = mid;
            } else { // there must be a peek in range (mid, ub]
                lb = mid + 1;
            }
        }
    }
};
