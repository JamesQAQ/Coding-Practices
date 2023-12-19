class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cpos = -1;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                cpos = i - 1;
                break;
            }
        }
        if (cpos != -1) {
            for (int i = nums.size() - 1; i > cpos; i--) {
                if (nums[i] > nums[cpos]) {
                    swap(nums[i], nums[cpos]);
                    break;
                }
            }
        }
        int len = nums.size() - cpos - 1;
        for (int i = 0; i < len / 2; i++) {
            swap(nums[cpos + 1 + i], nums[nums.size() - i - 1]);
        }
    }
};