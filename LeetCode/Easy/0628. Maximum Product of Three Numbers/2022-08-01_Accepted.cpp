class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] * nums[1] * nums[2];
        for (int i = 0; i < 3; i++) {
            int val = 1;
            for (int j = 0; j < i; j++) {
                val *= nums[j];
            }
            for (int j = 0; j < 3 - i; j++) {
                val *= nums[nums.size() - 1 - j];
            }
            ans = max(ans, val);
        }
        return ans;
    }
};