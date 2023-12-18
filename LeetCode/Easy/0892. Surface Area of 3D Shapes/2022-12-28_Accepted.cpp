class Solution {
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    ans += 2;
                    for (int k = 0; k < 4; k++) {
                        int di = i + d[k][0];
                        int dj = j + d[k][1];
                        if (0 <= di && di < n && 0 <= dj && dj < n) {
                            if (grid[di][dj] < grid[i][j]) {
                                ans += grid[i][j] - grid[di][dj];
                            }
                        } else {
                            ans += grid[i][j];
                        }
                    }
                }
            }
        }
        return ans;
    }
};