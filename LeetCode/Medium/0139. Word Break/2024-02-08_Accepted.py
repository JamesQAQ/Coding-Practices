class Solution:
  def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    dp = [False for _ in range(len(s) + 1)]
    dp[0] = True
    for i in range(len(s)):
      if dp[i]:
        for l in range(1, min(len(s) - i, 20) + 1):
          seg = s[i : i + l]
          if seg in wordDict:
            dp[i + l] = True
    return dp[len(s)]
