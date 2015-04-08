class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // answer to return
        vector<int> res;
        // size of matrix
        int m = matrix.size();
        // empty matrix
        if (m == 0) return res;
        int n = matrix[0].size();
        if (n == 0) return res;

        // current positon on the X asix
        int curX = 0, curY = 0;
        // current size of matrix
        int curM = m, curN = n;
        while ( 1 ) {
            // teminate loop
            if (curM <= 0 || curN <= 0) return res;

            // the top line
            if (curM > 0) {
                for (int i = 0; i < curN; i++) {
                    res.push_back(matrix[curX][curY+i]);
                }
                --curM;
            }
            // the rightmost line
            if (curN > 0) {
                for (int i = 1; i <= curM; i++) {
                    res.push_back(matrix[curX+i][curY+curN-1]);
                }
                --curN;
            }
            // the bottom line
            if (curM > 0) {
                for (int i = curN-1; i >= 0; i--) {
                    res.push_back(matrix[curX+curM][curY+i]);
                }
                --curM;
            }
            // the leftmost line
            if (curN > 0) {
                for (int i = curM; i >= 1; i--) {
                    res.push_back(matrix[curX+i][curY]);
                }
                --curN;
            }
            ++curX; ++curY;
        }
    }
};
