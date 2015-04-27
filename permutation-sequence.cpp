// Cantor expansion
class Solution {
public:
    // get the Kth permutation sequence
    string getPermutation(int n, int k) {
        // factorial from 1 to (n - 1)
        vector<int> fact(n);
        fact[0] = 1;
        for (int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;
        // mark the number if it has been used
        vector<bool> used(n + 1, false);

        // hold the answer
        string result = "";
        --k;
        for (int i = n - 1; i >= 0; --i) {
            int a = k / fact[i];
            k %= fact[i];

            int j = 1;
            while (j <= n && used[j]) ++j;
            for (; a > 0; ++j) if (!used[j]) --a;
            while (j <= n && used[j]) ++j;
            result += j + '0';
            used[j] = true;
        }

        return result;
    }
};
