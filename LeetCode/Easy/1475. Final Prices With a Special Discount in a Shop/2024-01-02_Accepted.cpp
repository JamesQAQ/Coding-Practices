class Solution {
public:
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> result;
    for (int i = 0; i < prices.size(); i++) {
      result.push_back(prices[i] - discount(prices, i));
    }
    return result;
  }

private:
  int discount(vector<int>& prices, int i) {
    for (int j = i + 1; j < prices.size(); j++) {
      if (prices[j] <= prices[i]) {
        return prices[j];
      }
    }
    return 0;
  }
};
