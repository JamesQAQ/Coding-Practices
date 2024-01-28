class Solution {
public:
  vector<int> twoOutOfThree(
      vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    vector<int> appeared = vector<int>(101, 0);
    process(appeared, nums1, 1);
    process(appeared, nums2, 2);
    process(appeared, nums3, 4);

    vector<int> result;
    for (int i = 1; i <= 100; i++) {
      if (appeared[i] == 3 || appeared[i] >= 5) {
        result.push_back(i);
      }
    }
    return result;
  }

private:
  void process(vector<int>& appeared, vector<int>& nums, int val) {
    for (auto num : nums) {
      appeared[num] |= val;
    }
  }
};
