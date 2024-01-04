class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int sum = 0;
    int remain = 0;
    while (numBottles + remain >= numExchange) {
      sum += numBottles;
      int total = numBottles + remain;
      numBottles = total / numExchange;
      remain = total % numExchange;
    }
    return sum + numBottles;
  }
};
