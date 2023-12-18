class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> res(26, 101);
        for (int i = 0; i < words.size(); i++) {
            vector<int> cnt(26, 0);
            for (int j = 0; j < words[i].length(); j++) {
                cnt[words[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                res[j] = min(res[j], cnt[j]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < res[i]; j++) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;
    }
};