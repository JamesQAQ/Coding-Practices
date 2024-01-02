class Solution:
  def reformat(self, s: str) -> str:
    alphas = []
    digits = []
    for c in s:
      if c.islower():
        alphas.append(c)
      else:
        digits.append(c)
    if abs(len(alphas) - len(digits)) > 1:
      return ''
    if len(digits) > len(alphas):
      return self._construct([digits, alphas])
    return self._construct([alphas, digits])

  def _construct(self, c: List[List[str]]) -> str:
    result = []
    for i in range(len(c[0]) + len(c[1])):
      result.append(c[i % 2][i // 2])
    return ''.join(result)
