class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int ans = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - min_price > ans) {
                ans = prices[i] - min_price;
            }
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
        }
        return ans;
    }
};