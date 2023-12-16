class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int upper_bound = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) {
            // Use greedy method, make the breakdowned number as large
            // as possible.
            int parts = nums[i] / upper_bound;

            if (nums[i] % upper_bound) {
                // If the reminder > 0, we need one more number.
                parts++;
            }

            // The next upper bound become to this value because we
            // distribute `nums[i]` to `parts` numbers evenly first.
            // Then we could distribute the remainder evenly from the
            // back.  So we could get the largest upper bound here.
            upper_bound = nums[i] / parts;
            ans += parts - 1;
        }
        return ans;
    }
};
