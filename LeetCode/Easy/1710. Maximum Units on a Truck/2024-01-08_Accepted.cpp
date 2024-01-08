class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), cmp);
    int ans = 0;
    for (auto boxType : boxTypes) {
      int usedSize = min(truckSize, boxType[0]);
      ans += boxType[1] * usedSize;
      truckSize -= usedSize;
      if (truckSize == 0) {
        break;
      }
    }
    return ans;
  }

private:
  static bool cmp(vector<int>& i, vector<int>& j) {
    return i[1] > j[1];
  }
};
