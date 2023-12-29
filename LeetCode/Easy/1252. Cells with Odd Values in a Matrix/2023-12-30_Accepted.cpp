class Solution {
public:
  int oddCells(int m, int n, vector<vector<int>>& indices) {
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    for (auto indice : indices) {
      row[indice[0]]++;
      col[indice[1]]++;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        ans += (row[i] + col[j]) % 2;
      }
    }
    return ans;
  }
};
