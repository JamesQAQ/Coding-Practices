class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                cnt++;
            } else {
                cnt = 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};