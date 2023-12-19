#include <unordered_map>
#include <algorithm>

using std::pair;
using std::unordered_map;
using std::stable_sort;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        stable_sort(nums.begin(), nums.end());

        unordered_map<long long, vector<pair<int, int>>> um;
        long long u1 = nums[0] - 1;
        bool repeat = false;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == u1) {
                if (!repeat) {
                    if (nums[i] == nums[i + 1]) {
                        um[nums[i] + nums[i + 1]].push_back({i, i + 1});
                        // printf("%d %d\n", i, i + 1);
                        repeat = true;
                    }
                }
                continue;
            }
            u1 = nums[i];
            repeat = false;
            long long u2 = nums[0] - 1;
            for (int j = nums.size() - 1; j >= i + 1; j--) {
                if (nums[j] == u2) continue;
                u2 = nums[j];
                um[nums[i] + nums[j]].push_back({i, j});
                if (nums[i] == nums[j]) {
                    repeat = true;
                }
            }
        }

        u1 = nums[0] - 1;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (nums[i] == u1) continue;
            u1 = nums[i];
            long long u2 = nums[0] - 1;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (nums[j] == u2) continue;
                u2 = nums[j];
                auto it = um.find(target - u1 - u2);
                // printf("nums[%d] = %d, nums[%d] = %d\n", i, nums[i], j, nums[j]);
                if (it == um.end()) {
                    // printf("continue\n");
                    continue;
                }
                for (auto p : it->second) {
                    // printf("%d %d\n", p.first, p.second);
                    if (p.first > j) {
                        ans.push_back({nums[i], nums[j], nums[p.first], nums[p.second]});
                    }
                }
            }
        }

        return ans;
    }
};