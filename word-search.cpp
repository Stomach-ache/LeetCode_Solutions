class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        n = board.size();
        if (n == 0) return word.size() == 0;

        m = board[0].size();
        len = word.size();
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (board[i][j] == word[0]) {
            char tmp = board[i][j];
            // mark the position (i, j) as visited instead of using another 2D array
            board[i][j] = '\0';
            if (dfs(i, j, 1, board, word)) return true;
            board[i][j] = tmp;
        }
        return false;
    }

    bool dfs(int x, int y, int pos, vector<vector<char> > &board, string &word) {
        if (pos == len) return true;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && board[xx][yy] == word[pos]) {
                char tmp = board[xx][yy];
                board[xx][yy] = '\0';
                if (dfs(xx, yy, pos+1, board, word)) return true;
                board[xx][yy] = tmp;
            }
        }
        return false;
    }
private:
    // size of board and length of the given word
    int n, m, len;
};
