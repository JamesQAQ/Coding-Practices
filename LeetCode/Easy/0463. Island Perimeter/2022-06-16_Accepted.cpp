class Solution {
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (x < 0 || x >= n || y < 0 || y >= m) ans++;
                        else if (grid[x][y] == 0) ans++;
                    }
                }
            }
        }
        return ans;
    }
};