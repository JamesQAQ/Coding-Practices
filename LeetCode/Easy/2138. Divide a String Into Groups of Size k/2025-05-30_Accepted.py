class Solution:
  def divideString(self, s: str, k: int, fill: str) -> List[str]:
    result = []
    processed_s = s + fill * k
    for i in range((len(s) - 1) // k + 1):
      result.append(processed_s[i * k : (i + 1) * k])
    return result
