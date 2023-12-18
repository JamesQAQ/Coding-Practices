class Solution {
public:
    int binaryGap(int n) {
        int cnt = -10000;
        int ans = 0;
        while (n) {
            if (n % 2 == 1) {
                ans = max(ans, cnt);
                cnt = 0;
            }
            cnt++;
            n /= 2;
        }
        return ans;
    }
};