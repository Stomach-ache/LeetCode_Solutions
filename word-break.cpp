class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        len = s.size();
        vector<int> dp(len, -1);

        return dfs(0, s, wordDict, dp);
    }

    bool dfs(int pos, string &s, unordered_set<string> &wordDict, vector<int> &dp) {
        if (pos == len) return true;
        if (dp[pos] != -1) return dp[pos];

        for (int i = pos; i < len; ++i) if (wordDict.find(s.substr(pos, i-pos+1)) != wordDict.end()) {
            if (dfs(i+1, s, wordDict, dp)) return dp[pos] = 1;
        }
        return dp[pos] = 0;
    }
private:
    int len;
};
