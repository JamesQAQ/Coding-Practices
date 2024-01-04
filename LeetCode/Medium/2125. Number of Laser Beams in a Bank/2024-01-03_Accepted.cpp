class Solution {
public:
  int numberOfBeams(vector<string>& bank) {
    int ans = 0;
    int pre = 0;
    for (auto row : bank) {
      int deviceNum = count(row);
      ans += pre * deviceNum;
      if (deviceNum != 0) {
        pre = deviceNum;
      }
    }
    return ans;
  }

private:
  int count(string s) {
    int sum = 0;
    for (auto c : s) {
      sum += (c == '1');
    }
    return sum;
  }
};
