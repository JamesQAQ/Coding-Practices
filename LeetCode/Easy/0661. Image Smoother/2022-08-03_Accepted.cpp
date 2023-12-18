class Solution {
    int d[9][2] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0;
                int cnt = 0;
                for (int k = 0; k < 9; k++) {
                    int x = i + d[k][0];
                    int y = j + d[k][1];
                    if (0 <= x && x < n && 0 <= y && y < m) {
                        sum += img[x][y];
                        cnt++;
                    }
                }
                ans[i].push_back(sum / cnt);
            }
        }
        return ans;
    }
};