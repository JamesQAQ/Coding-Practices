class Solution:
  def cellsInRange(self, s: str) -> List[str]:
    result = []
    for col_val in range(ord(s[0]), ord(s[3]) + 1):
      col = chr(col_val)
      for row in range(int(s[1]), int(s[4]) + 1):
        result.append(col + str(row))
    return result
        