class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> appeared;
        for (int i = 0; i < nums.size(); i++) {
            if (appeared.find(nums[i]) != appeared.end()) return true;
            appeared.insert(nums[i]);
        }
        return false;
    }
};