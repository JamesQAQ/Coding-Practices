class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<int> a[17];
        int dp[1001] = {};
        int maxlen = 0;
        int ans = 1;
        for (int i = 0; i < words.size(); i++) {
            a[words[i].length()].push_back(i);
            maxlen = max(maxlen, (int)words[i].length());
        }
        for (int i = 0; i < a[maxlen].size(); i++) {
            int idx = a[maxlen][i];
            dp[idx] = 1;
        }
        for (int i = maxlen - 1; i >= 1; i--) {
            for (int j = 0; j < a[i].size(); j++) {
                int idx = a[i][j];
                dp[idx] = 1;
                for (int k = 0; k < a[i + 1].size(); k++) {
                    int iidx = a[i + 1][k];
                    if (check(words, idx, iidx)) {
                        dp[idx] = max(dp[idx], dp[iidx] + 1);
                    }
                }
                ans = max(ans, dp[idx]);
            }
        }
        return ans;
    }
    
    bool check(vector<string>& words, int a, int b) {
        string sa = words[a];
        string sb = words[b];
        int idx = 0;
        bool different = false;
        for (int i = 0; i < sb.length(); i++) {
            if (idx < sa.length()) {
                if (sa[idx] != sb[i]) {
                    if (different) return false;
                    different = true;
                } else {
                    idx++;
                }
            }
        }
        return true;
    }
};