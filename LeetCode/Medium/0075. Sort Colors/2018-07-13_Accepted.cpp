class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lptr = 0, rptr = nums.size() - 1;
        for (int i = 0; i <= rptr; i++) {
            if (i < lptr) continue;
            if (nums[i] == 0) {
                nums[i--] = nums[lptr];
                nums[lptr++] = 0;
            } else if (nums[i] == 2) {
                nums[i--] = nums[rptr];
                nums[rptr--] = 2;
            }
        }
    }
};