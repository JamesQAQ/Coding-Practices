class Solution:
  def hasGroupsSizeX(self, deck: List[int]) -> bool:
    count = {}
    for card in deck:
      if card not in count:
        count[card] = 0
      count[card] += 1

    first_count = count[next(iter(count))]
    x = 1
    while x * x <= first_count:
      if first_count % x == 0:
        if self._verify(x, count) or self._verify(first_count // x, count):
          return True
      x += 1
    return False

  def _verify(self, x: int, count: Dict[int, int]):
    if x <= 1:
      return False
    for _, value in count.items():
      if value % x != 0:
        return False
    return True
