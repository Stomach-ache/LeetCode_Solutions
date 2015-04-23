class Solution {
public:
    int getSum(int n) {
        int ans = 0;
        while (n > 0) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        while (vis.find(n) == vis.end()) {
            vis.insert(n);
            n = getSum(n);
        }
        return n == 1;
    }
    
    unordered_set<int> vis;
};
