class Solution {
public:
    string reverseString(string str) {
        string s = str;
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            char tmp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = tmp;
        }
        return s;
    }
};