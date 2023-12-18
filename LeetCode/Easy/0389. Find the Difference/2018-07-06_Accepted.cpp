class Solution {
public:
    char findTheDifference(string s, string t) {
        stable_sort(s.begin(), s.end());
        stable_sort(t.begin(), t.end());
        s += " ";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) return t[i];
        }
    }
};