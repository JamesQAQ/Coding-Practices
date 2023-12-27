class Solution:
  def removeDuplicates(self, s: str) -> str:
    result = []
    for character in s:
      if result and result[-1] == character:
        result.pop()
      else:
        result.append(character)
    return ''.join(result)
