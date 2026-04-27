class Solution:
  def divisorSubstrings(self, num: int, k: int) -> int:
    ans = 0
    num_str = str(num)
    for i in range(0, len(num_str) - k + 1):
      divisor = int(num_str[i : i + k])
      if divisor != 0 and num % divisor == 0:
        ans += 1
    return ans
