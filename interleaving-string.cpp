class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // length of strings
        len1 = s1.size();
        len2 = s2.size();
        len3 = s3.size();
        if (len1 + len2 != len3) return false;

        // cache the answer
        vector<vector<int> > dp(len1+1, vector<int>(len2+1, -1));
        return dfs(0, 0, 0, s1, s2, s3, dp);
    }

    bool dfs(int i1, int i2, int i3, string &s1, string &s2, string &s3, vector<vector<int> > &dp) {
        if (i1 == len1 && i2 == len2 && i3 == len3) return true;
        if (dp[i1][i2] != -1) return dp[i1][i2];

        int &res = dp[i1][i2];
        if (i1 < len1 && i3 < len3 && s1[i1] == s3[i3]) if (dfs(i1 + 1, i2, i3 + 1, s1, s2, s3, dp)) return res = 1;
        if (i2 < len2 && i3 < len3 && s2[i2] == s3[i3]) if (dfs(i1, i2 + 1, i3 + 1, s1, s2, s3, dp)) return res = 1;
        return res = 0;
    }

private:
    int len1, len2, len3;
};
