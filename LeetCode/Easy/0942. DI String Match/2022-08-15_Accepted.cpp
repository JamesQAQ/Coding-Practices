class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l = 0, r = s.length();
        vector<int> ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') ans.push_back(l++);
            else ans.push_back(r--);
        }
        ans.push_back(l++);
        return ans;
    }
};