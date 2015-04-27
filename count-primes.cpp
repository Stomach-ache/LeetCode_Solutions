class Solution {
public:
    int countPrimes(int n) {
        bool *vis = new bool[n];
        for(int i = 2; i < n; ++i) vis[i] = true;

        int k = (int)sqrt(n + 0.0) + 1;
        for (int i = 2; i < k; ++i) if (vis[i]) for (int j = i*i; j < n; j += i) vis[j] = false;

        int result = 0;
        for(int i = 2; i < n; ++i) result += vis[i] ? 1 : 0;
        delete[] vis;

        return result;
    }
};
