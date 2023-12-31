class Solution {
public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), cmp);
    return arr;
  }

private:
  static bool cmp(int i, int j) {
    int bitI = countBit(i);
    int bitJ = countBit(j);
    if (bitI != bitJ) {
      return bitI < bitJ;
    }
    return i < j;
  }

  static int countBit(int x) {
    int ans = 0;
    while (x) {
      x -= (x & -x);
      ans++;
    }
    return ans;
  }
};
