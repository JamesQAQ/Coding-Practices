class Solution:
  def removeOuterParentheses(self, s: str) -> str:
    count = 0
    results = []
    for i in range(len(s)):
      if s[i] == '(':
        if count != 0:
          results.append('(')
        count += 1
      elif s[i] == ')':
        if count != 1:
          results.append(')')
        count -= 1
    return ''.join(results)
