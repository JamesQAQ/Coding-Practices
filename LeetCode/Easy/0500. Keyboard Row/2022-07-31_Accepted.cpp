class Solution {
    string keyboard[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    int ch[256] = {};
    
public:
    vector<string> findWords(vector<string>& words) {
        for (int i = 0; i < 3; i++) {
            string k = keyboard[i];
            for (int j = 0; j < k.length(); j++) {
                ch[k[j]] = ch[k[j] - 'a' + 'A'] = i + 1;
            }
        }
        
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            if (ok(words[i])) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }

private:
    bool ok(string s) {
        for (int i = 1; i < s.length(); i++) {
            if (ch[s[i]] != ch[s[0]]) {
                return false;
            }
        }
        return true;
    }
};