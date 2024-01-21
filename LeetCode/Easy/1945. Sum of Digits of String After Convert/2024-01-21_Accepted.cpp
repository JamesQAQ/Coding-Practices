class Solution {
public:
  int getLucky(string s, int k) {
    int result = 0;
    for (auto c : s) {
      int num = c - 'a' + 1;
      result += count(num);
    }
    while (--k) {
      result = count(result);
    }
    return result;
  }

private:
  int count(int x) {
    int sum = 0;
    while (x >= 10) {
      sum += x % 10;
      x /= 10;
    }
    return sum + x;
  }
};
