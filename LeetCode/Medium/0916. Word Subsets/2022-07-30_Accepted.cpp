class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Preprocess for word2.
        vector<int> subset2(26, 0);
        for (int i = 0; i < words2.size(); i++) {
            vector<int> s = build(words2[i]);
            for (int j = 0; j < 26; j++) {
                subset2[j] = max(subset2[j], s[j]);
            }
        }
        
        vector<string> res;
        for (int i = 0; i < words1.size(); i++) {
            vector<int> s = build(words1[i]);
            if (universal(s, subset2)) {
                res.push_back(words1[i]);
            }
        }
        return res;
    }
    
    vector<int> build(string& str) {
        vector<int> res(26, 0);
        for (int i = 0; i < str.length(); i++) {
            res[str[i] - 'a']++;
        }
        return res;
    }
    
    bool universal(vector<int>& s1, vector<int>& s2) {
        for (int i = 0; i < 26; i++) {
            if (s1[i] < s2[i]) {
                return false;
            }
        }
        return true;
    }
};