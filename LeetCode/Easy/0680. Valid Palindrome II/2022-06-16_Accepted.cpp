class Solution {
public:
    bool validPalindrome(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - 1 - i]) {
                return validSubPalindrome(s.substr(i + 1, s.length() - 1 - 2 * i)) || validSubPalindrome(s.substr(i, s.length() - 1 - 2 * i));
            }
        }
        return true;
    }

private:
    bool validSubPalindrome(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};