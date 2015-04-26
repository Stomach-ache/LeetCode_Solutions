class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // size of the given board
        n = board.size();
        if (n == 0) return ;
        m = board[0].size();

        // spread from the boundary that has value 'O'
        vector<vector<bool> > vis(n, vector<bool> (m, false));
        for (int i = 0; i < m; ++i) if (board[0][i] == 'O' && !vis[0][i]) bfs(0, i, board, vis);
        for (int i = 0; i < m; ++i) if (board[n - 1][i] == 'O' && !vis[n - 1][i]) bfs(n - 1, i, board, vis);
        for (int i = 0; i < n; ++i) if (board[i][0] == 'O' && !vis[i][0]) bfs(i, 0, board, vis);
        for (int i = 0; i < n; ++i) if (board[i][m - 1] == 'O' && !vis[i][m - 1]) bfs(i, m - 1, board, vis);

        // flip all the unvisited 'O's into 'X's
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
    }

    void bfs(int x, int y, vector<vector<char> > &board, vector<vector<bool> > &vis) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        queue<int> Q;
        Q.push(x * m + y);
        vis[x][y] = true;
        while (!Q.empty()) {
            int tmp = Q.front(); Q.pop();
            for (int i = 0; i < 4; ++i) {
                int xx = tmp / m  + dx[i];
                int yy = tmp % m + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (board[xx][yy] == 'O' && !vis[xx][yy]) {
                    vis[xx][yy] = true;
                    Q.push(xx * m + yy);
                }
            }
        }
        return ;
    }

private:
    int n, m;
};
