#include <algorithm>
using std::stable_sort;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.size() < 3) return ans;

        stable_sort(nums.begin(), nums.end());
        int u1 = nums[0] - 1;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (u1 == nums[i]) continue;
            u1 = nums[i];
            int u2 = nums[0] - 1;
            int ptr = nums.size() - 1;
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (u2 == nums[j]) continue;
                u2 = nums[j];
                if (-(u1 + u2) < nums[j + 1]) break;
                while (ptr > j && nums[ptr] > -(u1 + u2)) ptr--;
                if (ptr <= j) break;
                if (-(u1 + u2) == nums[ptr]) {
                    vector<int> tuple;
                    tuple.push_back(u1);
                    tuple.push_back(u2);
                    tuple.push_back(-(u1 + u2));
                    ans.push_back(tuple);
                }
            }
        }
        return ans;
    }
};