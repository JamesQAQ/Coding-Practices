class Solution {
public:
  bool checkIfExist(vector<int>& arr) {
    int zeroCount = 0;
    set<int> s;
    for (auto num : arr) {
      s.insert(num);
      if (num == 0) {
        zeroCount++;
      }
    }
    for (auto num : arr) {
      if (num == 0) {
        if (zeroCount > 1) {
          return true;
        }
      } else if (s.find(num * 2) != s.end()) {
        return true;
      }
    }
    return false;
  }
};
