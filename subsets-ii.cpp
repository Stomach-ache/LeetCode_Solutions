class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // answer to return
        vector<vector<int> > result;

        // sort the array first
        sort(begin(S), end(S));
        // count the number of each number
        vector<pair<int, int> > vec;
        int sz = S.size();
        for (int i = 0; i < sz; ++i) {
            int j = i;
            while (j < sz && S[j] == S[i]) ++j;
            vec.push_back(make_pair(S[i], j - i));
            i = j - 1;
        }

        // temporary vector to store a subset
        vector<int> vtmp;
        sz = vec.size();
        dfs(0, sz, vtmp, vec, result);
        return result;
    }

    void dfs(int cur, int sz, vector<int> &vtmp, vector<pair<int, int> > &S, vector<vector<int> > &result) {
        if (cur == sz) {
            result.push_back(vtmp);
            return ;
        }
        for (int i = 0; i <= S[cur].second; ++i) {
            for (int j = 0; j < i; ++j) vtmp.push_back(S[cur].first);
            dfs(cur + 1, sz, vtmp, S, result);
            for (int j = 0; j < i; ++j) vtmp.pop_back();
        }
    }
};
