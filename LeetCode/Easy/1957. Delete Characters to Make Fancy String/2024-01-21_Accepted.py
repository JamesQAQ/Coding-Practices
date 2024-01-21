class Solution:
  def makeFancyString(self, s: str) -> str:
    result = []
    pre = ''
    count = 0
    for c in s:
      if c != pre:
        pre = c
        count = 0
      count += 1
      if count <= 2:
        result.append(c)
    return ''.join(result)
