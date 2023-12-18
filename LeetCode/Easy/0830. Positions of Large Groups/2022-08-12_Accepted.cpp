class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        char c = '.';
        int start = -1;
        s += '.';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != c) {
                if (i - start >= 3) {
                    vector<int> item(2, start);
                    item[1] = i - 1;
                    ans.push_back(item);
                }
                c = s[i];
                start = i;
            }
        }
        return ans;
    }
};