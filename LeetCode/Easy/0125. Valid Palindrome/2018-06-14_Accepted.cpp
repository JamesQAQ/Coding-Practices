class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (int i = 0; i < s.length(); i++) {
            if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) str += s[i];
            else if ('A' <= s[i] && s[i] <= 'Z') str += s[i] - 'A' + 'a';
        }
        for (int i = 0; i < str.length() / 2; i++) {
            if (str[i] != str[str.length() - i - 1]) return false;
        }
        return true;
    }
};