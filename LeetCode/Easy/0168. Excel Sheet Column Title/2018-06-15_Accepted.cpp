class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n > 0) {
            int last = (n - 1) % 26;
            ans += (n - 1) % 26 + 'A';
            n -= last + 1;
            n /= 26;
        }
        for (int i = 0; i < ans.length() / 2; i++) {
            char tmp = ans[i];
            ans[i] = ans[ans.length() - 1 - i];
            ans[ans.length() - 1 - i] = tmp;
        }
        return ans;
    }
};