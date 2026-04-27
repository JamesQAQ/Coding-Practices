class Solution:
  def digitSum(self, s: str, k: int) -> str:
    while len(s) > k:
      s = ''.join(
          str(sum(int(d) for d in g))
          for g in [s[i : i + k] for i in range(0, len(s), k)]
      )
    return s
