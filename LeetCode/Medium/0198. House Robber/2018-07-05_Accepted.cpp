class Solution {
public:
    int rob(vector<int>& nums) {
        int pre2 = 0;
        int pre = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur = pre2 + nums[i];
            ans = max(ans, cur);
            pre2 = max(pre2, pre);
            pre = max(pre, cur);
        }
        return ans;
    }
private:
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
};