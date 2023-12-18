class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    ans++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int maxHeight = 0;
            for (int j = 0; j < n; j++) {
                maxHeight = max(grid[i][j], maxHeight);
            }
            ans += maxHeight;
        }

        for (int i = 0; i < n; i++) {
            int maxHeight = 0;
            for (int j = 0; j < n; j++) {
                maxHeight = max(grid[j][i], maxHeight);
            }
            ans += maxHeight;
        }

        return ans;
    }
};