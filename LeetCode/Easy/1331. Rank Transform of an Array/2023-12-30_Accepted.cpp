class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    map<int, int> rankMapping;
    int rank = 1;
    for (auto num : sortedArr) {
      if (rankMapping.find(num) == rankMapping.end()) {
        rankMapping[num] = rank++;
      }
    }
    for (int i = 0; i < arr.size(); i++) {
      arr[i] = rankMapping[arr[i]];
    }
    return arr;
  }
};
