class Solution {
public:
  vector<int> mostVisited(int n, vector<int>& rounds) {
    vector<int> count(n + 1, 0);
    count[rounds[0]]++;
    int maxCount = 1;
    for (int i = 0; i < rounds.size() - 1; i++) {
      int start = rounds[i];
      int end = rounds[i + 1];
      if (end <= start) {
        end += n;
      }
      for (int j = start + 1; j <= end; j++) {
        int pos = j;
        if (pos > n) {
          pos -= n;
        }
        count[pos]++;
        maxCount = max(maxCount, count[pos]);
      }
    }

    vector<int> result;
    for (int i = 1; i <= n; i++) {
      if (count[i] == maxCount) {
        result.push_back(i);
      }
    }
    return result;
  }
};
