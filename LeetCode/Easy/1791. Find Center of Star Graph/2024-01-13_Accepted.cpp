class Solution {
public:
  int findCenter(vector<vector<int>>& edges) {
    edges[0].insert(edges[0].end(), edges[1].begin(), edges[1].end());
    sort(edges[0].begin(), edges[0].end());
    for (int i = 0; i < 3; i++) {
      if (edges[0][i] == edges[0][i + 1]) {
        return edges[0][i];
      }
    }
    return -1;
  }
};
