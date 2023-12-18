class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[256] = {};
        for (int i = 0 ; i < s.length(); i++) {
            cnt[s[i]]++;
        }
        int single = 0, ans = 0;
        for (int i = 0; i < 256; i++) {
            ans += (cnt[i] / 2) * 2;
            if (cnt[i] % 2 == 1) single = 1;
        }
        return ans + single;
    }
};