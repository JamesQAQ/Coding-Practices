struct Placeholder {
  int x;
  int y;

  Placeholder operator+(const Placeholder& other) {
    Placeholder res = *this;
    res.x += other.x;
    res.y += other.y;
    return res;
  }
};

class Solution {
private:
  Placeholder offsets[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
  vector<vector<int>> allCellsDistOrder(
      int rows, int cols, int rCenter, int cCenter) {
    vector<vector<bool>> visited(rows);
    for (int i = 0; i < rows; i++) {
      visited[i] = vector<bool>(cols, false);
    }

    vector<vector<int>> result;
    queue<Placeholder> q;
    q.push({rCenter, cCenter});
    visited[rCenter][cCenter] = true;
    while (!q.empty()) {
      Placeholder cur = q.front();
      q.pop();
      result.push_back({cur.x, cur.y});
      for (auto offset : offsets) {
        Placeholder next = cur + offset;
        if (0 <= next.x && next.x < rows && 0 <= next.y && next.y < cols) {
          if (!visited[next.x][next.y]) {
            q.push({next.x, next.y});
            visited[next.x][next.y] = true;
          }
        }
      }
    }
    return result;
  }
};
