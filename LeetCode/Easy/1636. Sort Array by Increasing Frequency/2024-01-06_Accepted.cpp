struct Placeholder {
  int x;
  map<int, int>* count;

  bool operator<(const Placeholder& other) {
    if ((*count)[x] == (*count)[other.x]) {
      return x > other.x;
    }
    return (*count)[x] < (*count)[other.x];
  }
};

class Solution {
public:
  vector<int> frequencySort(vector<int>& nums) {
  map<int, int> count;
    vector<Placeholder> placeholders;
    for (auto num : nums) {
      if (count.find(num) == count.end()) {
        count[num] = 0;
      }
      count[num]++;
      placeholders.push_back({num, &count});
    }
    sort(placeholders.begin(), placeholders.end());
    nums.clear();
    for (auto placeholder : placeholders) {
      nums.push_back(placeholder.x);
    }
    return nums;
  }
};
