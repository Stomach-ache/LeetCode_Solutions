class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // get the size of $matrix.
        int m = (int)matrix.size(), n;
        if (m > 0) {
            n = (int)matrix[0].size();
        }

        // $fst_row records the whole first row numbers should be set to zero.
        // $fst_col records the whole first col numbers should be set to zero.
        bool fst_col = false, fst_row = false;

        // if $matrix[i][j] is zero then set $matrix[0][j] and $matrix[i][0] to zero.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) if (matrix[i][j] == 0) {
                if (i == 0) fst_row = true;
                if (j == 0) fst_col = true;
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
        // set rows from index one to $(m-1).
        for (int i = 1; i < m; i++) if (matrix[i][0] == 0) {
            for (int j = 1; j < n; j++) matrix[i][j] = 0;
        }
        // set columns from index one to $(n-1).
        for (int j = 1; j < n; j++) if (matrix[0][j] == 0) {
            for (int i = 1; i < m; i++) matrix[i][j] = 0;
        }
        // set the first column and the first row.
        if (fst_col)
            for (int j = 0; j < m; j++) matrix[j][0] = 0;
        if (fst_row)
            for (int i = 0; i < n; i++) matrix[0][i] = 0;
    }
};
