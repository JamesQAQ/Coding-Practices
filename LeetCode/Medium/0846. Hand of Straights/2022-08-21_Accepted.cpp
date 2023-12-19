class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;

        unordered_map<int, int> cnt;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (cnt.find(nums[i]) == cnt.end()) {
                cnt[nums[i]] = 0;
            }
            cnt[nums[i]]++;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (cnt[nums[i]] > 0) {
                for (int j = 0; j < k; j++) {
                    if (cnt.find(nums[i] + j) == cnt.end() || cnt[nums[i] + j] <= 0) return false;
                    cnt[nums[i] + j]--;
                }
            }
        }
        
        return true;
    }
};
