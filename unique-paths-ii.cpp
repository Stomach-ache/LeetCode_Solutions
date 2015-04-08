class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // size of the gragh
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int> (n, 0));

        // set $dp[i][j] to zero if $obstacleGrid[i][j] equals to one
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) {
                    if (obstacleGrid[i][j] == 0)
                        dp[i][j] = 1;
                } else {
                    if (obstacleGrid[i][j] == 0) {
                        if (i+1 < m && obstacleGrid[i+1][j] == 0) dp[i][j] += dp[i+1][j];
                        if (j+1 < n && obstacleGrid[i][j+1] == 0) dp[i][j] += dp[i][j+1];
                    }
                }
            }
        }
        return dp[0][0];
    }
};
