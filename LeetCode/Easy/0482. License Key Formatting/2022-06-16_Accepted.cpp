class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                if ('a' <= s[i] && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
                if (ans.length() > 0 && ans.length() % (k + 1) == k) ans += '-';
                ans += s[i];
            }
        }
        for (int i = 0; i < ans.length() / 2; i++) {
            swap(ans[i], ans[ans.length() - i - 1]);
        }
        return ans;
    }
};