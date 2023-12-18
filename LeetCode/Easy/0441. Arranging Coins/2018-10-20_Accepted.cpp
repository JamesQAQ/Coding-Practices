class Solution {
public:
    int arrangeCoins(int n) {
        int ans = sqrt(2LL * n) - 1;
        if (ans < 0) ans = 0;
        while (f(ans + 1) <= n) ans++;
        return ans;
    }

private:
    long long f(long long x) {
        return (1 + x) * x / 2;
    }
};