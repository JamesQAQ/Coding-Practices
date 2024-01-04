class Solution:
  def thousandSeparator(self, n: int) -> str:
    if n == 0:
      return '0'
    parts = []
    while n > 0:
      remain = n % 1000
      part = f'{remain:03d}' if n // 1000 > 0 else str(remain)
      parts.append(part)
      n = n // 1000
    parts.reverse()
    return '.'.join(parts)
