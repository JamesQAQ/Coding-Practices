class Solution:
  def reformatNumber(self, number: str) -> str:
    number = number.replace(' ', '').replace('-', '')
    parts = []
    while len(number) > 4:
      parts.append(number[:3])
      number = number[3:]
    if len(number) == 4:
      parts.append(number[:2])
      parts.append(number[2:])
    else:
      parts.append(number)
    return '-'.join(parts)
