class Solution:
  def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
    cb = [[] for _ in range(len(s) + 1)]
    cb[0] = [[]]
    for i in range(len(s)):
      if cb[i] != None:
        for l in range(1, min(len(s) - i, 10) + 1):
          seg = s[i : i + l]
          if seg in wordDict:
            for c in cb[i]:
              cb[i + l].append(c.copy() + [seg])
    return [' '.join(c) for c in cb[len(s)]]
