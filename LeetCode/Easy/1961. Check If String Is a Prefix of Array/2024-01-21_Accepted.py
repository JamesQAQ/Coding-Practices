class Solution:
  def isPrefixString(self, s: str, words: List[str]) -> bool:
    length = 0
    for i in range(0, len(words)):
      length += len(words[i])
      if length > len(s):
        return False
      elif length == len(s):
        return ''.join(words[:i + 1]) == s
    return False
