class Solution {
public:
    int rob(vector<int> &num) {
        
        int n = (int)num.size();
        vector<int> vis(n, -1);
        return dfs(0, n, num, vis);
    }
    
    int dfs(int cur, int n, vector<int> &num, vector<int> &vis) {
        if (cur >= n) return 0;
        if (vis[cur] != -1) return vis[cur];
        
        return vis[cur] = max(dfs(cur+1, n, num, vis), dfs(cur+2, n, num, vis)+num[cur]);
    }
};
