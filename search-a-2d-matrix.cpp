class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // size of matrix
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        // binary search
        int l = 0, r = n * m;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (matrix[mid / n][mid % n] > target) r = mid;
            else l = mid;
        }
        return matrix[l / n][l % n] == target;
    }
};
