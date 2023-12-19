class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int cnt[2001] = {};
        vector<int> box[2001];
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i] + 1000]++;
        }
        for (int i = 0; i < cnt[0]; i++) box[0].push_back(1);
        for (int i = 1; i <= 2000; i++) {
            if (cnt[i] > box[i - 1].size()) {
                for (int j = 0; j < cnt[i] - box[i - 1].size(); j++) {
                    box[i].push_back(1);
                }
            }
            int c = cnt[i];
            for (int j = 0; j < box[i - 1].size(); j++) {
                if (c == 0) {
                    if (box[i - 1][j] < 3) return false;
                } else {
                    box[i].push_back(box[i - 1][j] + 1);
                    c--;
                }
            }
        }
        if (box[2000].size() > 0) return box[2000][0] >= 3;
        return true;
    }
};