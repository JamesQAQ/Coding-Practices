class Solution {
public:
  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> edge = vector<vector<int>>(n);
    vector<bool> visited = vector<bool>(n, false);
    for (auto e : edges) {
      edge[e[0]].push_back(e[1]);
      edge[e[1]].push_back(e[0]);
    }
    queue<int> q;
    visited[source] = true;
    q.push(source);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      if (cur == destination) {
        return true;
      }
      for (auto next : edge[cur]) {
        if (!visited[next]) {
          visited[next] = true;
          q.push(next);
        }
      }
    }
    return false;
  }
};
