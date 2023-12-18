class Solution {
public:
    int findLHS(vector<int>& nums) {
        stable_sort(nums.begin(), nums.end());
        vector<pair<int, int>> processed;
        for (int i = 0; i < nums.size(); i++) {
            if (processed.size() == 0 || nums[i] != processed[processed.size() - 1].first) {
                processed.push_back(make_pair(nums[i], 0));
            }
            processed[processed.size() - 1].second++;
        }
        int ans = 0;
        for (int i = 1; i < processed.size(); i++) {
            if (processed[i].first - processed[i - 1].first == 1) {
                ans = max(ans, processed[i].second + processed[i - 1].second);
            }
        }
        return ans;
    }
};