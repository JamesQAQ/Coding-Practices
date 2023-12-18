class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ans;
        int maxVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                ans = i;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != maxVal && nums[i] * 2 > maxVal) {
                return -1;
            }
        }
        return ans;
    }
};