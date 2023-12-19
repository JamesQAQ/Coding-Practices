class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (reach < i) return false;
            int cur_reach = i + nums[i];
            if (cur_reach > reach) reach = cur_reach;
        }
        return reach >= nums.size() - 1;
    }
};