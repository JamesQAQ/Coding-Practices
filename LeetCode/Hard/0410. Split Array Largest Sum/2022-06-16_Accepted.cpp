class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int lval = 0;
        int rval = sum;
        while (lval <= rval) {
            int mval = (lval + rval) / 2;
            if (check(nums, m, mval)) {
                rval = mval - 1;
            } else {
                lval = mval + 1;
            }
        }
        return lval;
    }

private:
    bool check(vector<int>& nums, int m, int maxValue) {
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                return false;
            }
            if (sum + nums[i] <= maxValue) {
                sum += nums[i];
            } else {
                sum = nums[i];
                count++;
            }
        }
        return count + 1 <= m;
    }
};