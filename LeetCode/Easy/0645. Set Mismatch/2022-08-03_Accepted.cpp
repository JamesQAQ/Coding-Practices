class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        vector<bool> marked(nums.size() + 1, false);
        for (int i = 0; i < nums.size(); i++) {
            if (marked[nums[i]]) ans.push_back(nums[i]);
            marked[nums[i]] = true;
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (!marked[i]) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};