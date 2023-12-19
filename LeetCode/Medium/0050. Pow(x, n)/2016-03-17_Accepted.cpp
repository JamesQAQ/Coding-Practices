class Solution {
public:
    double myPow(double x, int N) {
        long long n = N;
        if (n < 0)
            x = 1 / x, n = -n;
        double ans = 1.0;
        for (int i = 31; i >= 0; i--){
            ans *= ans;
            if (((long long)1 << i) & n)
                ans *= x;
        }
        return ans;
    }
};
