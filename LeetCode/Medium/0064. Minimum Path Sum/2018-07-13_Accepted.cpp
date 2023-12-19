class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            dp.push_back(tmp);
            for (int j = 0; j < m; j++) {
                dp[i].push_back(2147483647);
            }
        }
        dp[0][0] = grid[0][0];
        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
    }
private:
    int min(int a, int b) {
        return (a < b) ? a : b;
    }
};