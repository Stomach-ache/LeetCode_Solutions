class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int len = strs.size();
        if (len == 0) return "";

        int minLen = 0x3f3f3f3f;
        for (int i = 0; i < len; i++) {
            // attention that the type of two argurements should be the same.
            minLen = min(minLen, (int)strs[i].size());
        }

        string ans = "";
        for (int i = 0; i < minLen; i++) {
            char ch = strs[0][i];
            for (int j = 1; j < len; j++) {
                if (strs[j][i] != ch) return ans;
            }
            ans += ch;
        }

        return ans;
    }
};
