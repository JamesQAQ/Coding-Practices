class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            negative = true;
        }
        long long n = dividend;
        long long m = divisor;
        if (n < 0) n = -n;
        if (m < 0) m = -m;
        long long ans = 0;
        for (int i = 31; i >= 0; i--) {
            long long cut = m << i;
            if (n >= cut) {
                n -= cut;
                ans += 1LL << i;
            }
        }
        if (negative) ans = -ans;
        if (ans > 2147483647LL) ans = 2147483647LL;
        return ans;
    }
};