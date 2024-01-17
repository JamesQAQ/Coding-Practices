class Solution {
public:
  int maximumPopulation(vector<vector<int>>& logs) {
    vector<int> population(101, 0);
    pair<int, int> ans = {-1, -1};
    for (auto log : logs) {
      population[log[0] - 1950]++;
      population[log[1] - 1950]--;
    }
    int sum = 0;
    for (int i = 0; i <= 100; i++) {
      sum += population[i];
      if (sum > ans.second) {
        ans = {i, sum};
      }
    }
    return ans.first + 1950;
  }
};
