class Solution {
public:
    int concatenatedBinary(int n) {
        int base = 1;
        int length = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i >= base) {
                base <<= 1;
                length++;
            }
            ans <<= length;
            ans += i;
            ans %= 1000000007;
        }
        return ans;
    }
};