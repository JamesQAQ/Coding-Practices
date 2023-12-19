class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for (int i = 0; i < s.length(); i++) {
            string a = go(s, i, i);
            if (a.length() > ans.length()) ans = a;
            if (i < s.length() && s[i] == s[i + 1]) {
                a = go(s, i, i + 1);
                if (a.length() > ans.length()) ans = a;
            }
        }
        return ans;
    }
    
    string go(string& s, int l, int r) {
        while (l - 1 >= 0 && r + 1 < s.length()) {
            if (s[l - 1] != s[r + 1]) {
                break;
            }
            l--;
            r++;
        }
        return s.substr(l, r - l + 1);
    }
};