class Solution {
public:
    int titleToNumber(string s) {
        int res = 0, base = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            int val = s[i] - 'A' + 1;
            res += val * base;
            base *= 26;
        }
        return res;
    }
};