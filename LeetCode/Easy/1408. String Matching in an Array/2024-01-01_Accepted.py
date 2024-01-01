class Solution:
  def stringMatching(self, words: List[str]) -> List[str]:
    result = []
    for w in words:
      for word in words:
        if w != word and w in word:
          result.append(w)
          break
    return result
