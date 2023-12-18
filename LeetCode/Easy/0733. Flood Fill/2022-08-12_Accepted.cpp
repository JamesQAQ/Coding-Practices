class Solution {
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int sourceColor = image[sr][sc];
        if (sourceColor != color) dfs(image, sr, sc, sourceColor, color);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int x, int y, int sourceColor, int color) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != sourceColor) return;
        image[x][y] = color;
        for (int i = 0; i < 4; i++) {
            dfs(image, x + d[i][0], y + d[i][1], sourceColor, color);
        }
    }
};