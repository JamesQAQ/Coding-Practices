class Solution {
public:
  double average(vector<int>& salary) {
    int minSalary = salary[0];
    int maxSalary = salary[0];
    int sum = 0;
    for (auto s : salary) {
      minSalary = min(minSalary, s);
      maxSalary = max(maxSalary, s);
      sum += s;
    }
    return ((double)sum - minSalary - maxSalary) / (salary.size() - 2);
  }
};
