class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0, n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] == 0){
                while (pos < n && (pos < i || nums[pos] == 0))
                    pos++;
                if (pos == n)
                    break;
                swap(nums[i], nums[pos]);
            }
        }
    }
};
