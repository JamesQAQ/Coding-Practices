class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int start_idx = i;
            int start_val = nums[i];
            int pre_idx = start_idx;
            int cur_idx = ((pre_idx - k) % n + n) % n;
            while (cur_idx != start_idx) {
                nums[pre_idx] = nums[cur_idx];
                pre_idx = cur_idx;
                cur_idx = ((pre_idx - k) % n + n) % n;
                cnt++;
            }
            nums[pre_idx] = start_val;
            cnt++;
            if (cnt == n) break;
        }
    }
};