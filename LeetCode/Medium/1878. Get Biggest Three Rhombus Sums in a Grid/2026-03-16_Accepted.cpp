class Solution {
public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    priority_queue<int, vector<int>, greater<int>> biggestSums;
    set<int> appearedSums;
  
    for (int i = 0; i * 2 - 1 < (int)grid.size(); i++) {
      for (int j = 0; j + 2 * i < grid.size(); j++) {
        for (int k = i; k + i < grid[0].size(); k++) {
          int sum = getRhombusSum(grid, i, j, k);
          if (appearedSums.find(sum) != appearedSums.end()) {
            continue;
          }
          appearedSums.insert(sum);

          if (biggestSums.size() < 3) {
            biggestSums.push(sum);
          } else if (sum > biggestSums.top()) {
            biggestSums.pop();
            biggestSums.push(sum);
          }
        }
      }
    }

    vector<int> result;
    while (!biggestSums.empty()) {
      result.push_back(biggestSums.top());
      biggestSums.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }

private:
  int move[4][2] = {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}};

  int getRhombusSum(vector<vector<int>>& grid, int len, int x, int y) {
    if (len == 0) {
      return grid[x][y];
    }

    int sum = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < len; j++) {
        sum += grid[x][y];
        x += move[i][0];
        y += move[i][1];
      }
    }
    return sum;
  }
};
