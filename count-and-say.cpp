/*
 * function to_string() appears in the
 * new standard of c++11.
 */

class Solution {
public:
    string countAndSay(int n) {

        string ans = "1";
        for (int i = 2; i <= n; i++) {
            char pre = 'a';
            int cnt = 0;
            string temp = ans;
            ans = "";
            int len = temp.size();
            for (int i = 0; i < len; i++) {
                char cur = temp[i];
                if (cur == pre) ++cnt;
                else {
                    if (cnt > 0) {
                        ans += to_string(cnt);
                        ans += pre;
                    }
                    pre = cur;
                    cnt = 1;
                }
            }
            if (cnt > 0) {
                ans += to_string(cnt);
                ans += pre;
            }
        }

        return ans;
    }
};
