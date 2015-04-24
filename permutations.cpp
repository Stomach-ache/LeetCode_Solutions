class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // the length of $num
        int sz = num.size();

        // answer to return
        vector<vector<int> > ans;
        // $vis[i] holds wheather the ith element has been used
        vector<bool> vis(sz, false);
        // temporary permutation.
        vector<int> vtmp;
        dfs(0, sz, num, ans, vis, vtmp);
        return ans;
    }

    void dfs(int cnt, int n, vector<int> &num, vector<vector<int> > &ans, vector<bool> &vis, vector<int> &vtmp) {
        if (cnt == n) {
            ans.push_back(vtmp);
            return ;
        }

        for (int i = 0; i < n; ++i) if (!vis[i]) {
            vis[i] = true;
            vtmp.push_back(num[i]);
            dfs(cnt + 1, n, num, ans, vis, vtmp);
            vtmp.pop_back();
            vis[i] = false;
        }
    }
};
