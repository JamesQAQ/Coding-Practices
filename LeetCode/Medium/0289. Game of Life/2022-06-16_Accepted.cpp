class Solution {
    int offset[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> preBoard = board;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int cnt = count(preBoard, i, j);
                if (preBoard[i][j] == 0) {
                    if (cnt == 3) {
                        board[i][j] = 1;
                    }
                } else if (cnt < 2 || cnt > 3) {
                    board[i][j] = 0;
                }
            }
        }
    }

private:
    int count(vector<vector<int>>& board, int _x, int _y) {
        int sum = 0;
        for (int i = 0; i < 8; i++) {
            int x = _x + offset[i][0];
            int y = _y + offset[i][1];
            if (!(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())) {
                sum += board[x][y];
            }
        }
        return sum;
    }
};