class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix[0].size(); i++) {
            if (!verify(0, i, matrix)) return false;
        }
        for (int i = 1; i < matrix.size(); i++) {
            if (!verify(i, 0, matrix)) return false;
        }
        return true;
    }

private:
    bool verify(int x, int y, vector<vector<int>>& matrix) {
        int v = matrix[x][y];
        while (x < matrix.size() && y < matrix[0].size()) {
            if (matrix[x++][y++] != v) return false;
        }
        return true;
    }
};