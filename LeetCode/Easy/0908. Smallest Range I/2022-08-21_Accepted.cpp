class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minVal = 10000, maxVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        if (2 * k > maxVal - minVal) return 0;
        return maxVal - minVal - 2 * k;
    }
};