class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int igs = 0, igt = 0;
        int ps = s.length() - 1, pt = t.length() - 1;
        while (true) {
            while (ps >= 0) {
                if (s[ps] == '#') {
                    igs++;
                } else if (igs > 0) {
                    igs--;
                } else {
                    break;
                }
                ps--;
            }
            while (pt >= 0) {
                if (t[pt] == '#') {
                    igt++;
                } else if (igt > 0) {
                    igt--;
                } else {
                    break;
                }
                pt--;
            }
            if (ps < 0 && pt < 0) break;
            if (ps < 0 || pt < 0) return false;
            if (s[ps--] != t[pt--]) return false;
        }
        return true;
    }
};