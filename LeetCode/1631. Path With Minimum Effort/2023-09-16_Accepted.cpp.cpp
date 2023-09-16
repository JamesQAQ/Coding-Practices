struct Node {
  int x;
  int y;
  int dp;

  bool operator>(const Node& other) const {
    return dp > other.dp;
  }
};

class Solution {
private:
  int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<bool>> visited;
    vector<vector<int>> dp;
    for (int i = 0; i < n; i++) {
      visited.push_back(vector<bool>(m, false));
      dp.push_back(vector<int>(m, INT_MAX));
    }

    priority_queue<Node, vector<Node>, greater<Node>> queue;
    dp[0][0] = 0;
    queue.push({0, 0, dp[0][0]});
    while (!queue.empty()) {
      Node i = queue.top();
      queue.pop();
      if (visited[i.x][i.y] || dp[i.x][i.y] < i.dp) {
        continue;
      }
      visited[i.x][i.y] = true;
      for (int k = 0; k < 4; k++) {
        int next_x = i.x + dir[k][0];
        int next_y = i.y + dir[k][1];
        if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m) {
          if (!visited[next_x][next_y]) {
            int max_gap = max(
                dp[i.x][i.y], abs(heights[i.x][i.y] - heights[next_x][next_y]));
            if (max_gap < dp[next_x][next_y]) {
              dp[next_x][next_y] = max_gap;
              queue.push({next_x, next_y, max_gap});
            }
          }
        }
      }
    }

    return dp[n - 1][m - 1];
  }
};
