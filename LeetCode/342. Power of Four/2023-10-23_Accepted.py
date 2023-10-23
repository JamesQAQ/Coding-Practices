class Solution:
  def isPowerOfFour(self, n: int) -> bool:
    if n <= 0:
      return False
    power = math.log2(n) / 2
    return power % 1 == 0
