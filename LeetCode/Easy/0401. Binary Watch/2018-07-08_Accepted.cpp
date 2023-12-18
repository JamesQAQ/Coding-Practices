class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        int watch[11] = {};
        dfs(0, num, watch, ans);
        return ans;
    }
private:
    void dfs(int x, int num, int watch[], vector<string>& ans) {
        if (x == 10) {
            if (num == 0) {
                string res = time(watch);
                if (res.length() > 0) {
                    ans.push_back(res);
                }
            }
            return;
        }
        if (num > 0) {
            watch[x] = 1;
            dfs(x + 1, num - 1, watch, ans);
        }
        watch[x] = 0;
        dfs(x + 1, num, watch, ans);
    }
    
    string time(int watch[]) {
        int h = 0;
        for (int i = 0; i < 4; i++) {
            h = h * 2 + watch[i];
        }
        int m = 0;
        for (int i = 4; i < 10; i++) {
            m = m * 2 + watch[i];
        }
        if (h < 12 && m < 60) {
            char s[10];
            sprintf(s, "%d:%02d", h, m);
            string res = string(s);
            return res;
        }
        return "";
    }
};