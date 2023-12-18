class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for (int i = 1; i * i <= len; i++) {
            if (len % i == 0) {
                int a = i, b = len / i;
                if (check(s, a)) return true;
                if (check(s, b)) return true;
            }
        }
        return false;
    }
    
    bool check(string& s, int x) {
        if (x == s.length()) return false;
        int times = s.length() / x;
        for (int i = 0; i < x; i++) {
            char c = s[i];
            for (int j = 1; j < times; j++) {
                if (c != s[j * x + i]) return false;
            }
        }
        return true;
    }
};