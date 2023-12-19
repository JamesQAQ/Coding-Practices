class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    int move[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    bool dfs(int x, int y, int pos, vector<vector<char>>& board, string& word) {
        if (pos == word.length()) {
            return true;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return false;
        }
        if (board[x][y] != word[pos]) {
            return false;
        }
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            if (dfs(x + move[i][0], y + move[i][1], pos + 1, board, word)) {
                return true;
            }
        }
        board[x][y] = word[pos];
        return false;
    }
};