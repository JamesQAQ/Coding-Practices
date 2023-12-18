// This is NOT for `Follow-up`.

#include <algorithm>
using std::stable_sort;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        stable_sort(nums.begin(), nums.end());
        int a = nums[0], cnt = 1, ans;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == a)
                cnt++;
            else{
                a = nums[i];
                cnt = 1;
            }
            if (cnt > nums.size() / 2)
                ans = a;
        }
        if (cnt > nums.size() / 2)
            ans = a;
        return ans;
    }
};
