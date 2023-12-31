class Solution:
  def sortString(self, s: str) -> str:
    count = [0 for _ in range(26)]
    for c in s:
      count[ord(c) - ord('a')] += 1
    used = 0
    result = []
    while used < len(s):

      def process(x: int) -> int:
        if count[x] > 0:
          result.append(chr(ord('a') + x))
          count[x] -= 1
          return 1
        return 0

      for i in range(26):
        used += process(i)
      for i in range(25, -1, -1):
        used += process(i)

    return ''.join(result)
