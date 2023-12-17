class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int cnt = 0;
        while (cnt < target.length()) {
            int pos = 0;
            while (pos <= target.length() - stamp.length()) {
                if (match(stamp, target, pos)) break;
                pos++;
            }
            if (pos > target.length() - stamp.length()) return {};
            for (int i = 0; i < stamp.length(); i++) {
                if (target[pos + i] != '?') {
                    target[pos + i] = '?';
                    cnt++;
                }
            }
            ans.push_back(pos);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    bool match(string& stamp, string& target, int pos) {
        int cnt = 0;
        for (int i = 0; i < stamp.length(); i++) {
            if (target[pos + i] == '?') {
                cnt++;
            } else if (stamp[i] != target[pos + i]) {
                return false;
            }
        }
        return cnt < stamp.length();
    }
};