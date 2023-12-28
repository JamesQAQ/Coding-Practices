class Solution {
private:
  int MOD = 1000000007;
  vector<int> prime = {
      2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
      53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
  };

public:
  int numPrimeArrangements(int n) {
    auto it = upper_bound(prime.begin(), prime.end(), n);
    int primeCount = distance(prime.begin(), it);
    return ((long long)factorial(primeCount) * factorial(n - primeCount)) % MOD;
  }

private:
  int factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
      result = (result * i) % MOD;
    }
    return result;
  }
};
