class Solution {
public:
    /* determine whether $token is a operator */
    bool isOp(const string &token) {
        return token=="+" || token=="-" || token=="*" || token=="/";
    }

    /* convert string $token to an integer */
    int strToInt(const string &token) {
        int res = 0;
        int n = token.size();
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (token[i] == '-') {
                flag = -1;
                continue;
            }
            res = res*10 + token[i]-'0';
        }
        return res*flag;
    }

    /* calculate the result of expression "$a $op $b" */
    int calc(int a, int b, string &op) {
        if (op == "+") return a + b;
        else if (op == "-") return a - b;
        else if (op == "*") return a * b;
        else return a / b;
    }

    int evalRPN(vector<string> &tokens) {
        char str[100];
        stack<string> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (isOp(tokens[i])) {
                if (st.size() >= 2) {
                    int b = strToInt(st.top()); st.pop();
                    int a = strToInt(st.top()); st.pop();
                    int c = calc(a, b, tokens[i]);
                    str[0] = 0;
                    sprintf(str, "%d", c);
                    st.push(string(str));
                }
            } else {
                st.push(tokens[i]);
            }
        }
        if (st.size()) return strToInt(st.top());
    }
};
