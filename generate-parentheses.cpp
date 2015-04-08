class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string stmp = "";
        dfs(0, 0, n, stmp, ans);
        return ans;
    }

    void dfs(int lft, int rgt, int n, string &stmp, vector<string> &ans) {
        if (lft == rgt && lft == n) {
            ans.push_back(stmp);
            return ;
        }

        // we can choose to append a left parentheses if $lft less than $n
        if (lft < n) {
            stmp.append("(");
            dfs(lft+1, rgt, n, stmp, ans);
            stmp.pop_back();
        }
        // we can choose to append a right parentheses if $rgt less than $lft
        if (rgt < lft) {
            stmp.append(")");
            dfs(lft, rgt+1, n, stmp, ans);
            stmp.pop_back();
        }
    }
};
