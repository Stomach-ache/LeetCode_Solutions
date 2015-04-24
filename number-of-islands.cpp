class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        // size of the given grid
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        // mark the position (x, y) to 'true' if once it is visited
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (grid[i][j] == '1' && !vis[i][j]) {
            bfs(i, j, n, m, grid, vis);
            ++ans;
        }
        return ans;
    }

    void bfs(int sx, int sy, int n, int m, vector<vector<char> > &grid, vector<vector<bool> > &vis) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        queue<int> que;
        que.push(sx * m + sy);
        vis[sx][sy] = true;
        while (!que.empty()) {
            int cur = que.front(); que.pop();
            int x = cur / m;
            int y = cur % m;
            for (int i = 0; i < 4; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == '1' && !vis[xx][yy]) {
                    que.push(xx * m + yy);
                    vis[xx][yy] = true;
                }
            }
        }
    }
};
