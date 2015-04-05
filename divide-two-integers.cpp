const int MAX_INT = 0x7fffffff;
const int MIN_INT = 0x80000000;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == MIN_INT && divisor == -1) return MAX_INT;
        if (divisor == 0) return MAX_INT;

        long long dividend2 = abs((long long)dividend), divisor2 = abs((long long)divisor);
        int ans = 0;
        while (dividend2 >= divisor2) {
            long long m = divisor2;
            long long n = 0;
            while ((m<<1) <= dividend2) {
                m <<= 1;
                ++n;
            }
            dividend2 -= m;
            ans += 1<<n;
        }

        if ((dividend > 0) ^ (divisor > 0)) ans = -ans;

        return ans;
    }
};
