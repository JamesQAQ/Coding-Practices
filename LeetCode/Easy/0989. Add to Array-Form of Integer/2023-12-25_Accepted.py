class Solution:
  def addToArrayForm(self, num: List[int], k: int) -> List[int]:
    sys.set_int_max_str_digits(10001)
    return [
        int(digit) for digit in str(int(''.join([str(d) for d in num])) + k)]
