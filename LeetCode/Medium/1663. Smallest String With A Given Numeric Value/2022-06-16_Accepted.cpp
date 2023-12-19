class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        for (int i = 0; i < n; i++) {
            if (1 + (n - i - 1) * 26 < k) {
                ans[i] = k - (n - i - 1) * 26 + 'a' - 1;
            }
            k -= ans[i] - 'a' + 1;
        }
        return ans;
    }
};