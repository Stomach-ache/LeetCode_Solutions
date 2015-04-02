/* 0! = 1 */

class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) return 0;

        // calculate the number of 2 and 5 in n!
        int num2 = 0, num5 = 0;
        int temp = n;
        long long x = 2;
        while (temp >= x) {
            num2 += temp / x;
            x *= 2;
        }
        temp = n;
        x = 5;
        while (temp >= x) {
            num5 += temp / x;
            x *= 5;
        }
        return min(num2, num5);
    }
};
