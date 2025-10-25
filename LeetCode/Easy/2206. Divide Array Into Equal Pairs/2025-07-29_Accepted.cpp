class Solution {
public:
  bool divideArray(vector<int>& nums) {
    map<int, bool> pairMap;
    for (auto num : nums) {
      if (pairMap.find(num) == pairMap.end()) {
        pairMap[num] = false;
      }
      pairMap[num] = !pairMap[num];
    }

    for (auto it : pairMap) {
      if (it.second) {
        return false;
      }
    }
    return true;
  }
};
