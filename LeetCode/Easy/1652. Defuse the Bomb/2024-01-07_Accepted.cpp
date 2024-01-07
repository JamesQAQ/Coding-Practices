class Solution {
public:
  vector<int> decrypt(vector<int>& code, int k) {
    if (k == 0) {
      return vector<int>(code.size(), 0);
    }
    bool reverseResult = k < 0;
    if (reverseResult) {
      k = -k;
      reverse(code.begin(), code.end());
    }
    vector<int> sum = code;
    for (int i = 0; i < k; i++) {
      sum.push_back(sum[i]);
    }
    for (int i = 0; i < sum.size(); i++) {
      sum[i] = sum[i] + (i ? sum[i - 1] : 0);
    }
    vector<int> result;
    for (int i = 0; i < code.size(); i++) {
      result.push_back(sum[i + k] - sum[i]);
    }
    if (reverseResult) {
      reverse(result.begin(), result.end());
    }
    return result;
  }
};
