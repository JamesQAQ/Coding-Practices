class Solution {
public:
  bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3) {
      return false;
    }
    bool increasing = true;
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i - 1] == arr[i]) {
        return false;
      }
      if (increasing) {
        if (arr[i - 1] > arr[i]) {
          if (i == 1) {
            return false;
          }
          increasing = false;
        }
      } else if (arr[i - 1] < arr[i]) {
        return false;
      }
    }
    return !increasing;
  }
};
