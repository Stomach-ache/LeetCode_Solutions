class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ans;
        vector<int> vtmp;

        // sort the array first
        sort(begin(num), end(num));
        // length of array
        int n = num.size();

        dfs(0, 0, num, n, target, vtmp, ans);
        return ans;
    }

    void dfs(int cur, int sum, vector<int> &num, int n, int target, vector<int> &vtmp, vector<vector<int> > &ans) {

        if (sum == target) {
            string stmp = "";
            for (const int &v : vtmp) stmp += to_string(v);
            if (stmp.size() && vis.find(stmp) == vis.end()) {
                vis.insert(stmp);
                ans.push_back(vtmp);
            }
        } else if (sum < target && cur < n) {
            // do not use $num[cur]
            dfs(cur+1, sum, num, n, target, vtmp, ans);

            // use $num[cur]
            if (sum + num[cur] <= target) {
                vtmp.push_back(num[cur]);
                dfs(cur+1, sum+num[cur], num, n, target, vtmp, ans);
                vtmp.pop_back();
            }
        }
    }
private:
    unordered_set<string> vis;
};
