class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            dp.push_back(tmp);
            for (int j = 0; j < m; j++) {
                dp[i].push_back(0);
            }
        }
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (int j = 1; j < m; j++) {
            if (obstacleGrid[0][j] != 0) break;
            dp[0][j] = dp[0][j - 1];
        }
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[i][0] != 0) break;
            dp[i][0] = dp[i - 1][0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};