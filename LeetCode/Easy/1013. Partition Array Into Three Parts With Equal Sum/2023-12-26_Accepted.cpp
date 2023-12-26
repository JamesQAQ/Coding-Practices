class Solution {
public:
  bool canThreePartsEqualSum(vector<int>& arr) {
    vector<int> leftSum(arr.size());
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
      sum += arr[i];
      leftSum[i] = sum;
    }

    if (sum % 3 != 0) {
      return false;
    }
    int partitionSum = sum / 3;
    vector<int> possibleI;
    for (int i = 0; i < leftSum.size(); i++) {
      if (leftSum[i] == partitionSum) {
        possibleI.push_back(i);
      }
    }

    int currentSum = 0;
    for (int j = arr.size() - 1; j > 0; j--) {
      currentSum += arr[j];
      if (currentSum == partitionSum) {
        for (auto i : possibleI) {
          if (i >= j - 1) {
            break;
          }
          if (leftSum[j - 1] - leftSum[i] == partitionSum) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
