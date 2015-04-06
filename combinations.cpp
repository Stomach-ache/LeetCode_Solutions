class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // answer to return.
        vector<vector<int> > ans;

        // a temporaray vector.
        vector<int> vtmp;
        dfs(0, k, n, vtmp, ans);

        return ans;
    }

    /* $cur: the lastest value appended in $tvmp*/
    /* $lft: number of elements needed. */
    void dfs(int cur, int lft, int n, vector<int> &vtmp, vector<vector<int> > &ans) {
        if (lft == 0) {
            ans.push_back(vtmp);
            return ;
        }

        for (int i = cur+1; i <= n; i++) {
            vtmp.push_back(i);
            dfs(i, lft-1, n, vtmp, ans);
            vtmp.pop_back();
        }
    }
};
