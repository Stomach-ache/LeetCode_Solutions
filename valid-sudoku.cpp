class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // check the validity of board size.
        int sz = (int)board.size();
        if (sz != 9) return false;
        sz = (int)board[0].size();
        if (sz != 9) return false;

        // check rule one and rule two.
        for (int i = 0; i < sz; i++) {
            vector<bool> row(10, false), col(10, false);
            for (int j = 0; j < sz; j++) {
                char v1 = board[i][j];
                if (v1 != '.') {
                    if (row[v1-'0']) return false;
                    row[v1-'0'] = true;
                }
                char v2 = board[j][i];

                if (v2 != '.') {
                    if (col[v2-'0']) return false;
                    col[v2-'0'] = true;
                }
            }
        }

        // check rule three.
        for (int i = 0; i < sz; i += 3) {
            for (int j = 0; j < sz; j += 3) {
                vector<bool> vis(10, false);
                for (int k = 0; k < 3; k++) for (int l = 0; l < 3; l++) {
                    int x = i + k, y = j + l;
                    char v = board[x][y];
                    if (v == '.') continue;
                    if (vis[v-'0']) return false;
                    vis[v-'0'] = true;
                }
            }
        }
        return true;
    }
};
