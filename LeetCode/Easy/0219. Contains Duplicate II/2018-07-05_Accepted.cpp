class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> appeared;
        for (int i = 0 ; i < nums.size(); i++) {
            if (i - k - 1 >= 0) appeared.erase(nums[i - k - 1]);
            if (appeared.find(nums[i]) != appeared.end()) return true;
            appeared.insert(nums[i]);
        }
        return false;
    }
};