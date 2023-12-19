class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int tmp, ans = 0;
        bool down = true;
        for (int i = 0; i < prices.size() - 1; i++){
            if (down){
                if (prices[i] < prices[i + 1]){
                    tmp = prices[i];
                    down = false;
                }
            }
            else{
                if (prices[i] > prices[i + 1]){
                    ans += prices[i] - tmp;
                    down = true;
                }
            }
        }
        if (down){
            if (prices[prices.size() - 1] > prices[prices.size() - 2])
                ans += prices[prices.size() - 1] - prices[prices.size() - 2];
        }
        else{
            ans += prices[prices.size() - 1] - tmp;
        }
        return ans;
    }
};
