class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    set<int> set1;
    set<int> set2;
    process(nums1, set1);
    process(nums2, set2);

    vector<vector<int>> result(2);
    getResult(result[0], nums1, set2);
    getResult(result[1], nums2, set1);
    return result;
  }

private:
  void process(vector<int>& nums, set<int>& _set) {
    for (auto num : nums) {
      _set.insert(num);
    }
  }

  void getResult(vector<int>& result, vector<int>& nums, set<int>& _set) {
    set<int> matched;
    for (auto num : nums) {
      if (_set.find(num) == _set.end()) {
        matched.insert(num);
      }
    }
    for (auto it : matched) {
      result.push_back(it);
    }
  }
};
