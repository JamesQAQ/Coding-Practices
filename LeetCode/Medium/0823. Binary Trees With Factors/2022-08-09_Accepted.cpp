class Solution {
    int MOD = 1000000007;
    
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<long long> dp(arr.size(), 1);
        int ans = 0;
        map<int, int> idx;
        for (int i = 0; i < arr.size(); i++) {
            idx[arr[i]] = i;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0 && idx.find(arr[i] / arr[j]) != idx.end()) {
                    dp[i] = (dp[i] + dp[j] * dp[idx[arr[i] / arr[j]]]) % MOD; 
                }
            }
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};