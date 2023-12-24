class Solution {
public:
  vector<int> sortArrayByParityII(vector<int>& nums) {
    int odd_ptr = 1;
    int even_ptr = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i % 2 == 0 && nums[i] % 2 != 0) {
        swap(nums[odd_ptr], nums[i--]);
        odd_ptr += 2;
      } else if (i % 2 != 0 && nums[i] % 2 == 0) {
        swap(nums[even_ptr], nums[i--]);
        even_ptr += 2;
      }
    }
    return nums;
  }
};
