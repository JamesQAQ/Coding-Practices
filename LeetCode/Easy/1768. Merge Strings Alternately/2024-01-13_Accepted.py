class Solution:
  def mergeAlternately(self, word1: str, word2: str) -> str:
    result = []
    for i in range(min(len(word1), len(word2))):
      result.append(word1[i])
      result.append(word2[i])
    if len(word1) > len(word2):
      word1, word2 = word2, word1
    for i in range(len(word1), len(word2)):
      result.append(word2[i])
    return ''.join(result)
