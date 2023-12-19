int _move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Pos{
    int x, y;
    Pos(int _x, int _y){
        x = _x;
        y = _y;
    }
} ;

void bfs(vector<vector<char>>& board, int x, int y) {
    queue <Pos> que;
    board[x][y] = 'V';
    que.push(Pos(x, y));
    while (!que.empty()){
        Pos now = que.front();
        que.pop();
        for (int i = 0; i < 4; i++){
            int xx = now.x + _move[i][0], yy = now.y + _move[i][1];
            if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size() && board[xx][yy] == 'O'){
                board[xx][yy] = 'V';
                que.push(Pos(xx, yy));
            }
        }
    }
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++){
                if ((i == 0 || i == board.size() - 1) && board[i][j] == 'O')
                    bfs(board, i, j);
                if ((j == 0 || j == board[0].size() - 1) && board[i][j] == 'O')
                    bfs(board, i, j);
            }
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == 'V')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
    }
};
