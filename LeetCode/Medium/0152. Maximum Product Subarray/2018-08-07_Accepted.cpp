class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minVal = min(nums[0], 1);
        int maxVal = max(nums[0], 1);
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans = max(max(ans, nums[i]), max(nums[i] * minVal, nums[i] * maxVal));
            int newMinVal = min(min(minVal * nums[i], maxVal * nums[i]), 1);
            int newMaxVal = max(max(minVal * nums[i], maxVal * nums[i]), 1);
            minVal = newMinVal;
            maxVal = newMaxVal;
        }
        return ans;
    }
};