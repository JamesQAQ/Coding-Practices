class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1;
        int space = 100;
        for (int i = 0; i < s.length(); i++) {
            int w = widths[s[i] - 'a'];
            if (w > space) {
                line++;
                space = 100 - w;
            } else {
                space -= w;
            }
        }
        vector<int> ans;
        ans.push_back(line);
        ans.push_back(100 - space);
        return ans;
    }
};