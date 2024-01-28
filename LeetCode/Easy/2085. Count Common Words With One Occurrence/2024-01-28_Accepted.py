class Solution:
  def countWords(self, words1: List[str], words2: List[str]) -> int:
    count = {}
    for word in words1:
      if word not in count:
        count[word] = 1
      else:
        count[word] = 1001
    for word in words2:
      if word in count:
        count[word] -= 1
    ans = 0
    for word in count:
      if count[word] == 0:
        ans += 1
    return ans
