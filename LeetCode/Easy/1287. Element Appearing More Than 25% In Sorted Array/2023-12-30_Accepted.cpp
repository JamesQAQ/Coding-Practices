class Solution {
public:
  int findSpecialInteger(vector<int>& arr) {
    map<int, int> count;
    int target = arr.size() / 4 + 1;
    for (auto num : arr) {
      if (count.find(num) == count.end()) {
        count[num] = 0;
      }
      count[num]++;
      if (count[num] == target) {
        return num;
      }
    }
    return -1;
  }
};
