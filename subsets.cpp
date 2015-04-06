class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // answer to return.
        vector<vector<int> > ans;
        // size of $S.
        int n = (int)S.size();
        // the initial set is $sup.
        int sup = (1<<n) - 1;
        // $sub is a subset of $sup.
        int sub = sup;
        do {
            sub = (sub - 1) & sup;
            vector<int> vtmp;
            for (int i = 0; i < n; i++) if ((1<<i) & sub) {
                vtmp.push_back(S[i]);
            }
            sort(begin(vtmp), end(vtmp));
            ans.push_back(vtmp);
        } while (sub != sup); // -1 & sup == sup.

        return ans;
    }
};
