class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);

        // traverse from the back to front.
        int i = len - 1;
        int ans = 0;
        while (i >= 0 && s[i] == ' ') --i;
        while (i >= 0 && s[i] != ' ') { ++ans; --i; }

        return ans;
    }
};
