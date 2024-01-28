class Solution:
  def kthDistinct(self, arr: List[str], k: int) -> str:
    count = {}
    for s in arr:
      if s not in count:
        count[s] = 0
      count[s] += 1
    idx = 0
    for s in arr:
      if count[s] == 1:
        idx += 1
        if idx == k:
          return s
    return ''
