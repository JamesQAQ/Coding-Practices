class Solution {
public:
  string tictactoe(vector<vector<int>>& moves) {
    vector<vector<int>> t(3, {-1, -1, -1});
    int cur = 0;
    for (auto move : moves) {
      t[move[0]][move[1]] = cur;
      cur = 1 - cur;
    }
    if (wins(t, 0)) {
      return "A";
    } else if (wins(t, 1)) {
      return "B";
    }
    return moves.size() == 9 ? "Draw" : "Pending";
  }

private:
  bool wins(vector<vector<int>>& t, int x) {
    for (int i = 0; i < 3; i++) {
      if (t[i][0] == x && t[i][1] == x && t[i][2] == x) {
        return true;
      }
      if (t[0][i] == x && t[1][i] == x && t[2][i] == x) {
        return true;
      }
    }
    if (t[0][0] == x && t[1][1] == x && t[2][2] == x) {
      return true;
    }
    if (t[2][0] == x && t[1][1] == x && t[0][2] == x) {
      return true;
    }
    return false;
  }
};
