class Solution {
public:
  int minTaps(int n, vector<int>& ranges) {
    vector<int> max_covered(n + 1, -1);
    for (int i = 0; i < n + 1; i++) {
      if (ranges[i] > 0) {
        int left = max(0, i - ranges[i]);
        max_covered[left] = max(max_covered[left], min(n, i + ranges[i]));
      }
    }

    int ans = 0;
    int last_covered = 0;
    int index = 0;
    while (last_covered < n) {
      int largest_right_bound = -1;
      while (index <= last_covered) {
        largest_right_bound = max(largest_right_bound, max_covered[index++]);
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
};
