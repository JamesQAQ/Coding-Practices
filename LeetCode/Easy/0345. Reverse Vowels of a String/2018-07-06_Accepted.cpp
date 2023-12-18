class Solution {
public:
    string reverseVowels(string str) {
        string s = str;
        v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = true;
        v['A'] = v['E'] = v['I'] = v['O'] = v['U'] = true;
        
        int l = 0, r = s.length() - 1;
        while (true) {
            while (!isVowel(s[l]) && l < s.length()) l++;
            while (!isVowel(s[r]) && r >= 0) r--;
            if (l < r) {
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l++;
                r--;
            } else {
                break;
            }
        }
        return s;
    }
private:
    char v[256] = {};
    
    bool isVowel(char c) {
        return v[c];
    }
};