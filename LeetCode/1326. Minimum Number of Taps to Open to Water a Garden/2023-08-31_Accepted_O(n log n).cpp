class Solution {
public:
  int minTaps(int n, vector<int>& ranges) {
    vector<pair<int, int>> processed_ranges;
    for (int i = 0; i < n + 1; i++) {
      if (ranges[i] > 0) {
        processed_ranges.push_back({i - ranges[i], i + ranges[i]});
      }
    }
    sort(
        processed_ranges.begin(),
        processed_ranges.end(),
        compareProcessedRange);

    int ans = 0;
    int last_covered = 0;
    int index = 0;
    while (last_covered < n) {
      int largest_right_bound = -1;
      while (index < processed_ranges.size()
             && processed_ranges[index].first <= last_covered) {
        largest_right_bound = max(
            largest_right_bound, processed_ranges[index++].second);
      }
      
      if (largest_right_bound == -1) {
        return -1;
      } else {
        last_covered = largest_right_bound;
        ans++;
      }
    }
    return ans;
  }

private:
  static bool compareProcessedRange(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
  }
};
