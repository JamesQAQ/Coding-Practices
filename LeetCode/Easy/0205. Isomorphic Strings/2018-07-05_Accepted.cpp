class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        char r[256];
        bool appear[256] = {};
        bool used[256] = {};
        for (int i = 0; i < s.length(); i++) {
            if (!appear[s[i]]) {
                appear[s[i]] = true;
                if (used[t[i]]) return false;
                r[s[i]] = t[i];
                used[t[i]] = true;
            } else {
                if (r[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};