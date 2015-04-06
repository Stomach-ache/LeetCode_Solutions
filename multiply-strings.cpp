class Solution {
public:
    string multiply(string num1, string num2) {
        // length of $num1 and $num2.
        int len1 = num1.size();
        int len2 = num2.size();
        // reverse $num1 and $num2.
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));

        // multiply every bit without carry.
        vector<int> vtmp(len1+len2-1, 0);
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                vtmp[i+j] += (num1[i]-'0') * (num2[j]-'0');
            }
        }
        // deal with carry of every bit.
        int len = len1+len2-1;
        int carry = 0;
        vector<int> ans;
        for (int i = 0; i < len; i++) {
            int tmp = vtmp[i] + carry;
            ans.push_back(tmp%10);
            carry = tmp / 10;
        }
        while (carry > 0) {
            ans.push_back(carry%10);
            carry /= 10;
        }
        string res = "";
        len = ans.size();
        // remove leading zeros.
        while (len > 1 && ans[len-1] == 0) --len;
        for (int i = len-1; i >= 0; --i) res += ans[i] + '0';
        return res;
    }
};
