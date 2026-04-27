class Solution:
  def largestGoodInteger(self, num: str) -> str:
    for i in range(9, -1, -1):
      three_same_digit_number = str(i) * 3
      if three_same_digit_number in num:
        return three_same_digit_number
    return ''
