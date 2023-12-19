class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        
        // try to find the minimum position first
        int offset = minimunPosition(nums);
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = nums[(mid + offset) % nums.size()];
            if (val > target) {
                r = mid - 1;
            } else if (val < target) {
                l = mid + 1;
            } else {
                return (mid + offset) % nums.size();
            }
        }
        return -1;
    }
private:
    int minimunPosition(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[0]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};