class Solution:
  def sortEvenOdd(self, nums: List[int]) -> List[int]:
    odd_idxs = [i for i in range(0, len(nums), 2)]
    odd_idxs.sort(key = lambda x : nums[x])
    even_idxs = [i for i in range(1, len(nums), 2)]
    even_idxs.sort(key = lambda x : nums[x], reverse=True)
    result = []
    for i in range(0, len(nums)):
      result.append(nums[odd_idxs[i // 2] if i % 2 == 0 else even_idxs[i // 2]])
    return result
