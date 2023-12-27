class Solution {
public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    set<int> arr2_set;
    for (auto num : arr2) {
      arr2_set.insert(num);
    }

    map<int, int> count;
    vector<int> not_appear;
    for (auto num : arr1) {
      if (arr2_set.find(num) != arr2_set.end()) {
        if (count.find(num) == count.end()) {
          count[num] = 0;
        }
        count[num]++;
      } else {
        not_appear.push_back(num);
      }
    }

    vector<int> ans;
    for (auto num : arr2) {
      int c = count[num];
      while (c--) {
        ans.push_back(num);
      }
    }
    sort(not_appear.begin(), not_appear.end());
    ans.insert(ans.end(), not_appear.begin(), not_appear.end());
    return ans;
  }
};
