class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> leftBound;
        map<int, int> rightBound;
        map<int, int> cnt;
        int maxCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            rightBound[nums[i]] = i;
            if (cnt.find(nums[i]) == cnt.end()) {
                cnt[nums[i]] = 0;
            }
            cnt[nums[i]]++;
            maxCnt = max(maxCnt, cnt[nums[i]]);
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            leftBound[nums[i]] = i;
        }
        int ans = nums.size();
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            if (it->second == maxCnt) {
                ans = min(ans, rightBound[it->first] - leftBound[it->first] + 1);
            }
        }
        return ans;
    }
};