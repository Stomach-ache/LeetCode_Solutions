class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cc = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++cc;
        }
        return m << cc;
    }
};
