class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) return res;
        long long left = nums[0], cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > cur + 1) {
                if (left == cur) res.push_back(to_string(left));
                else res.push_back(to_string(left) + "->" + to_string(cur));
                left = cur = nums[i];
            } else {
                cur++;
            }
        }
        if (left == cur) res.push_back(to_string(left));
        else res.push_back(to_string(left) + "->" + to_string(cur));
        return res;
    }
};