class Solution {
public:
  int largestInteger(int num) {
    int origin_num = num;
    vector<int> odd_digits;
    vector<int> even_digits;
    while (num) {
      if ((num % 10) % 2) {
        odd_digits.push_back(num % 10);
      } else {
        even_digits.push_back(num % 10);
      }
      num /= 10;
    }
    sort(odd_digits.begin(), odd_digits.end());
    sort(even_digits.begin(), even_digits.end());

    int odd_idx = 0;
    int even_idx = 0;
    vector<int> result_digits;
    while (origin_num) {
      if ((origin_num % 10) % 2) {
        result_digits.push_back(odd_digits[odd_idx++]);
      } else {
        result_digits.push_back(even_digits[even_idx++]);
      }
      origin_num /= 10;
    }

    int ans = 0;
    reverse(result_digits.begin(), result_digits.end());
    for (auto d : result_digits) {
      ans = ans * 10 + d;
    }
    return ans;
  }
};
