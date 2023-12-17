class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 1; j <= 9; j++) {
                row[i][j] = col[i][j] = box[i][j] = false;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    row[i][val] = true;
                    col[j][val] = true;
                    box[idx(i, j)][val] = true;
                }
            }
        }
        dfs(0, 0, board);
    }
private:
    bool row[9][10], col[9][10], box[9][10];
    
    int idx(int x, int y) {
        x = x / 3;
        y = y / 3;
        return x * 3 + y;
    }
    
    bool dfs(int x, int y, vector<vector<char>>& board) {
        if (x == 9) {
            x = 0;
            y++;
        }
        if (y == 9) {
            return true;
        }
        if (board[x][y] != '.') {
            if (dfs(x + 1, y, board)) return true;
        } else {
            for (int i = 1; i <= 9; i++) {
                if (!row[x][i] && !col[y][i] && !box[idx(x, y)][i]) {
                    row[x][i] = col[y][i] = box[idx(x, y)][i] = true;
                    board[x][y] = i + '0';
                    if (dfs(x + 1, y, board)) return true;
                    row[x][i] = col[y][i] = box[idx(x, y)][i] = false;
                }
            }
            board[x][y] = '.';
        }
        return false;
    }
};