class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    arr.push_back(1001);
    int cur = arr[0];
    int count = 1;
    set<int> appearedCount;
    for (int i = 1; i < arr.size(); i++) {
      if (cur != arr[i]) {
        if (appearedCount.find(count) != appearedCount.end()) {
          return false;
        }
        appearedCount.insert(count);
        cur = arr[i];
        count = 0;
      }
      count++;
    }
    return true;
  }
};
