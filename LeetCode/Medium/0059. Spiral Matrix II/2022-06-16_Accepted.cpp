class Solution {
    int offset[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        vector<int> emptyRow(n, 0);
        for (int i = 0; i < n; i++) {
            res.push_back(emptyRow);
        }
        
        int x = 0, y = 0, dir = 0;
        for (int i = 1; i <= n * n; i++) {
            res[x][y] = i;
            int nx = x + offset[dir][0];
            int ny = y + offset[dir][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || res[nx][ny] != 0) {
                dir = (dir + 1) % 4;
                nx = x + offset[dir][0];
                ny = y + offset[dir][1];
            }
            x = nx;
            y = ny;
        }
        return res;
    }
};
