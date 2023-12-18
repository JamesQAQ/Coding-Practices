class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> len;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s[i] != s[i - 1]) {
                len.push_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        len.push_back(cnt);
        int ans = 0;
        for (int i = 1; i < len.size(); i++) {
            ans += min(len[i - 1], len[i]);
        }
        return ans;
    }
};