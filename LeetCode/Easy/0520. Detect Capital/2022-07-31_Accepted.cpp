class Solution {
public:
    bool detectCapitalUse(string word) {
        return case1(word) || case2(word) || case3(word);
    }

private:
    bool case1(string s) {
        for (int i = 0; i < s.length(); i++) {
            if ('a' <= s[i] && s[i] <= 'z') return false;
        }
        return true;
    }
    
    bool case2(string s) {
        for (int i = 0; i < s.length(); i++) {
            if ('A' <= s[i] && s[i] <= 'Z') return false;
        }
        return true;
    }
    
    bool case3(string s) {
        if ('a' <= s[0] && s[0] <= 'z') return false;
        for (int i = 1; i < s.length(); i++) {
            if ('A' <= s[i] && s[i] <= 'Z') return false;
        }
        return true;
    }
};