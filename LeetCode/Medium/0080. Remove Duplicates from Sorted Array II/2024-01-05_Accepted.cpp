class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int cur = -10001;
    int count;
    int ptr = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (cur != nums[i]) {
        cur = nums[i];
        count = 0;
      }
      count++;
      if (count <= 2) {
        nums[ptr++] = nums[i];
      }
    }
    return ptr;
  }
};
