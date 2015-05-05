class Solution {
public:
    int longestValidParentheses(string s) {
        // length of string $s
        int len = s.size();
        // use a stack
        stack<int> st;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ')') {
                if (!st.empty() && s[st.top()] == '(') st.pop();
                else st.push(i);
            } else {
                st.push(i);
            }
        }

        int result = 0;
        int a = len;
        if (st.empty()) result = len;
        else {
            while (!st.empty()) {
                int b = st.top(); st.pop();
                result = max(result, a - b - 1);
                a = b;
            }
            result = max(result, a);
        }
        return result;
    }
};
