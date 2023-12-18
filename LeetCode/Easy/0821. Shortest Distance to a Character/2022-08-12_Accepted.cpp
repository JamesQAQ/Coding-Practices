class Solution {
    int MAX = 10000;
    
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.length(), MAX);
        int pre = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) pre = i;
            if (pre != -1) ans[i] = min(ans[i], abs(i - pre));
        }
        pre = -1;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == c) pre = i;
            if (pre != -1) ans[i] = min(ans[i], abs(i - pre));
        }
        return ans;
    }
};