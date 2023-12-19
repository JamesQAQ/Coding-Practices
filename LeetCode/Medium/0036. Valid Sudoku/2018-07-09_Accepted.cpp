class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10], col[9][10], box[9][10];
        for (int i = 0; i < 9; i++) {
            for (int j = 1; j <= 9; j++) {
                row[i][j] = col[i][j] = box[i][j] = false;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    if (row[i][val] || col[j][val] || box[boxIndex(i, j)][val]) return false;
                    row[i][val] = col[j][val] = box[boxIndex(i, j)][val] = true;
                }
            }
        }
        return true;
    }
private:
    int boxIndex(int x, int y) {
        int xx = x / 3;
        int yy = y / 3;
        return xx * 3 + yy;
    }
};