class Solution:
  def decompressRLElist(self, nums: List[int]) -> List[int]:
    results = []
    for i in range(0, len(nums), 2):
      results += [nums[i + 1] for unused in range(nums[i])]
    return results
