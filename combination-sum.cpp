class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {

        // a copy of $candidates.
        vector<int> arr(candidates);
        // sort and unique.
        sort(begin(arr), end(arr));
        int n = unique(begin(arr), end(arr)) - begin(arr);

        // answer to return.
        vector<vector<int> > ans;
        vector<int> vtmp;
        dfs(0, arr, 0, vtmp, n, target, ans);

        return ans;
    }

    void dfs(int cur, vector<int> &arr, int curSum, vector<int> &vtmp, int n, int target, vector<vector<int> > &ans) {
        if (curSum == target) {
            ans.push_back(vtmp);
        }

        // attention that sum of $arr[i] and $curSum may bigger than MAX_INT.
        for (int i = cur; i < n && arr[i] <= target-curSum; i++) {
            vtmp.push_back(arr[i]);
            dfs(i, arr, curSum+arr[i], vtmp, n, target, ans);
            vtmp.pop_back();
        }
    }
};
