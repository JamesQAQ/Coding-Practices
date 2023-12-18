class Solution {
public:
    bool checkRecord(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') cnt++;
            if (cnt >= 2) return false;
        }
        return s.find("LLL") == -1;
    }
};