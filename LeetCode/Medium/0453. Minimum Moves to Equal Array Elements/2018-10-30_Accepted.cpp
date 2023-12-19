class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = 2147483647;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i] - mini;
        }
        return ans;
    }
};