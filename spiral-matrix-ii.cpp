class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // answer to return
        vector<vector<int> > matrix(n, vector<int> (n));

        // current positon on the X asix
        int curX = 0, curY = 0;
        // current size of matrix
        int curM = n, curN = n;
        // current value to fill in the matrix
        int val = 1;
        while ( 1 ) {
            // teminate loop
            if (curM <= 0 || curN <= 0) return matrix;

            // the top line
            if (curM > 0) {
                for (int i = 0; i < curN; i++) {
                    matrix[curX][curY+i] = val++;
                }
                --curM;
            }
            // the rightmost line
            if (curN > 0) {
                for (int i = 1; i <= curM; i++) {
                    matrix[curX+i][curY+curN-1] = val++;
                }
                --curN;
            }
            // the bottom line
            if (curM > 0) {
                for (int i = curN-1; i >= 0; i--) {
                    matrix[curX+curM][curY+i] = val++;
                }
                --curM;
            }
            // the leftmost line
            if (curN > 0) {
                for (int i = curM; i >= 1; i--) {
                    matrix[curX+i][curY] = val++;
                }
                --curN;
            }
            ++curX; ++curY;
        }
    }
};
