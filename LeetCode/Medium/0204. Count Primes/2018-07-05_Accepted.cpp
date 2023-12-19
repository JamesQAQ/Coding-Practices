class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> p(n + 1);
        int ans = 1;
        p[2] = true;
        for (int i = 4; i < n; i += 2) {
            p[i] = false;
        }
        for (int i = 3; i < n; i += 2) {
            p[i] = true;
        }
        for (int i = 3; i < n; i += 2) {
            if (p[i]) ans++;
            for (int j = 3 * i; j < n; j += 2 * i) {
                p[j] = false;
            }
        }
        return ans;
    }
};