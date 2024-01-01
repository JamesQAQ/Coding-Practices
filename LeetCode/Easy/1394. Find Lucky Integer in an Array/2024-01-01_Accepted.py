class Solution:
  def findLucky(self, arr: List[int]) -> int:
    count = {}
    for num in arr:
      if num not in count:
        count[num] = 0
      count[num] += 1
    ans = -1
    for num in count:
      if num == count[num]:
        ans = max(ans, num)
    return ans
