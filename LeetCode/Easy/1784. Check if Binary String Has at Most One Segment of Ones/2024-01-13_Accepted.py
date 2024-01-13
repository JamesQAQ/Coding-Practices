class Solution:
  def checkOnesSegment(self, s: str) -> bool:
    segments = s.split('0')
    return len(segments) - segments.count('') == 1
