class Solution:
  def finalValueAfterOperations(self, operations: List[str]) -> int:
    x = 0
    for operation in operations:
      x = x + 1 if '+' in operation else x - 1
    return x
