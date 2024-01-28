class Solution:
  def areNumbersAscending(self, s: str) -> bool:
    pre = 0
    for part in s.split(' '):
      if part.isdigit():
        num = int(part)
        if num <= pre:
          return False
        pre = num
    return True
