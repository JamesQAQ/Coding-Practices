class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (l < s.length() && !letter(s[l])) l++;
            while (r >= 0 && !letter(s[r])) r--;
            if (l < r) swap(s[l++], s[r--]);
        }
        return s;
    }

private:
    bool letter(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }
};