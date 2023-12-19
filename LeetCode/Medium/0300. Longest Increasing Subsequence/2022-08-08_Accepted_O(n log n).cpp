class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > dp[dp.size() - 1]) {
                dp.push_back(nums[i]);
            } else {
                int l = 0, r = dp.size() - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (dp[mid] == nums[i]) {
                        l = mid;
                        break;
                    }
                    if (dp[mid] < nums[i]) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                if (l >= 0) {
                    dp[l] = nums[i];
                }
            }
        }
        return dp.size();
    }
};
