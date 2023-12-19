class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int ans = nums[0];
		int min_prefix = 0;
		int sum = 0;
		
        for (int i = 0; i < nums.size(); i++) {
        	sum += nums[i];
        	if (sum - min_prefix > ans) {
        		ans = sum - min_prefix;
			}
			if (sum < min_prefix) min_prefix = sum;
		}
		
		return ans;
    }
};