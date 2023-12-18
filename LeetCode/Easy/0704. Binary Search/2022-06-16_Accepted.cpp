class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lpos = 0, rpos = nums.size() - 1;
        while (lpos <= rpos) {
            int mpos = (lpos + rpos) / 2;
            if (nums[mpos] < target) {
                lpos = mpos + 1;
            } else if (nums[mpos] > target) {
                rpos = mpos - 1;
            } else {
                return mpos;
            }
        }
        return -1;
    }
};