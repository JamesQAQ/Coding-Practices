class Solution {
public:
    int findMin(vector<int>& nums) {
        int pivot = nums[0];
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= pivot) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (l < nums.size()) return nums[l];
        return pivot;
    }
};