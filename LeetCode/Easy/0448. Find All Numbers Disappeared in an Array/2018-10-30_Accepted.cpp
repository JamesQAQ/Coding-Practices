class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int idx = val - 1;
            if (nums[idx] != val) {
                nums[i] = nums[idx];
                nums[idx] = val;
                i--;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};