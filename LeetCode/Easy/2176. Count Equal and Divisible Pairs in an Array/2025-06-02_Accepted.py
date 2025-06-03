class Solution:
  def countPairs(self, nums: List[int], k: int) -> int:
    idx_map = {}
    for i, num in enumerate(nums):
      if num not in idx_map:
        idx_map[num] = []
      idx_map[num].append(i)
    
    ans = 0
    for num in idx_map:
      ans += self.count(idx_map[num], k)
    return ans
  
  def count(self, idxs: List[int], k: int) -> int:
    result = 0
    for i in range(len(idxs)):
      for j in range(i + 1, len(idxs)):
        if (idxs[i] * idxs[j]) % k == 0:
          result += 1
    return result
