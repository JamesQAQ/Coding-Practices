struct Placeholder {
  int x;
  int y;

  void operator+=(const Placeholder& other) {
    this->x += other.x;
    this->y += other.y;
  }
};

class Solution {
public:
  int numRookCaptures(vector<vector<char>>& board) {
    int ans = 0;
    Placeholder rook = findRook(board);
    Placeholder offset[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
      Placeholder cur = rook;
      cur += offset[i];
      while (inBoard(cur)) {
        if (board[cur.x][cur.y] != '.') {
          if (board[cur.x][cur.y] == 'p') {
            ans++;
          }
          break;
        }
        cur += offset[i];
      }
    }
    return ans;
  }

private:
  Placeholder findRook(vector<vector<char>>& board) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (board[i][j] == 'R') {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }

  bool inBoard(Placeholder pos) {
    return 0 <= pos.x && pos.x < 8 && 0 <= pos.y && pos.y < 8;
  }
};
